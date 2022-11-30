// sort_doubles.c: Somewhat simpler demo of using function
// pointers. Shows to functions that are caste to the same type
// (cmp_t) when assigned to a pointer. qsort() is used to to sort
// doubles using these comparison functions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longcmp(long *xp, long *yp) {       // compare longs
  return -(*xp < *yp) + (*xp > *yp);    // a bit of trickiness to do int comparisons and generate -1,0,+1
}

int doubcmp(double *xp, double *yp) {   // compare doubles
  return -(*xp < *yp) + (*xp > *yp);    // a bit of trickiness to generate -1,0,+1
}

// convenience type to enable casting of typed comparisong functions
// to the void-ish functions expected by qsort()
typedef int (*cmp_t) (const void *, const void *);

int main(int argc, char *argv[]) {
  if(argc < 2){
    printf("usage: %s {long|doub}\n",argv[0]);
    printf("specify whether to sort using 'long' comparisons or 'doub'-le comparisons\n");
    return 0;
  }
    
  cmp_t compare = NULL;               // function pointer
  if( strcmp(argv[1],"long" )==0 ){   // sort as longs
    compare = (cmp_t) longcmp;
  }
  else {
    compare = (cmp_t) doubcmp;
  }
    
  // positive doubles will sort fine using either floating point or
  // integer comparisons
  double arr[10] = {1.1, 6.6, 5.5, 2.2, 3.3, 9.0, 4.4, 7.7, 8.8, 0.5}; 
  qsort((void*) arr, 10, sizeof(double), compare); // sort using compare() function
    
  printf("positive arr sorted as '%s':\n",argv[1]);
  for (int i = 0; i < 10; ++i) {      // print sorted array
    printf("%.1f ", arr[i]);
  }
  printf("\n");

  printf("\n");

  // Arrays of doubles with negative values will sort "slightly" out
  // of order if treated as longs: negatives appear in reversed order
  // double arr2[10] = {-1.1, -6.6, -5.5, -2.2, -3.3, -9.0, -4.4, -7.7, -8.8, -0.5}; 
  double arr2[10] = {1.1, 6.6, -5.5, -2.2, 3.3, -9.0, 4.4, -7.7, 8.8, -0.5}; 
  qsort((void*) arr2, 10, sizeof(double), compare); // sort using compare() function
    
  printf("pas/neg arr2 sorted as '%s':\n",argv[1]);
  for (int i = 0; i < 10; ++i) {      // print sorted array
    printf("%.1f ", arr2[i]);
  }
  printf("\n");

  if(compare == (cmp_t) doubcmp){
    return 0;                         // already sorted as doubles, don't need to patch
  }

  // but with a O(N) search for the boudary of the negative side +
  // O(N) reversal of the negative part of the array, the sorted order
  // can be achieved

  int last_neg = 0;                  // find boundary of negatives, could also do binary search
  while(last_neg < 10 && arr2[last_neg]<0.0){
    last_neg++;
  }

  for(int i=0; i<last_neg/2; i++){    // reverse negative part of the array
    double tmp = arr2[i];
    arr2[i] = arr2[last_neg-i-1];
    arr2[last_neg-i-1] = tmp;
  }
  
  printf("pas/neg arr2 sorted as '%s' and patched:\n",argv[1]);
  for (int i = 0; i < 10; ++i) {      // print sorted array
    printf("%.1f ", arr2[i]);
  }
  printf("\n");

  return 0; 
} 
