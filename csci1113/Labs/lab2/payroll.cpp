#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double pay = 16.78;
    double unio = 10.00;
    int depend = 0;
    int hours = 0;

    
    cout << "enter hours per week: ";
    cin >> hours;
    cout << "enter dependants: ";
    cin >> depend;
    if (hours <= 40) {
        if (depend < 3){
            cout << "pay: " << (hours*pay*.75)-10;
        }
        else {
            cout << "pay: " << (hours*pay*.75)-45;
        }
    }
    else if (hours > 40){
        if (depend < 3){
            cout << "pay: " << (((hours-40)*pay)*1.5)+((40*pay*.75)-10);
        }
        else {
            cout << "pay: " << (((hours-40)*pay)*1.5)+((40*pay*.75)-40);
        }
    }

	return 0;

}