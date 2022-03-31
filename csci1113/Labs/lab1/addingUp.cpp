#include <iostream>
using namespace std;

const int NUMITEMS = 3;

int main() {

	int sum = 0, number;

	double average;
	for (int i = 0; i < NUMITEMS; i++) {

		cout << "Enter a number: ";
		cin >> number;

		sum += number;
		
	}
	average = sum / NUMITEMS;

	cout << "The average of all the numbers is: " <<  << endl;

	return 0;

}