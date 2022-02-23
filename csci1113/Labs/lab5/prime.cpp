#include <iostream>
#include <string>
using namespace std;

bool isPrime(int num){
    for (size_t i = 2; i < (num/2); i++)
    {
        if(num%i == 0){
            return true;
        }
    }
    return false;
}

int main()
{
    int num;
    cout << "please enter a number: ";
    cin >> num;

    if(isPrime){
        cout << num << " is a prime number";
    }
    else{
        cout << num << " is not a prime number";
    }


}