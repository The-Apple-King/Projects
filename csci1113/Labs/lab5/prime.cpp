#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int num);

int main()
{
    int num;
    cout << "please enter a number: ";
    cin >> num;

    if(isPrime(num)){
        cout << num << " is a prime number";
    }
    else{
        cout << num << " is not a prime number";
    }


}

bool isPrime(int num){
    for (size_t i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0 && num !=1){
            return false;
        }
    }
    return true;
}