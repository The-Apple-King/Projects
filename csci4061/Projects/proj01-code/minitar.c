#include <fcntl.h>
#include <grp.h>
#include <math.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>

#include "minitar.h"

#define NUM_TRAILING_BLOCKS 2
#define MAX_MSG_LEN 512
#define BLOCK_SIZE 512

/*
 * Helper function to compute the checksum of a tar header block
 * Performs a simple sum over all bytes in the header in accordance with POSIX
 * standard for tar file structure.
 */
void compute_checksum(tar_header *header)
{
    // Have to initially set header's checksum to "all blanks"
    memset(header->chksum, ' ', 8);
    unsigned sum = 0;
    char *bytes = (char *)header;
    for (int i = 0; i < sizeof(tar_header); i++)
    {
        sum += bytes[i];
    }
    snprintf(header->chksum, 8, "%07o", sum);
}

/*
 * Populates a tar header block pointed to by 'header' with metadata about
 * the file identified by 'file_name'.
 * Returns 0 on success or -1 if an error occurs
 */
int fill_tar_header(tar_header *header, const char *file_name)
{
    memset(header, 0, sizeof(tar_header));
    char err_msg[MAX_MSG_LEN];
    struct stat stat_buf;
    // stat is a system call to inspect file metadata
    if (stat(file_name, &stat_buf) != 0)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to stat file %s", file_name);
        perror(err_msg);
        return -1;
    }

    strncpy(header->name, file_name, 100);                       // Name of the file, null-terminated string
    snprintf(header->mode, 8, "%07o", stat_buf.st_mode & 07777); // Permissions for file, 0-padded octal

    snprintf(header->uid, 8, "%07o", stat_buf.st_uid); // Owner ID of the file, 0-padded octal
    struct passwd *pwd = getpwuid(stat_buf.st_uid);    // Look up name corresponding to owner ID
    if (pwd == NULL)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to look up owner name of file %s", file_name);
        perror(err_msg);
        return -1;
    }
    strncpy(header->uname, pwd->pw_name, 32); // Owner  name of the file, null-terminated string

    snprintf(header->gid, 8, "%07o", stat_buf.st_gid); // Group ID of the file, 0-padded octal
    struct group *grp = getgrgid(stat_buf.st_gid);     // Look up name corresponding to group ID
    if (grp == NULL)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to look up group name of file %s", file_name);
        perror(err_msg);
        return -1;
    }
    strncpy(header->gname, grp->gr_name, 32); // Group name of the file, null-terminated string

    snprintf(header->size, 12, "%011o", (unsigned)stat_buf.st_size);   // File size, 0-padded octal
    snprintf(header->mtime, 12, "%011o", (unsigned)stat_buf.st_mtime); // Modification time, 0-padded octal
    header->typeflag = REGTYPE;                                        // File type, always regular file in this project
    strncpy(header->magic, MAGIC, 6);                                  // Special, standardized sequence of bytes
    memcpy(header->version, "00", 2);                                  // A bit weird, sidesteps null termination
    snprintf(header->devmajor, 8, "%07o", major(stat_buf.st_dev));     // Major device number, 0-padded octal
    snprintf(header->devminor, 8, "%07o", minor(stat_buf.st_dev));     // Minor device number, 0-padded octal

    compute_checksum(header);
    return 0;
}

/*
 * Removes 'nbytes' bytes from the file identified by 'file_name'
 * Returns 0 upon success, -1 upon error
 * Note: This function uses lower-level I/O syscalls (not stdio), which we'll learn about later
 */
int remove_trailing_bytes(const char *file_name, int nbytes)
{
    char err_msg[MAX_MSG_LEN];
    // Note: ftruncate does not work with O_APPEND
    int fd = open(file_name, O_WRONLY);
    if (fd == -1)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to open file %s", file_name);
        perror(err_msg);
        return -1;
    }
    //  Seek to end of file - nbytes
    off_t current_pos = lseek(fd, -1 * nbytes, SEEK_END);
    if (current_pos == -1)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to seek in file %s", file_name);
        perror(err_msg);
        close(fd);
        return -1;
    }
    // Remove all contents of file past current position
    if (ftruncate(fd, current_pos) == -1)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to truncate file %s", file_name);
        perror(err_msg);
        close(fd);
        return -1;
    }
    if (close(fd) == -1)
    {
        snprintf(err_msg, MAX_MSG_LEN, "Failed to close file %s", file_name);
        perror(err_msg);
        return -1;
    }
    return 0;
}

/**
 * @brief returns the size of a file and sets pointer to beginning of file
 *
 * @param filename a pointer to the file location
 * @return int size of the file
 */
int sizeOfFile(FILE *filename)
{
    int size = 0;
    fseek(filename, 0, SEEK_END); // set pointer to end of file
    size = ftell(filename);       // save size of file
    fseek(filename, 0, SEEK_SET); // set pointer to start of file
    return size;
}

/**
 * @brief create two blocks of 0's at the end of a file
 *
 * @param archive_name the archive fill to append 0's onto
 * @return int return 0 if it works -1 if it fails
 */
int endblock(const char *archive_name)
{
    // open target file
    FILE *tar = fopen(archive_name, "r+");
    if (tar == NULL)
    {
        perror("tar file in create archive broke");
        return -1;
    }
    // go to end of file
    fseek(tar, 0, SEEK_END);
    // loop for 2 blocks and write a 0 each time
    for (int i = 0; i < 1024; i++)
    {
        fprintf(tar, "%c", 0x00);
    }
    fclose(tar);
    return 0;
}

/**
 * @brief creates header and puts blocks of 512 bytes into file archive_name
 * then if necessary puts a not full block of 512 bytes filled with trailing zeroes
 *
 * @param archive_name name of file to save to
 * @param file the name of the file to save from
 */
int archiveSingleFile(const char *archive_name, const char *file)
{
    // open both files and error out if theres a problem
    FILE *tar = fopen(archive_name, "r+");
    if (tar == NULL)
    {
        perror("tar error in archive single string");
        return -1;
    }
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL)
    {
        perror("ptr error in archive single string");
        return -1;
    }

    // set tar to end of file
    fseek(tar, 0, SEEK_END);
    char buf[BLOCK_SIZE];

    // create header
    tar_header header;
    if (fill_tar_header(&header, file) == -1)
    {
        perror("fill_tar_header in archiveSingleFile");
        return -1;
    }

    // start writing to file
    // write header
    fwrite(&header, sizeof(header), 1, tar);

    int fileSize = sizeOfFile(ptr);
    int blocks = floor(fileSize / BLOCK_SIZE);

    // write full blocks
    for (int i = 0; i < blocks; i++)
    {
        fread(buf, BLOCK_SIZE, 1, ptr);
        fwrite(buf, BLOCK_SIZE, 1, tar);
    }

    // clean up not full block************************************************************
    memset(buf, 0, BLOCK_SIZE);
    if (fileSize != blocks * BLOCK_SIZE)
    {
        // if blocks*512 doesnt equal filesize save the extra bytes to file
        fread(buf, 1, fileSize - (blocks * BLOCK_SIZE), ptr);
        fwrite(buf, BLOCK_SIZE, 1, tar);
    }

    // close files we opened
    fclose(ptr);
    fclose(tar);
    return 0;
}

int create_archive(const char *archive_name, const file_list_t *files)
{
    // empty file so no conflicts
    FILE *tar = fopen(archive_name, "w"); // opening file with w should clear contents
    if (tar == NULL)
    {
        perror("tar error in create archive to empty file");
        return -1;
    }
    fclose(tar); // closing file saves changes so we can just call archiveSingleFile

    // go file by file adding it to the archive
    node_t *curNode = files->head;
    for (int i = 0; i < files->size; i++)
    {
        if(archiveSingleFile(archive_name, curNode->name) == 0){
        curNode = curNode->next;
        }else{
            perror("file not found");
            return -1;
        }
    }

    // end file with 2 0 blocks
    endblock(archive_name);

    return 0;
}

/**
 * @brief Append files to an archive
 *
 * @param archive_name archive to append files to
 * @param files files to append to the archive
 * @return int 0 if success -1 if fail
 */
int append_files_to_archive(const char *archive_name, const file_list_t *files)
{

    // remove double 0 block
    remove_trailing_bytes(archive_name, 1024);

    // loop through files, and add them to the archive
    node_t *curnode = files->head;
    for (int i = 0; i < files->size; i++)
    {
        if(archiveSingleFile(archive_name, curnode->name)==0){
        curnode = curnode->next;
        }else{
            perror("file not found");
            return -1;
        }
    }

    // end file with 2 blocks of 0s
    endblock(archive_name);

    return 0;
}

/**
 * @brief Get the list of files from the tar archive
 *
 * will clear anything in file list and replace it with what is in tar
 * currently assumes that names are shorter than 101 chars
 *
 * @param archive_name archive to get files from
 * @param files list to add files to
 * @return int
 */
int get_archive_file_list(const char *archive_name, file_list_t *files) // error to fix here
{
    // open archive file
    FILE *tar = fopen(archive_name, "r");
    if (tar == NULL)
    {
        perror("tar error in get archive file list");
        return -1;
    }

    int size = 0;         // size of the file archive
    char nameEnd[100];    // name of file
    char namePrefix[155]; // name of prefx
    char fullName[255];   // full name compounded

    // find file size and make sure its big enough
    int count = sizeOfFile(tar) - 1024; // count = the number of actual blocks of code
    if (count < 1024)
    {
        perror("File sent in was too short");
        return -1;
    }

    // loop through the file
    for (int i = 0; i < count;) // i+=512 will cover for the header files we seek through
    {
        fread(nameEnd, 100, 1, tar);    // read in name,no reference to prefix so unless necessary leave as is
        fseek(tar, 24, SEEK_CUR);       // seek till file size
        fscanf(tar, "%o", &size);       // read in octal and put into size
        fseek(tar, 209, SEEK_CUR);      // move pointer to start of name prefix
        fread(namePrefix, 155, 1, tar); // read in namePrefix
        fseek(tar, 12, SEEK_CUR);       // seek till end of header

        // find the number of blocks until next header
        int blocks = size / BLOCK_SIZE;
        if (size % BLOCK_SIZE > 0)
        {
            blocks++;
        }

        // creates a full name from prefix and name
        strcpy(fullName, namePrefix); // copies namePrefix to fullName
        strcat(fullName, nameEnd);    // appends nameEnd to fullName

        // adds file to file list
        file_list_add(files, fullName);

        // seek till next header
        fseek(tar, (blocks * BLOCK_SIZE) + 1, SEEK_CUR);

        // update i by the number of blocks we just searched through
        i += ((1 + blocks) * BLOCK_SIZE); // +1 for header, blocks for file contents, 512 for block size
    }

    return 0;
}

int extract_files_from_archive(const char *archive_name)
{
    // open archive file
    FILE *tar = fopen(archive_name, "r");
    if (tar == NULL)
    {
        perror("tar error in extract files from archive");
        return -1;
    }

    int size = 0;         // size of the file archive
    char nameEnd[100];    // name of file
    char namePrefix[155]; // name of prefx
    char fullName[255];   // full name compounded
    char buf[BLOCK_SIZE]; // buffer to hold file data

    // find file size and make sure its big enough
    int count = sizeOfFile(tar) - 1024; // count = the number of actual blocks of code
    if (count < 1024)
    {
        perror("File sent in was too short");
        return -1;
    }

    // loop through the file
    for (int i = 0; i < count;) // i+=512 will cover for the header files we seek through
    {
        fread(nameEnd, 100, 1, tar);    // read in name,no reference to prefix so unless necessary leave as is
        fseek(tar, 24, SEEK_CUR);       // seek till file size
        fscanf(tar, "%o", &size);       // read in octal and put into size
        fseek(tar, 209, SEEK_CUR);      // move pointer to start of name prefix
        fread(namePrefix, 155, 1, tar); // read in namePrefix
        fseek(tar, 13, SEEK_CUR);       // seek till end of header

        // find the number of blocks until next header
        int blocks = size / BLOCK_SIZE;

        // creates a full name from prefix and name
        strcpy(fullName, namePrefix); // copies namePrefix to fullName
        strcat(fullName, nameEnd);    // appends nameEnd to fullName

        // create the file to write to
        FILE *ptr = fopen(fullName, "w");
        if (ptr == NULL)
        {
            perror("ptr error in extract files from archive");
            return -1;
        }

        // write full blocks
        for (int j = 0; j < blocks; j++)
        {
            fread(buf, BLOCK_SIZE, 1, tar);
            fwrite(buf, BLOCK_SIZE, 1, ptr);
        }

        // clean up not full block************************************************************
        memset(buf, 0, BLOCK_SIZE);
        if (size != blocks * BLOCK_SIZE)
        {
            // if blocks*512 doesnt equal filesize save the extra bytes to file
            fread(buf, 1, size - (blocks * BLOCK_SIZE), tar);
            fwrite(buf, size - (blocks * BLOCK_SIZE), 1, ptr);
            fseek(tar, (BLOCK_SIZE - (size - (blocks * BLOCK_SIZE))), SEEK_CUR);
        }
        fclose(ptr);

        // update i by the number of blocks we just searched through
        i += ((2 + blocks) * BLOCK_SIZE); // +1 for header, blocks for file contents, 512 for block size
    }

    return 0;
}
