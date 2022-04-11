#include <iostream>
#include <string>
using namespace std;

void validateInput(int &number);
void getInput(string str, int &num);
void print(int rows, int cols, int **twoD);
void enter(int rows, int cols, int **twoD);
void del(int rows, int cols, int **twoD);

int main()
{

    int rows, cols;
    int **twoD;

    getInput("rows", rows);
    getInput("columns", cols);

    twoD = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        twoD[i] = new int[cols];
    }
    enter(rows, cols, twoD);
    print(rows, cols, twoD);
    del(rows, cols, twoD);
    print(rows, cols, twoD);

    return 0;
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