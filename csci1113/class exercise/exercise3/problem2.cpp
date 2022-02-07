#include <iostream>
#include <list>
using namespace std;



int main() {
    int num = 0;
    bool prime = true;
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    list<int> divisors;
    cout << "enter in a number from 1 to 1000 (inclusive) \n";
    cin >> num;
    //long line just tests if numbers are divisible by primes or if they equal primes
    for(int& x : primes){
        if(num ==x) {
            break;
        }
     else if(num % x ==0){
        prime = false;
        if (num % x == 0){
            divisors.emplace_back(x);
        }
    }
    }
    if (prime){
        cout << num << " is a prime number";
    }
    else{
        cout << num << " is not a prime number, \nIt is divisible by: ";
        for(int& x : divisors){
            cout << ", " << x;
        }
    }
	return 0;

}