#include <iostream>
using namespace std;

int main()
{
    string password1 = "";
    string password2 = "";

    cout << "Enter two passwords: ";
    cin >> password1 >> password2;

    if(password1 == password2){
        cout << "passwords match" << endl;
    }
    else{
        cout << "passwords do not match" << endl;
    }
}