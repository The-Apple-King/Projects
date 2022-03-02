#include <iostream>
#include <string>
using namespace std;

int sum(int values[]);

int main(){
    //check for size create array and run function
}

int sum(int values[]){
    int sum = 0;
    for (size_t i = 0; i < sizeof(values)/sizeof(1); i++)
    {
        sum += values[i];
    }
    return sum;
}

int sumSquare(int values[]){
    int sum = 0;
    for (size_t i = 0; i < sizeof(values)/sizeof(1); i++)
    {
        sum += (values[i]*values[i]);
    }
    return sum;
}