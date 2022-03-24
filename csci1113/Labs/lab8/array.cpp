#include <iostream>
using namespace std;

void showValues(int [], int); // Function prototype
const int ARRAY_SIZE = 100;

int main()
{
   int numbers[ARRAY_SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};

   showValues(numbers, ARRAY_SIZE);
   return 0;
}

//**************************************************
// Definition of function showValue.               *
// This function accepts an array of integers and  *
// the array's size as its arguments. The contents *
// of the array are displayed.                     * 
//**************************************************

void showValues(int nums[], int size)
{
   for (int index = 0; index <= size; index++)
      cout << nums[index] << " ";
   cout << endl;
}

//int[] to int
//invalid conversion from int* to int

//int [] to int
//invalid types

// < to <=
//returns a zero at the end of the array

//numbers to numbers[]
//expected primary-expression before ]

//numbers[] to numbers[0]
//invalid conversion from int to int*

//int [] to int &
//invalid conversion from int to int*


//8 to array_size
// returns a bunch of zeroes