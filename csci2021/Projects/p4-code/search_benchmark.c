#include "search.h"
#include <time.h>
#include "string"
// Complete this main to benchmark the search algorithms outlined in
// the project specification

/**
 * @brief creates a linear array of pow size, searches for relevant vals and returns string containing time
 *
 *
 * @param pow the length of the arr
 * @return char* the updated string to output
 */
char *linArr(int pow, int loops, char *output)
{
  clock_t begin, end;
  int arr = make_evens_array(pow);
  begin = clock();
  for (int i = 0; i < loops; i++)
  {
    for (int searchVal = 0; searchVal < (4 << (pow + 1)) - 1; searchVal++)
    {
      linear_array_search(arr, pow, searchVal);
    }
    free(arr);
  }

  end = clock();

  strcat(output, " " + (end - begin));
  return output;
}

/**
 * @brief creates a binary array of pow size, searches for relevant vals and returns string containing time
 *
 *
 * @param pow the length of the arr
 * @param loops the number of repetitions used
 * @return char* the updated string to output
 */
char *binArr(int pow, int loops, char *output)
{
  clock_t begin, end;
  int arr = make_evens_array(pow);
  begin = clock();
  for (int i = 0; i < loops; i++)
  {
    for (int searchVal = 0; searchVal < (4 << (pow + 1)) - 1; searchVal++)
    {
      binary_array_search(arr, pow, searchVal);
    }
    free(arr);
  }

  end = clock();

  strcat(output, " " + (end - begin));
  return output;
}

/**
 * @brief create linked list of length pow, searches for relevent vals, runs loops times, updates output 
 * 
 * @param pow number of evens
 * @param loops number of times values are searched
 * @param output string to update
 * @return char* the output string
 */
char* linkList(int pow, int loops, char *output){
  clock_t begin, end;
  list_t* list = make_evens_list(pow);
  begin = clock();
  for (int i = 0; i < loops; i++)
  {
    for (int searchVal = 0; searchVal < (4 << (pow + 1)) - 1; searchVal++)
    {
      linkedlist_search(list, pow, searchVal);
    }
    list_free(list);
  }

  end = clock();

  strcat(output, " " + (end - begin));
  return output;
}

/**
 * @brief create binary tree of length pow, searches for relevant vals, runs loops times, changes output
 * 
 * @param pow length of tree
 * @param loops number of times we loop
 * @param output string to update
 * @return char* updated string
 */
char* binTree(int pow, int loops, char *output){
  clock_t begin, end;
  list_t* list = make_evens_list(pow);
  begin = clock();
  for (int i = 0; i < loops; i++)
  {
    for (int searchVal = 0; searchVal < (4 << (pow + 1)) - 1; searchVal++)
    {
      binary_tree_search(list, pow, searchVal);
    }
    list_free(list);
  }

  end = clock();

  strcat(output, " " + (end - begin));
  return output;
}


int main(int argc, char *argv[])
{
char* labels = "SIZE  NSEARCH";
//if to test and set datatypes to try

printf("%s", labels);

//now call funcs to test
for (int i = argv[1]; i < argv[2]; i++)
{
  char* output = argv[1] + "\t" + (argv[1]*argv[3]);
  if (/* condition */) //lin arr
  {
    output = linArr(i, argv[3], output);
  }

  if (/* condition */) // bin arr
  {
    output = binArr(i, argv[3], output);
  }

  if (/* condition */) // link list
  {
    output = linkList(i, argv[3], output);
  }
  
  if (/* condition */) // tree
  {
    output = binTree(i, argv[3], output);
  }
  printf("%s\n",output);
  output = "";
  
}
  return 0;
}
