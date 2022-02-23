#include <iostream>
#include <string>
using namespace std;

bool leapYear(int year){
    if (year % 4 == 0 || (year % 100 == 0 && year % 400 != 0))
        {
            return true;
        }
        else
        {
            return false;
        }
}

int main()
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    char cont = 'Y';
    
    while (cont == 'Y')
    {
        cout << "\nenter month and year value: ";
        cin >> day >> month >> year;
        if(leapYear(year) && month == 2 && day == 28){
            cout << "The next day is 2 29 " << year << "\n";
        }
        else{
            if (day == daysInMonth[month])
            {
                cout << "next day is: 1 " << (month + 1) << " " << year << "\n";
            }
            else{
                cout << "next day is: " << (day + 1) << " " << month << " " << year << "\n";
            }
        }
        cout << "continue? (y/n)";
        cin >> cont;
        cont = toupper(cont);
    }
}