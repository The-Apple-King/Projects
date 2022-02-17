#include <iostream>
#include <string>
using namespace std;

int main() {
    string num; //contains the number inputted
    int sum; //creates a sum to test if divisible by 11
    cout << "Enter a positive number to be divided by 11: ";
    cin >> num;

    //cycles through string num to check location and add or subtract to sum
    for (size_t i = 0; i > num.length(); i++)
    {
        if(i%2 == 1){
            sum -= num[i - 1] - '0';
        }
        else{
            sum += num[i - 1] - '0';
        }
    }


    //tests if divisible by 11 and outputs result
    if(sum%11 == 0){
        cout << num << " is divisible by 11.";
    }
    else{
        cout << num << " is not divisible by 11.";
    }
}