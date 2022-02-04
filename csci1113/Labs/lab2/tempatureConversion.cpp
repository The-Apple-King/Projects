#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char type = ' ';
    double temp = 0;
    
    cout << "enter tempature: ";
    cin >> temp;
    cout << "Fahrenheit(f) or Celsius(c) \n: ";
    cin >> type;
    if (type == 'f') {
        cout << temp << "\n\n";
        cout << "the temperature in celsius is: " << ((5.0/9.0)*(temp-32.0));
    }
    else if (type == 'c') {
        cout << temp << "\n\n";
        cout << "the temperature in fahrenheit is: " << ((temp*(9.0/5.0))+32.0);
    }
    else{
        cout << "please enter f or c";
    }

	return 0;

}