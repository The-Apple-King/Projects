#include <stdio.h>
#include <string.h>

#include "file_list.h"
#include "minitar.h"

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s -c|a|t|u|x -f ARCHIVE [FILE...]\n", argv[0]);
        return 0;
    }

    file_list_t files;
    file_list_init(&files);

    // TODO: Parse command-line arguments and invoke functions from 'minitar.h'
    // to execute archive operations
    file_list_t files;
    file_list_init(&files);
    for (size_t i = 3; i < argc; i++)
    {
        file_list_add(&files, argv[i]);
    }
    
    char* flags = argv[1];
    char flag =argv[1][1];
    switch (flag)
    {
    case 'c': //create
        create_archive(argv[2], &files);
        break;
    
    case 'a': // add
        append_files_to_archive(argv[2], &files);
        break;

    case 't': //list
        get_archive_file_list(argv[2],&files);
        break;

    case 'u': // update
        
        break;
    
    case 'x': // extract
        break;
    
    default:
        break;
    }
    

    file_list_clear(&files);
    return 0;
}
