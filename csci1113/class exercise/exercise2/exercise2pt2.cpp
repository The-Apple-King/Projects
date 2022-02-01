//Owen Swearingen swear041@umn.edu
#include <iomanip>
#include <ios>
#include <iostream>
#include <cmath>
using namespace std;

const int NUMITEMS = 3;

int main() {

    double height = 0;
    double base = 0;
    cout << std::setprecision(2) << std::fixed;
	cout << ("enter the base of the triangle: ");
    cin >> base;
    cout << ("enter the height of the triangle: ");
    cin >> height;
    double hypotenuse = sqrt((base*base) + (height*height));
    double area = base*height*.5;
    cout << ("the base of the triangle is: ") << setw(20) << (round(base*100)/100) << "\n";
    cout << ("the height of the triangle is: ") << setw(18) << (round(height*100)/100) << "\n";
    cout << ("the hypotenuse of the triangle is: ") << setw(14) << (round(hypotenuse*100)/100) << "\n";
    cout << ("the area of the triangle is: ") << setw(20) << (round(area*100)/100);
    cin >> height;
	return 0;

}