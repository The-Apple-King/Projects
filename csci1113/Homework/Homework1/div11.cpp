#include <iostream>
using namespace std;

int main() {
    string num = "";
    int sum = 0;
    cout << "Enter the integer to be divided by 11: ";
    cin >> num;
    for (size_t i = 0; i < num.length(); i++)
    {
        if(i%2 ==0){
            sum += (int)num.substr(i,i+1);
        }
        else{
            sum -= (int)num.substr(i,i+1);
        }
    }
    if(sum%11 == 0){
        cout << num << "is divisible by 11";
    }
    else{
        cout << num << "is not divisible by 11";
    }
	
}