// Owen Swearingen
// Homework 4A
// adds two numbers with up to 300 digits

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int separate(string number, int numberArr[]);
string createNum(int *arr, int array1Pos, int array2Pos);
void doMath(int *number1array, int *number2array, int array1Pos, int array2Pos);

int main()
{
    string number1;
    string number2;
    int number1array[100] = {0};
    int number2array[100] = {0};
    int array1Pos = 0;
    int array2Pos = 0;

    // inputs
    cout << "ENTER THE NUMBER USING THIS FORMAT(###,###,###) UP TO 300 DIGITS:";
    cin >> number1;
    cout << "ENTER THE NUMBER USING THIS FORMAT(###,###,###) UP TO 300 DIGITS:";
    cin >> number2;
    cout << endl;

    // creates number arrays and their max positions
    array1Pos = separate(number1, number1array);
    array2Pos = separate(number2, number2array);

    // adds together
    doMath(number1array, number2array, array1Pos, array2Pos);

    // outputs
    if (array1Pos > 99 || array2Pos > 99) // if too big
    {
        cout << "OVERFLOW WARNING\n"
             << endl;
        cout << "ADDITION RESULT: "
             << "0,";
        for (size_t i = 0; i < 98; i++)
        {
            cout << "000,";
        }
        cout << "000";
    }
    else // normal case
    {
        cout << "ADDITION RESULT: ";
        cout << createNum(number1array, array1Pos, array2Pos);
    }
}

/**
 * @brief separates input by commas and puts each section into an array
 *
 * @param number the input from user
 * @param numberArr the array for storing numbers
 * @return int returns number of array positions used
 */
int separate(string number, int numberArr[])
{
    int count = 0;
    for (int i = number.length(); i >= 0; i--)
    {
        //searches for every comma in input
        int len = 0;
        while (i >= 0 && number[i] != ',')
        {
            len++;
            i--;
        }
        // sets every string of numbers into an int
        numberArr[count] = stoi(number.substr(i == 0 ? i : i + 1, len));
        count++;
    }
    return count;
}

/**
 * @brief creates a string of the value of the array
 *
 * @param arr array containing number
 * @param array1Pos max position for first number
 * @param array2Pos max position for the second number
 * @return string number to be outputted
 */
string createNum(int *arr, int array1Pos, int array2Pos)
{
    string output = "";
    for (int i = max(array1Pos, array2Pos); i >= 0; i--)
    {
        //tests if starts with a zero and skips it
        if(arr[i] == 0 && i == max(array1Pos, array2Pos)){
            i--;
        }
        // adds zeroes where needed
        if (i != max(array1Pos, array2Pos))
        {
            if (arr[i] < 100)
            {
                output += "0";
            }
            if (arr[i] < 10)
            {
                output += "0";
            }
        }
        output += to_string(arr[i]);
    }
    // adds commas to the final string
    //number of commas
    int commas = output.length() / 3;
    if (output.length() % 3 == 0)
    {
        commas--;
    }
    //putting commas in string
    for (size_t i = 0; i < commas; i++)
    {
        output.insert(output.length() - 3 * (commas - i), ",");
    }
    return output;
}

/**
 * @brief adds the two arrays together
 *
 * @param number1array first number stored in an array
 * @param number2array second number stored in an array
 * @param array1Pos max array position for first number
 * @param array2Pos max array position for second number
 */
void doMath(int *number1array, int *number2array, int array1Pos, int array2Pos)
{
    int carry = 0;// stores 1's that need to carry to the next part of the array
    int temp = 0;// stores value so that we can repurpose number1array
    for (size_t i = 0; i < max(array1Pos, array2Pos) + 2; i++)
    {
        temp = (number1array[i] + number2array[i] + carry);
        number1array[i] = temp % 1000;//numbers less than 1000
        carry = temp / 1000; //sets carry if over 1000
    }
}