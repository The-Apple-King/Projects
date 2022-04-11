#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void validateInput(int &number);
void getInput(string str, int &num);
void print(int rows, int cols, int **twoD);
void enter(int rows, int cols, int **twoD);
void del(int rows, int cols, int **twoD);
int** addArray(int** array1, int** array2, int x, int y);
void printRowSums(int rows, int cols, int **twoD);
void printColSums(int rows, int cols, int **twoD);
void randomArr(int rows, int cols, int **twoD);


int main(){
    int rows, cols;
    int **arr1;

    srand(time(0));

    getInput("rows", rows);
    getInput("columns", cols);

    arr1 = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr1[i] = new int[cols];
    }
    randomArr(rows, cols, arr1);
    printRowSums(rows, cols, arr1);
    printColSums(rows, cols, arr1);

    return 0;
}

void randomArr(int rows, int cols, int** twoD){
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
           twoD[i][j] = (rand()%99)+1;
        }
    }
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

void printRowSums(int rows, int cols, int **twoD)
{
    int sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            sum += twoD[i][j];
            if(j != cols-1){
            cout << twoD[i][j] << " + ";
            }
            else{
                cout << twoD[i][j] << " = " << sum;
            }
        }
        cout << endl;
    }
}

void printColSums(int rows, int cols, int **twoD)
{
    int sum = 0;
    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            sum += twoD[j][i];
        }
        cout << sum << "   ";
        sum = 0;
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
    delete twoD;
}