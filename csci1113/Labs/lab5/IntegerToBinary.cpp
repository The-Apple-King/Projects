#include <iostream>
#include <string>
using namespace std;

string numberToBitString(int number, string bitStr, string bit, int remainder);

void To16Bit(string bitStr);

int main(){

    int number, remainder;
    string bitStr = "" ;                         // initialize the bit string accumulator to null
    string bit;

    cout << "Enter a positive number: ";
    cin >> number;
    
    bitStr = numberToBitString(number, bitStr, bit, remainder);
    To16Bit(bitStr);

    cout << bitStr << endl;                         // output the current result 
    // need to modify for a sixteen bit string
}

string numberToBitString(int number, string bitStr, string bit, int remainder){
    while(number != 0){

        remainder = number % 2;                     // get a bit i.e. 1 or 0
        bit = to_string(remainder);                 // to_string C++ 11 convention to convert to string
        bitStr =  bit + bitStr ;                    // add the bit to the string using concatenation
        number /= 2;                                // Use the quotient for repeated division
    }
    return bitStr;
}

void To16Bit(string bitStr){
    int length = 16;
    length -= bitStr.length();
    for (size_t i = 0; i < length; i++)
    {
        cout << "0";
    }
}