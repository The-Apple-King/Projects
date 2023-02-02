#include <iostream>
#include "personHeight.h"
using namespace std;


int main(){
personHeight Shonal = personHeight(6, 0);
personHeight Libby = personHeight(5,5);
personHeight VeryShort = personHeight();

cout << Shonal.height_in_inches() << endl;
cout << Libby.height_in_inches() << endl;
cout << VeryShort.height_in_inches() << endl;
}