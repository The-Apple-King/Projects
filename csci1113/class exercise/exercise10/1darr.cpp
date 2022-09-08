#include <iostream>
using namespace std;

class date
{
private:
    int day, month, year;
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNames[13] = {"", "january", "febuary", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

public:
    date(int, int, int);
    ~date();
    void print(int);
    date &operator++();
    date &operator--();
    date &operator++(int);
    date &operator--(int);
    int &operator-(date);
    bool operator==(date);
    date &operator<<(ostream);
    date &operator>>(istream);
    date &operator<(date);
    date &operator>(date);
};

date::date(int dayval, int monthval, int yearval)
{
    day = dayval;
    month = monthval;
    year = yearval;
}

date::~date()
{
}

void date::print(int type)
{
    switch (type)
    {
    case 1:
        cout << month << "/" << day << "/" << year;
        break;
    case 2:
        cout << monthNames[month] << " " << day << ", " << year;
        break;
    case 3:
        cout << day << " " << monthNames[month] << " " << year;
        break;

    default:
        cout << "enter a number 1, 2, or 3";
        break;
    }
}

date &date::operator++()
{
    day++;
    if (daysInMonth[month] < day)
    {
        month++;
        day = 1;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    date d1 = date(day, month, year);
    return d1;
}

date &date::operator++(int)
{
    date d1 = date(day, month, year);
    day++;
    if (daysInMonth[month] < day)
    {
        month++;
        day = 1;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return d1;
}

date &date::operator--()
{
    day--;
    if (1 > day)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }
    date d1 = date(day, month, year);
    return d1;
}

date &date::operator--(int)
{
    date d1 = date(day, month, year);
    day--;
    if (1 > day)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }
    return d1;
}

int &date::operator-(date d1)
{
    int days = 0;
    days += (this->year - d1.year) * 365;
    for (size_t i = 0; i < this->month; i++)
    {
        days += daysInMonth[i];
    }
    for (size_t i = 0; i < d1.month; i++)
    {
        days -= daysInMonth[i];
    }
    day += this->day - d1.day;
    return days;
}

bool date::operator==(date d1)
{
    if (this->year == d1.year && this->month == d1.month * *this.day == d1.day)
    {
        return true;
    }
    else{
        return false;
    }
}

date &date::operator<<(ostream out)
{
    out += print(2);
    return out;
}

date &date::operator>>(istream in)
{
}

date &date::operator<(date d1)
{
}

date &date::operator>(date d1)
{
}

int main()
{
}