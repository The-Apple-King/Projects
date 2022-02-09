#include <iostream>
using namespace std;

int main() {

	double cost = 0;
    int paid = 0;
    int change = 0;
    cout << "Enter cost: ";
    cin >> cost;
    cout << "Enter paid in Dollars: ";
    cin >> paid;

    change = (int)(100*(paid- cost)+1);
    cout << change;
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