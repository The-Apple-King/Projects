// Owen Swearingen
//Homework 4A

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

    //create data
    int table [3][3];
    int count = 10;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            table[j][i] = count;
            count--;
            cout << table[j][i] << " ";
        }
        cout << "\n";
    }
    
    
}