#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	
	string name;
	int i, j;

	cout << "Please enter your name: ";
	getline(cin, name);

	cout << "Your name is " << name << endl;
	j = name.length() - 1;
				
	for (i = 0; i <= j; i++, j--) {
		char temp = name.at(j);
		name.at(j) = name.at(i);
		name.at(i) = temp;

	}
	

	cout << "Your name spelled backwards is " << name << endl;
	
	return 0;

}