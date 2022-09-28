#include "treemap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// PROVIDED: Makes use of functions provided in banlet_funcs.c to
// print messages in a "fontified" fashion. This program should not
// require modification.

int main()
{
    treemap_t tree;
    treemap_init(&tree);
    char arg[128];
    char key[64];
    char val[64];
    printf("TreeMap Editor\n");
    printf("Commands:\n");
    printf("  quit:            exit the program\n");
    printf("  print:           shows contents of the tree in reverse sorted order\n");
    printf("  add <key> <val>: inserts the given key/val into the tree, duplicate keys are ignored\n");
    printf("  get <key>:       prints FOUND if the name is in the tree, NOT FOUND otherwise\n");
    printf("  clear:           eliminates all key/vals from the tree\n");
    printf("  size:            prints the total number of nodes in the tree\n");
    printf("  preorder:        prints contents of the tree in pre-order which is how it will be saved\n");
    printf("  save <file>:     writes the contents of the tree in pre-order to the given file\n");
    printf("  load <file>:     clears the current tree and loads the one in the given file\n");
    while (1)
    {
        printf("TM> ");

        if(scanf("%s", arg) == EOF){
            treemap_clear(&tree);
            break;
        }

        if (strcmp(arg, "quit") == 0) 
        {
            printf("%s", arg);
            treemap_clear(&tree);
            break;
        }
        else if (strcmp(arg, "print") == 0) 
        {
            printf("%s\n", arg);
            treemap_print_revorder(&tree);
        }
        else if (strcmp(arg, "add") == 0) 
        {
            scanf("%s", key);
            scanf("%s", val);
            printf("%s %s %s\n",arg, key, val);
            treemap_add(&tree, key, val);
        }
        else if (strcmp(arg, "get") == 0) 
        {
            scanf("%s", key);
            printf("%s %s\n", arg, key);
            if(treemap_get(&tree, key) ==NULL){
                printf("NOT FOUND\n");
            }
            else{
                printf("FOUND: %s\n", treemap_get(&tree, key));
            }
        }
        else if (strcmp(arg, "clear") == 0) 
        {
            printf("%s\n", arg);
            treemap_clear(&tree);
        }
        else if (strcmp(arg, "size") == 0) 
        {
            printf("%s\n", arg);
            printf("%d nodes\n", treemap_size(&tree));
        }
        else if (strcmp(arg, "preorder") == 0) 
        {
            printf("%s\n", arg);
            treemap_print_preorder(&tree);
        }
        else if (strcmp(arg, "save") == 0) 
        {
            scanf("%s", arg);
            printf("save %s\n", arg);
            treemap_save(&tree, arg);
        }
        else if (strcmp(arg, "load") == 0) 
        {
            scanf("%s", arg);
            printf("load %s\n", arg);
            if(treemap_load(&tree, arg) == 0){
                printf("load failed\n");
            }
        }
        else
        {
            // TODO: Remove this
            printf("please enter a valid response");
        }
    }
}