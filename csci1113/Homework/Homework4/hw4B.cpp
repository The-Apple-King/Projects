// Owen Swearingen
// Homework 4A
// opens and closes mailboxes to output list of squares

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int separate(string number, int numberArr[]);

int main()
{
    string number1;
    int number1array[300] = {0};
    int number2array[300] = {0};
    string number2;
    cout << "enter number 1: ";
    cin >> number1;
    cout << "enter number 2: ";
    cin >> number2;

    int array1Pos = 0;
    int array2Pos = 0;
    string strtest;
    int inttest;

    array1Pos = separate(number1, number1array);
    array2Pos = separate(number2, number2array);

    cout << "the result is ";
    int carry = 0;
    for (size_t i = 0; i < max(array1Pos, array2Pos) + 2; i++)
    {
        inttest = (number1array[i] + number2array[i] + carry);
        number1array[i] = ((number1array[i] + number2array[i] + carry) % 1000);
        carry = (number1array[i] + number2array[i] + carry) / 1000;
    }

    for (int i = max(array1Pos, array2Pos) + 2; i >= 0; i--)
    {
        if (number1array[i] != 0)
        {
            cout << number1array[i] << ",";
        }
    }
}

int separate(string number, int numberArr[])
{
    int count =0;
    int len = 0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        while (i > 0 && number[i] != ',')
        {
            len++;
            i--;
        }
        numberArr[count] = stoi(number.substr(i, len));
        count++;
    }
    return count;
}