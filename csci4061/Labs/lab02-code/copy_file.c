#include <stdio.h>

#define BUF_SIZE 4096

/*
 * Copy the contents of one file into another file
 *   source_file: Name of the source file to copy from
 *   dest_file: Name of the destination file to copy to
 * The destination file is overwritten if it already exists
 * Returns 0 on success and -1 on error
 */
int copy_file(const char *source_file, const char *dest_file)
{
    FILE *input, *output;
    input = fopen(source_file, "r");
    output = fopen(dest_file, "w");
    fseek(input, 0L, SEEK_END);
    int filesize = ftell(input);
    rewind(input);
    char buff[BUF_SIZE];

    if (input == NULL || output == NULL)
    {
        printf("one or both files can't be opened \n");
        return 0;
    }
    while (!feof(input))
    {
        fread(buff, sizeof(char), filesize, input);
    }
    fwrite(buff, sizeof(char), filesize, output);
    
    int infile = fclose(input);
    int outfile = fclose(output);

    if (infile == 1)
    {
        printf("error closing source file");
    }
    if (outfile == 1)
    {
        printf("error closing destination file");
    }
    
    

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <source> <dest>\n", argv[0]);
        return 1;
    }

    // copy_file already prints out any errors
    if (copy_file(argv[1], argv[2]) != 0)
    {
        return 1;
    }
    return 0;
}
