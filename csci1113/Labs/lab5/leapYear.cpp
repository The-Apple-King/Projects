#include <iostream>
#include <string>
using namespace std;

bool leapYear(int year);

int main()
{

    int year;
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "\nenter a year value: ";
        cin >> year;
        if (leapYear(year))
        {
            cout << year << " is a leap year \n";
        }
        else
        {
            cout << year << " is not a leap year \n";
        }
        cout << "continue? (y/n)";
        cin >> cont;
        cont = toupper(cont);
    }
}

bool leapYear(int year){
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
}