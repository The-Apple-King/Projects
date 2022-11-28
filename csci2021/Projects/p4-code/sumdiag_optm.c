// optimized versions of matrix diagonal summing
#include "matvec.h"
#include <stdlib.h>

// You can write several different versions of your optimized function
// in this file and call one of them in the last function.

int sumdiag_VER1(matrix_t *mat, vector_t *vec) {
  if(vec->len != (mat->rows + mat->cols -1)){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }

  vector_t vec1 = *vec;
  matrix_t mat1 = *mat;
  
  // create an array so we can increment the vals of diagonals instead of setting them repeatedly
  int* vecArr;
  vecArr = (int*) malloc(sizeof(int) * vec1.len+1);
  for(int i=0; i<vec1.len; i++){
   vecArr[i] = 0;
  }

  //acess rows then cols: makes full use of cache
  // loc is the diagonal location: created in loop so it doesnt take up space in register
  for (size_t y = 0, loc = mat1.cols-1; y < mat1.rows; y++, loc--){
    for (size_t x = 0; x < mat1.cols; x++){
      vecArr[loc + x] += MGET(mat1, y, x);
    }
  }
  
  // sets the val of vectors 1 by 1
  for (size_t i = 0; i < vec1.len; i++){
    VSET(vec1, i, vecArr[i]);
  }
    free(vecArr);
    *vec = vec1;
  return 0;
}

int sumdiag_VER2(matrix_t *mat, vector_t *vec) {
  // OPTIMIZED CODE HERE
  return 0;
}

int sumdiag_OPTM(matrix_t *mat, vector_t *vec) {
  // call your preferred version of the function
  return sumdiag_VER1(mat, vec);
}
