#include <iostream>
using namespace std;

int main() {

	double cost = 0;
    double paid = 0;
    int change = 0;
    cout << "Enter cost: ";
    cin >> cost;
    cout << "Enter paid in Dollars: ";
    cin >> paid;

    change = (100*paid) - (100*cost);
    cout << change/2000 << " 20 Dollar Bills" << "\n";
    change = change%2000;
    cout << change/1000 << " 10 Dollar Bills" << "\n";
    change = change%1000;
    cout << change/100 << " Dollars" << "\n";
    change = change%100;
    cout << change/25 << " Quarters" << "\n";
    change = change%25;
    cout << change/10 << " Dimes" << "\n";
    change = change%10;
    cout << change/5 << " Nickels" << "\n";
    change = change%5;
    cout << change << " Pennies" << "\n";
}