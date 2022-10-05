#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//throw code in here for debugging
int main()
{
    FILE* ptr = fopen("pp.txt", "w");
    fwrite("help", sizeof(char),1,ptr);
}
