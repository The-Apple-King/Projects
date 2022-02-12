#include <iostream>
using namespace std;

int main()
{
    int month; // stores the month
    int day; // stores the day of the month and how many days since january 1st
    char temp; // stores the / in the date
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in each month for adding to day
    string zodiac[] = {"Aquarius", "Piscese", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Saggitarius", "Capricorn"}; // zodiac signs easy to call
    // enter info
    cout << "Enter when you were born in dd/mm format: ";
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
        if (day < 20)
        {
            cout << "Your zodiac sign is Capricorn";
        }
        else
        {
            day -= 20;
            cout << "Your zodiac sign is " << zodiac[(day / 29)];
        }
    }
    else
    {
        cout << "Your zodiac sign is Please enter a valid date";
    }
}
