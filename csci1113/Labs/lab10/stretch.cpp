#include <iostream>
#include <string>
using namespace std;

void validateInput(int &number);
void getInput(string str, int &num);
void print(int rows, int cols, int **twoD);
void enter(int rows, int cols, int **twoD);
void del(int rows, int cols, int **twoD);
int** addArray(int** array1, int** array2, int x, int y);

int main(){
    int rows, cols;
    int **arr1;
    int **arr2;

    getInput("rows", rows);
    getInput("columns", cols);

    arr1 = new int *[rows];
    arr2 = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr1[i] = new int[cols];
        arr2[i] = new int[cols];
    }
    enter(rows, cols, arr1);
    print(rows, cols, arr1);
    enter(rows, cols, arr2);
    print(rows, cols, arr2);

    cout << "matrixes added together" << endl;
    print(rows, cols, addArray(arr1, arr2, rows, cols));
    

    return 0;
}

int** addArray(int** array1, int** array2, int x, int y){
    int** result;
    result = new int *[x];
    for (int i = 0; i < x; i++)
    {
        result[i] = new int[y];
    }

    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            result[i][j] = array1[i][j] + array2[i][j];
        }
        
    }
    return result;
}

void validateInput(int &number)
{
    while (number <= 0)
    {
        cout << number << " must be positive. Re-enter: ";
        cin >> number;
    }
}

void getInput(string str, int &num)
{
    cout << "How many " << str << " in your matrix? ";
    cin >> num;
    validateInput(num);
}

void print(int rows, int cols, int **twoD)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << twoD[i][j] << " ";
        }
        cout << endl;
    }
}

void enter(int rows, int cols, int **twoD)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "value for " << i << ", " << j << ": ";
            cin >> twoD[i][j];
        }
    }
}

void del(int rows, int cols, int **twoD)
{
    for (size_t j = 0; j < cols; j++)
    {
        delete [] twoD[j];
    }
    delete [] twoD;
}