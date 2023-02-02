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
    fseek(filename, 0, SEEK_END);
    return ftell(filename);
}

/**
 * @brief creates header and puts blocks of 512 bytes into file archive_name 
 * then if necessary puts a not full block of 512 bytes filled with trailing zeroes
 * 
 * @param archive_name name of file to save to
 * @param file the name of the file to save from
 */
int archiveSingleFile(const char *archive_name, const char *file){
    FILE *tar = fopen(archive_name, O_WRONLY);
    FILE *ptr = fopen(file, O_RDONLY)

    //set tar to end of file
    tar = seek(tar, 0, SEEK_END);

    //create header
    tar_header *header;
    fill_tar_header(header, file);

    //start writing to file
    //write header
    fwrite(header, sizeof(header), 1, tar);

    //write full blocks
    for (size_t i = 0; i < sizeOfFile(ptr)/512; i++)
    {
        char* buf[512];
        fread(buf,512, 1, ptr);
        fwrite(buf,512, 1, tar);
    }

    //clean up not full block
    for (size_t i = 0; i < 512; i++)
    {
        //if not at end of file save one byte at a time
        if (fread(buf, 1, 1, ptr) != EOF)
        {
            fwrite(buf, 1, 1, tar);
        }
        //if at end of file print 0s until filled block
        else {
            fprintf(tar, 0);
        }
    }

    //create var with size of file
    int endOfFile = sizeOfFile(tar);

    //close files we opened 
    fclose(ptr);
    fclose(tar);
    
    //returns size of the target file so we know where to put 2 blocks of zeroes in create_archive
    return endOfFile;
    
}

int create_archive(const char *archive_name, const file_list_t *files)
{
    // TODO
    node_t curNode = files->head;

    for (size_t i = 0; i < files->size; i++)
    {
        archiveSingleFile(archive_name, curNode.name);
        //if archive_name doesn't have its pointer updated you might need to maually set it
        //change the name to the next file
        curNode = curNode.next;
    }

    //end file with 2 0 blocks

    //open target file
    FILE *tar = fopen(archive_name, O_RDWR) 

    //loop for 2 blocks and write a '0' each time
    for (size_t i = 0; i < 1024; i++)
    {
        fprintf(tar, '0');
    }
    

    return 0;
}

int append_files_to_archive(const char *archive_name, const file_list_t *files)
{
    //remove double 0 block
    remove_trailing_bytes(archive_name, 1024);

    //create_archive will take file list and call add single file on it until end
    //then it adds trailing zeroes for us
    create_archive(archive_name, files);

    return 0;
}

int get_archive_file_list(const char *archive_name, file_list_t *files)
{
    // TODO: Not yet implemented
    
    return 0;
}

int extract_files_from_archive(const char *archive_name)
{
    // TODO: Not yet implemented
    return 0;
}