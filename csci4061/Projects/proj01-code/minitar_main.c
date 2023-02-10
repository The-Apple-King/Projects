#include <stdio.h>
#include <string.h>
#include "file_list.h"
#include "minitar.h"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Usage: %s -c|a|t|u|x -f ARCHIVE [FILE...]\n", argv[0]);
        return 0;
    }
    file_list_t files;
    file_list_init(&files);

    // TODO: Parse command-line arguments and invoke functions from 'minitar.h'
    // to execute archive operations

    // adds all files to the file list
    for (size_t i = 4; i < argc; i++)
    {
        file_list_add(&files, argv[i]);
    }

    if (strcmp(argv[1], "-c") == 0) // create
    {
        create_archive(argv[3], &files);
    }

    else if (strcmp(argv[1], "-a") == 0) // add
    {
        append_files_to_archive(argv[3], &files);
    }

    else if (strcmp(argv[1], "-t") == 0) // list
    {
        get_archive_file_list(argv[3], &files); // populate files
        node_t *curnode = files.head;           // set curnode to the first file
        for (size_t i = 0; i < files.size; i++) // loop through every file
        {
            printf("%s\n", curnode->name); // print file name and then newline
            curnode = curnode->next;       // set curnode to next node in the chain
        }
    }

    else if (strcmp(argv[1], "-u") == 0) // update
    {
        // create a file_list_t containing all files already in archive
        file_list_t present;
        file_list_init(&present);
        get_archive_file_list(argv[3], &present);

        //if all files to append are in present we can update them
        if (file_list_is_subset(&files, &present))
        {
            append_files_to_archive(argv[3], &files);
        }
        // else we output an error
        else
        {
            printf("Error: One or more of the specified files is not already present in archive");
            file_list_clear(&files);
            file_list_clear(&present);
            return -1;
        }
        file_list_clear(&present);
    }

    else if (strcmp(argv[1], "-x") == 0) // extract
    {
        extract_files_from_archive(argv[3]);
    }

    file_list_clear(&files);
    return 0;
}
