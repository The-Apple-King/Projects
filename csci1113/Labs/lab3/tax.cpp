#include <iostream>
using namespace std;

int main() {
    int income = 0;
    int tot = 0;
    double tax =0;
    cout << "Enter income in drachmas: ";
    cin >> income;
    tot = income;
	if(income >= 70000)
    tax = .3*(income-70000);
    income =70000;

    if(income >= 30000)
    tax = tax + (.2*(income-30000));
    income =30000;

    if(income > 10000)
    tax = tax + (.1*(income-10000));
    income =10000;
    
    cout << "The tax is " << tax << " for an income of " << tot;
}