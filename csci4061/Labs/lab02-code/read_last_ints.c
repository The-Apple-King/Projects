#include <stdio.h>
#include <stdlib.h>

/*
 * Read the last integers from a binary file
 *   'num_ints': The number of integers to read
 *   'file_name': The name of the file to read from
 * Returns 0 on success and -1 on error
 */
int read_last_ints(const char *file_name, int num_ints) {
    FILE *input;
    input = fopen(file_name, "r");
    fseek(input, (-num_ints*sizeof(int)), SEEK_END);
    int *nums = malloc(sizeof(int)*num_ints);

    if (input == NULL)
    {
        printf("one or both files can't be opened \n");
        return 0;
    }
    fread(nums, sizeof(int), num_ints, input);
    
    for (size_t i = 0; i < num_ints; i++)
    {
        printf("%d\n", nums[i]);
    }
    

    int infile = fclose(input);

    if (infile ==1)
    {
        printf("error closing source file");
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <num_ints>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];
    int num_ints = atoi(argv[2]);
    if (read_last_ints(file_name, num_ints) != 0) {
        printf("Failed to read last %d ints from file %s\n", num_ints, file_name);
        return 1;
    }
    return 0;
}
