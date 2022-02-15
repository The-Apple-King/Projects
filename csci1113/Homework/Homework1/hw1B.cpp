#include <iostream>
#include <string>
using namespace std;

int main() {
    uint32_t num; //contains the number inputted
    uint32_t sum = 0; //creates a sum to test if divisible by 11
    uint32_t original; //stores original value of num
    bool end = true; //used to test when to jump out of the loop
    cout << "Enter a positive integer: ";
    cin >> num;
    original = num;

    //cycles through the int %10 and /10 adding and subtracting to sum until there is a single digit
    for (size_t i = 0; end; i++)
    {
        if (num < 10)
        {
            end = false;
        }
        
        if(i%2 == 1){
            sum -= num%10;
        }
        else{
            sum += num%10;
        }
        num = num/10;
    }
    
    //tests if divisible by 11 and outputs result
    if(sum%11 == 0){
        cout << original << " is divisible by 11.";
    }
    else{
        cout << original << " is not divisible by 11.";
    }
    
}