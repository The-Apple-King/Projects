#include <iostream>
using namespace std;

int main()
{
    int month; // stores the month
    int day; // stores the day of the month and how many days since january 1st
    char temp; // stores the / in the date
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in each month for adding to day
    // enter info
    cout << "Enter the month/day when you were born: \n";
    cin >> month >> temp >> day;

    //checks if valid month
    if (month > 0 && month <= 12)
    {
        // turns months into days
        for (size_t i = 0; i < month - 1; i++)
        {
            day += daysInMonth[i];
        }
        // checks days, if they are less than 20 its capricorn, else day-20 and day/29 to get location in array
        if (day < 19 || day > 355)
        {
            cout << "Capricorn";
        }
        else if(day < 50)
        {
            cout << "Aquarius";
        }
        else if(day < 80)
        {
            cout << "Pisces";
        }
        else if(day < 110)
        {
            cout << "Aries";
        }
        else if(day < 141)
        {
            cout << "Taurus";
        }
        else if(day < 172)
        {
            cout << "Gemini";
        }
        else if(day < 204)
        {
            cout << "Cancer";
        }
        else if(day < 235)
        {
            cout << "Leo";
        }
        else if(day < 266)
        {
            cout << "Virgo";
        }
        else if(day < 296)
        {
            cout << "Libra";
        }
        else if(day < 326)
        {
            cout << "Scorpio";
        }
        else if(day < 355)
        {
            cout << "Sagittarius";
        }
    }
    else
    {
        cout << "Invalid month";
    }
}
