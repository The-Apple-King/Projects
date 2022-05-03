#include <iostream>
using namespace std;
int minIndex(double *values, int length){
    int min = 0;
    for (size_t i = 1; i < length; i++)
    {
        if (values[min] > values[i])
        {
            min = i;
        }
    }
    
}

int revMinInxed(double *values, int length){
    int min = values[length];
    for (size_t i = length-1; i >=0; i++)
    {
        if (values[min] > values[i])
        {
            min = i;
        }
    }
}

int main(){
int* secret; 
 int* p; 
 
 secret = new int[10]; 
 
 *secret = 10; 
 p = &secret[1]; 
 
 for (int j = 1; j < 10; j++) { 
  *p = *(p - 1) + 5; 
  p++; 
 } 
 
 for (int j = 0; j < 10; j++) { 
  cout << *(secret + j) << "  "; 
 } 
 
 cout << endl; 
 
 return 0; 
}