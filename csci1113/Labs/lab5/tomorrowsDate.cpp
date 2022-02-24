#include <iostream>
#include <string>
using namespace std;

bool leapYear(int year);

int main()
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    char cont = 'Y';
    
    while (cont == 'Y')
    {
        cout << "\nenter month and year value: ";
        cin >> month >> day >> year;
        if(leapYear(year) && month == 2 && day == 28){
            cout << "The next day is 2 29 " << year << "\n";
        }
        else{
            if (day >= daysInMonth[month-1])
            {
                if(month < 12){
                cout << "next day is: " << (month + 1) << " 1 " << year << "\n";
                }
                else{
                    cout << "next day is: 1 1 " << (year+1) << "\n";
                }
            }
            else{
                cout << "next day is: " << month << " " << (day + 1) << " " << year << "\n";
            }
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