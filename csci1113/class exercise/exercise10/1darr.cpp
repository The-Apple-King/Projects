#include <iostream>
using namespace std;

class date
{
private:
    int day, month, year;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    date(int, int, int);
    ~date();
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


int main(){

}