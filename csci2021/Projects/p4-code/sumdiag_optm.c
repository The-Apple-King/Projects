// optimized versions of matrix diagonal summing
#include "matvec.h"
#include <stdlib.h>

// You can write several different versions of your optimized function
// in this file and call one of them in the last function.

int sumdiag_VER1(matrix_t *mat, vector_t *vec) {
  // OPTIMIZED CODE HERE
  if(vec->len != (mat->rows + mat->cols -1)){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }

  vector_t vec1 = *vec;
  matrix_t mat1 = *mat;
  
  // create an array so we can increment the vals of diagonals instead of setting them repeatedly
  int* vecArr;
  vecArr = (int*) malloc(sizeof(int) * vec1.len+1);
  for(int i=0; i<vec1.len-4; i+=4){
   vecArr[i] = 0;
   vecArr[i+1] = 0;
   vecArr[i+2] = 0;
   vecArr[i+3] = 0;
  }
  
  for (size_t i = vec1.len-4; i < vec1.len; i++)
  {
    vecArr[i] = 0;
  }
  

  //acess rows then cols: makes full use of cache
  // loc is the diagonal location: created in loop so it doesnt take up space in register
  for (size_t y = 0, loc = mat1.cols-1; y < mat1.rows; y++, loc--){
    int x;
    for (x = 0; x < mat1.cols-4; x+=4){
      vecArr[loc + x] += MGET(mat1, y, x);
      vecArr[loc + x+1] += MGET(mat1, y, x+1);
      vecArr[loc + x+2] += MGET(mat1, y, x+2);
      vecArr[loc + x+3] += MGET(mat1, y, x+3);
    }

    for (size_t i = x; i < mat1.cols; i++)
    {
      vecArr[loc + i] += MGET(mat1, y, i);
    }
  }
  
  // sets the val of vectors 1 by 1
  int i;
  for (i = 0; i < vec1.len-4; i+=4){
    VSET(vec1, i, vecArr[i]);
    VSET(vec1, i+1, vecArr[i+1]);
    VSET(vec1, i+2, vecArr[i+2]);
    VSET(vec1, i+3, vecArr[i+3]);
  }
  for (; i < vec1.len; i++)
  {
    VSET(vec1, i, vecArr[i]);
  }
  
    free(vecArr);
    *vec = vec1;
  
  return 0;
}

int sumdiag_VER2(matrix_t *mat, vector_t *vec) {
  // OPTIMIZED CODE HERE
  if(vec->len != (mat->rows + mat->cols -1)){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }

  vector_t vec1 = *vec;
  matrix_t mat1 = *mat;
  
  // create an array so we can increment the vals of diagonals instead of setting them repeatedly
  int* vecArr;
  vecArr = (int*) malloc(sizeof(int) * vec1.len+1);
  for(int i=0; i<vec1.len-4; i+=4){
   vecArr[i] = 0;
   vecArr[i+1] = 0;
   vecArr[i+2] = 0;
   vecArr[i+3] = 0;
  }
  
  for (size_t i = vec1.len-4; i < vec1.len; i++)
  {
    vecArr[i] = 0;
  }
  

  //acess rows then cols: makes full use of cache
  // loc is the diagonal location: created in loop so it doesnt take up space in register
  for (size_t y = 0, loc = mat1.cols-1; y < mat1.rows; y++, loc--){
    int x;
    for (x = 0; x < mat1.cols-4; x+=4){
      vecArr[loc + x] += MGET(mat1, y, x);
      vecArr[loc + x+1] += MGET(mat1, y, x+1);
      vecArr[loc + x+2] += MGET(mat1, y, x+2);
      vecArr[loc + x+3] += MGET(mat1, y, x+3);
    }

    for (size_t i = x; i < mat1.cols; i++)
    {
      vecArr[loc + i] += MGET(mat1, y, i);
    }
  }
  
  // sets the val of vectors 1 by 1
  int i;
  for (i = 0; i < vec1.len-4; i+=4){
    VSET(vec1, i, vecArr[i]);
    VSET(vec1, i+1, vecArr[i+1]);
    VSET(vec1, i+2, vecArr[i+2]);
    VSET(vec1, i+3, vecArr[i+3]);
  }
  for (; i < vec1.len; i++)
  {
    VSET(vec1, i, vecArr[i]);
  }
  
    free(vecArr);
    *vec = vec1;
  
  return 0;
}

int sumdiag_OPTM(matrix_t *mat, vector_t *vec) {
  // call your preferred version of the function
  return sumdiag_VER2(mat, vec);
}
