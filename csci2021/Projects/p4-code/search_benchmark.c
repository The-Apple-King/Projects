#include "search.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Complete this main to benchmark the search algorithms outlined in
// the project specification

typedef void *(*create_t)(int);
typedef void (*search_t)(const void *, int, int);
typedef void (*free_t)(void *);

typedef struct
{
  create_t create;
  search_t search;
  free_t freeData;
} datatype;

void test(int size, int repititions, datatype funcs)
{
  clock_t begin, end;
  void *arr = funcs.create(size);
  begin = clock();
  for (int i = 0; i < repititions; i++)
  {
    for (int searchVal = 0; searchVal < (4 << (size + 1)) - 1; searchVal++)
    {
      funcs.search(arr, size, searchVal);
    }
    funcs.freeData(arr);
  }

  end = clock();
  printf("\t%ld", (end-begin));
}

int main(int argc, char *argv[])
{

  datatype algs[4] = {
      {.create = (create_t)make_evens_array, .search = (search_t)linear_array_search, .freeData = (free_t)free},   // linear search
      {.create = (create_t)make_evens_list, .search = (search_t)linkedlist_search, .freeData = (free_t)list_free}, // linked list
      {.create = (create_t)make_evens_array, .search = (search_t)binary_array_search, .freeData = (free_t)free},   // binary search
      {.create = (create_t)make_evens_tree, .search = (search_t)binary_tree_search, .freeData = (free_t)bst_free}, // binary tree
  };

 printf("    SIZE  NSEARCH");

int stuff[4] = {0,0,0,0};
  if (argc > 4)
  {
    for (int i = 3; i < argc; i++)
    {

      if (strcmp(argv[i], "la") == 0) // lin arr
      {
        stuff[0] = 1;
        printf("\tarray");
      }

      if (strcmp(argv[i], "ll") == 0) // lin arr
      {
        stuff[1] = 1;
        printf("\tlist");
      }

      if (strcmp(argv[i], "bl") == 0) // lin arr
      {
        stuff[2] = 1;
        printf("\tbinary");
      }

      if (strcmp(argv[i], "bt") == 0) // lin arr
      {
        stuff[3] = 1;
        printf("\ttree");
      }
    }
    printf("\n");
  }
  else
  {
    stuff[0] = 1;
    stuff[1] = 1;
    stuff[2] = 1;
    stuff[3] = 1;
    printf("\tarray\tlist\tbinary\ttree\n");
  }

  // now call funcs to test
  for (int i = atoi(argv[1]); i < atoi(argv[2]); i++)
  {
    printf("%d\t%d", (1<<atoi(argv[1])), atoi(argv[1]) * atoi(argv[3]));
    if (stuff[0])
    {
      test(i, atoi(argv[3]), algs[0]);
    }
    if (stuff[1])
    {
      test(i, atoi(argv[3]), algs[1]);
    }
    if (stuff[2])
    {
      test(i, atoi(argv[3]), algs[2]);
    }
    if (stuff[3])
    {
      test(i, atoi(argv[3]), algs[3]);
    }
    printf("\n");
  }
  return 0;
}
