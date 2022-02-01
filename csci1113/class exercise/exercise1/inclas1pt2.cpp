#include <iostream>
#include <string>
using namespace std;

int main() {

	double numCookies = 0;
    cout << "Please enter the number of cookies: ";
    cin >> numCookies;
    // reuse numcookies as a ratio because we only use it once
    numCookies = numCookies/48.0;
    //returns ingredient amounts * ratio
    cout << "amount of sugar " << (1.5*numCookies) << "\n";
    cout << "amount of butter " << (1 * numCookies) << "\n";
    cout << "amount of flour " << (2.75 *numCookies) << "\n";
	
    //Owen Swearingen 041
    //Sanurag Rout 054
}