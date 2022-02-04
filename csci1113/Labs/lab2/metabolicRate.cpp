#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char sex = ' ';
    double weight = 0;
    double height = 0;
    double age = 0;
    double basal = 0;
    
    cout << "Male: M or Female: F \n: ";
    cin >> sex;
    cout << "weight in pounds: ";
    cin >> weight;
    cout << "height in inches: ";
    cin >> height;
    cout << "age in years: ";
    cin >> age;
    if (sex == 'F') {
        basal = (655+(4.3*weight) + (4.7*height) - (4.7*age));
        cout << "The amount of calories to maintain weight is:" << basal;
        cout << "the amount of chocolate bars needed to maintain weight is: " << (basal/230);
    }
    else if (sex == 'M') {
        basal = (66+(6.3*weight) + (12.9*height) - (6.8*age));
        cout << "The amount of calories to maintain weight is:" << basal;
        cout << "the amount of chocolate bars needed to maintain weight is: " << (basal/230);
   }
    else{
        cout << "please enter M or F";
    }

	return 0;

}