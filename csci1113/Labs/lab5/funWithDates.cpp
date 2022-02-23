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
    int month;
    int year;
    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "\nenter month and year value: ";
        cin >> month >> year;
        if(leapYear(year) && month == 2){
            cout << "days in a month: 29\n";
        }
        else{
            cout << "days in a month: " << daysInMonth[month-1] << "\n";
        }
        cout << "continue? (y/n)";
        cin >> cont;
        cont = toupper(cont);
    }
}