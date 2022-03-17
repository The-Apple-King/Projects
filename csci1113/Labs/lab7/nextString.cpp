#include <iostream>
#include <string>
using namespace std;


string nextString(string input, int start)
{
    return input.substr(start, (input.substr(start).find(",")));
}

int main(){
    int loc = 0;
    string input = "";
    getline(cin, input);
    cin >> loc;
    cout << nextString(input, loc);
}