#include <iostream>
using namespace std;

int main()
{

    int num = 0;
    string out = "";

    cout << "Enter the number : ";
    cin >> num;

    // do math and output
    while (num > 0)
    {
        if (num <= 999 && num >= 900)
        {
            out += "CM";
            num -= 900;
        }
        else if (num <= 899 && num >= 500)
        {
            out += "D";
            num -= 500;
        }
        else if (num <= 499 && num >= 400)
        {
            out += "CD";
            num -= 400;
        }
        else if (num <= 399 && num >= 100)
        {
            out += "C";
            num -= 100;
        }
        else if (num <= 99 && num >= 90)
        {
            out += "XC";
            num -= 90;
        }
        else if (num <= 89 && num >= 50)
        {
            out += "L";
            num -= 50;
        }
        else if (num <= 49 && num >= 40)
        {
            out += "XL";
            num -= 40;
        }
        else if (num <= 39 && num >= 10)
        {
            out += "X";
            num -= 10;
        }
        else if (num == 9)
        {
            out += "IX";
            num -= 9;
        }
        else if (num <= 8 && num >= 5)
        {
            out += "V";
            num -= 5;
        }
        else if (num == 4)
        {
            out += "IV";
            num -= 4;
        }
        else if (num <= 3 && num >= 1)
        {
            out += "I";
            num -= 1;
        }
    }
    cout << out;
}