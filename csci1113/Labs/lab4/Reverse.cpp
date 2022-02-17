#include <iostream>
#include <string>

using namespace std;
int main(){
    string num = "";
    cout << "Input a positive integer: ";
    cin >> num;
    for (int i = num.size()-1; i >= 0; i--)
    {
       cout << num[i];
    }
}