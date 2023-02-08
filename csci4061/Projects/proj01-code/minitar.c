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
int remove_trailing_bytes(const char *file_name, size_t nbytes)
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
 * @brief returns the size of a file
 *
 * @param filename a pointer to the file location
 * @return int size of the file
 */
int sizeOfFile(FILE *filename)
{
    int size = 0;
    fseek(filename, 0, SEEK_END);
    size = ftell(filename);
    fseek(filename, 0, SEEK_SET);
    return size;
}

/**
 * takes a string of characters in octal and returns their value in base 10
 * will not check if string is octal assumed it is.
 */
int string_to_octal(char *num)
{
    int result = 0;
    while (*num)
    {
        result <<= 3;                  // multiply by 8 each time to get base 8
        result += (int)(*num++ - '0'); // takes the char and turns it to an int and adds it to result
    }
    return result;
}

int endblock(const char *archive_name)
{
    // open target file
    FILE *tar = fopen(archive_name, "r+");
    if (tar == NULL)
    {
        perror("tar file in create archive broke");
        return -1;
    }
    fseek(tar, 0, SEEK_END);
    // loop for 2 blocks and write a '0' each time
    for (size_t i = 0; i < 1024; i++)
    {
        fprintf(tar, "%c", '0');
    }
    return 0;
}

/**
 * @brief creates header and puts blocks of 512 bytes into file archive_name
 * then if necessary puts a not full block of 512 bytes filled with trailing zeroes
 *
 * @param archive_name name of file to save to
 * @param file the name of the file to save from
 */
void archiveSingleFile(const char *archive_name, const char *file)
{
    FILE *tar = fopen(archive_name, "r+");
    if (tar == NULL)
    {
        perror("tar error in archive single string");
    }
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL)
    {
        perror("ptr error in archive single string");
    }

    // set tar to end of file
    fseek(tar, 0, SEEK_END);
    char buf[512];

    // create header
    tar_header header;
    if (fill_tar_header(&header, file) == -1)
    {
        perror("fill_tar_header in archiveSingleFile");
    }

    // start writing to file
    // write header
    fwrite(&header, sizeof(header), 1, tar);

    int count = sizeOfFile(ptr) / 512;

    // write full blocks
    for (size_t i = 0; i < count; i++)
    {
        fread(buf, 512, 1, ptr);
        fwrite(buf, 512, 1, tar);
    }

    // clean up not full block************************************************************

    // check if we need to add trailing zeroes
    if (count % 512 != 0)
    {
        // save byte by byte until EOF then save 0s
        for (size_t i = 0; i < count % 512; i++)
        {
            // if not at end of file save one byte at a time
            if (fread(buf, 1, 1, ptr) != -1)
            {
                fwrite(buf, 1, 1, tar);
            }
        }
        for (size_t i = 0; i < 512 - count % 512; i++)
        {
            // if at end of file print 0s until filled block
            fprintf(tar, "%c", '0');
        }
    }

    // close files we opened
    fclose(ptr);
    fclose(tar);
}

int create_archive(const char *archive_name, const file_list_t *files)
{
    // empty file so no conflicts
    FILE *tar = fopen(archive_name, "w"); // opening file with w should clear contents
    fclose(tar);                          // closing file saves changes so we can just call archiveSingleFile

    // go file by file adding it to the archive
    node_t *curNode = files->head;
    for (size_t i = 0; i < files->size; i++)
    {
        archiveSingleFile(archive_name, curNode->name);
        curNode = curNode->next;
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
 * @return int
 */
int append_files_to_archive(const char *archive_name, const file_list_t *files)
{
    // remove double 0 block
    remove_trailing_bytes(archive_name, 1024);

    // loop through files, and add them to the archive
    node_t *curnode = files->head;
    for (size_t i = 0; i < files->size; i++)
    {
        archiveSingleFile(archive_name, curnode->name);
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
int get_archive_file_list(const char *archive_name, file_list_t *files)
{

    FILE *tar = fopen(archive_name, "r");
    int size = 0;   // size of the file archive
    char sizes[8];  // temporary location to store the size in string form
    char name[255]; // name of file

    int count = sizeOfFile(tar) - 1024;     // count = the number of actual blocks of code
    for (size_t i = 0; i < count; i += 512) // i+=512 will cover for the header files we seek through
    {
        fread(name, 100, 1, tar);          // read in name,no reference to prefix so unless necessary leave as is
        fseek(tar, 24, SEEK_CUR);          // seek till file size
        fread(sizes, sizeof(int), 1, tar); // take in size
        size = string_to_octal(sizes);
        fseek(tar, 376, SEEK_CUR); // seek till end of header

        // find the number of blocks until next header
        int blocks = size / 512;
        if (size % 512 > 0)
        {
            blocks++;
        }

        // adds file to file list
        file_list_add(files, name);

        // seek till next header
        fseek(tar, blocks * 512, SEEK_CUR);

        // update i by the number of blocks we just searched through
        i += (blocks * 512);
    }

    return 0;
}

int extract_files_from_archive(const char *archive_name)
{
    FILE *tar = fopen(archive_name, "r");   // file to read
    int size = 0;                           // size of file in archive
    char sizes[8];                          // size of file as a char array
    char name[255];                         // name of file
    char codeBlock[512];                    // buffer of codeblock
    int j = 0;
    // loop until pointer reaches end of code
    while (fseek(tar, 0, SEEK_CUR) < sizeOfFile(tar) - 1024)
    {

        fread(name, 100, 1, tar);          // read in name,no reference to prefix so unless necessary leave as is
        fseek(tar, 24, SEEK_CUR);          // seek till file size
        fread(sizes, sizeof(int), 1, tar); // take in size

        size = string_to_octal(sizes);

        fseek(tar, 376, SEEK_CUR); // seek till end of header

        FILE *ptr = fopen(name, "w");
        for (j = 0; j < size / 512; j++) // read full codeblocks and write them to file name;
        {
            fread(codeBlock, 512, 1, tar);
            fwrite(codeBlock, 512, 1, ptr);
        }
        if (j * 512 < size)
        {
            fread(codeBlock, (size - (j * 512)), 1, tar);  // read in remaining codeBlock
            fseek(tar, (j * 512 - size), SEEK_CUR);        // seek to end of 0 block
            fwrite(codeBlock, (size - (j * 512)), 1, ptr); // write codeBlock to file
        }
        fclose(ptr); // close file
    }

    return 0;
}
