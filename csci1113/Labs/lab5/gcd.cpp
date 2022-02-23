#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b){
    int r = a%b;
    if(r ==0)
    {
        return b;
    }
    GCD(b,r);
}

int main()
{
    int num1, num2;
    char cont = 'Y';
    
    while (cont == 'Y')
    {
        cout << "please enter two numbers: ";
        cin >> num1 >> num2;

        cout << GCD(num1, num2) << " is the greatest common denominator.\n";
        cout << "continue? (y/n)";
        cin >> cont;
        cont = toupper(cont);
    }
}