//Owen Swearingen swear041@umn.edu
#include <iostream>
#include <cmath>
using namespace std;

const int NUMITEMS = 3;

int main() {

    double radius = 0;

	cout << ("enter the radius of the sphere: ");
    cin >> radius;
    radius = radius*radius*radius;
    cout << ("the volume of the sphere is: ") << (round(1000*(4/3*(3.1415926535*radius)))/1000);
	return 0;

}