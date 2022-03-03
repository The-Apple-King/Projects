#include <iostream>
using namespace std;

int timeToMinutes(int,int);

int main() {
    int hour = 0;
    int minute = 0;
    char temp;

    char cont = 'Y';
    while (cont == 'Y')
    {
        cout << "Enter time in Hour:Min format: ";
        cin >> hour >> temp >> minute;

        cout << "Time in minutes is: " << timeToMinutes(hour, minute) << "\n";

        cout << "continue? (y/n)";
        cin >> cont;
        cont = toupper(cont);
    }
}

int timeToMinutes(int hours, int min){
    return ((hours * 60) + min);
}