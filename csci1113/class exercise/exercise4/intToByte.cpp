#include <iostream>
#include <string>
using namespace std;

int main() {
    int num =0;
    int remainder = 0;
    string bitStr = "";
    string bit = "";
    cout << "Enter the integer: ";
    cin >> num;
    while(num != 0){
        remainder = num % 2;
        bit = to_string(remainder);
        bitStr = bit + bitStr;
        num /= 2;
    }
    for (size_t i = 0; i < (16 - bitStr.length()); i++)
    {
        cout << "0";
    }
    
    cout << bitStr << endl;
    return 0;
}