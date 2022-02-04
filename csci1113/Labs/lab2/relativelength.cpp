#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double L = 0;
    double v = 0;
    double c = 30000000000;
    
    cout << "Length: ";
    cin >> L;
    cout << "Velocity: ";
    cin >> v;

    cout << "the relative length is:" << L*sqrt(1-((v*v)/(c*c)));

	return 0;

}