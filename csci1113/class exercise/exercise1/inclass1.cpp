#include <iostream>
#include <string>
using namespace std;

int main() {

	int numCookies = 0;
    cout << "Please enter the number of cookies: ";
    cin >> numCookies;
    cout << "you consumed ";
    // returns the number of cookies times number of calories
    cout << (numCookies*100);
    cout << " calories";
    cin >> numCookies;
	return 0;
//Owen Swearingen 041
//Sanurag Rout 054
}