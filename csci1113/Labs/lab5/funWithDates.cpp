#include <iostream>
#include <string>
using namespace std;

bool leapYear(int year);

int last_day(int month, int year, int daysInMonth[]);

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
        cout << "days in month: " << last_day(month, year, daysInMonth) << "\n";
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

int last_day(int month, int year, int daysInMonth[]){
    if(month>0 && month<13){
        if(leapYear(year) && month == 2){
            return 29;
        }
        else{
           return daysInMonth[month-1];
        }
    }
    else{
        return 0;
    }
}