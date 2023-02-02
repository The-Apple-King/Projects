#include <iostream>
using namespace std;

int main()
{
    string password = "";
    int age = 0;

    cout << "Enter a password and your age: ";
    cin >> password >> age;
    if (password.length() > 8 && age >= 18)
    {
        cout << "Access granted." << endl;
    }
    else if (password.length() < 8 && age >= 18)
    {
        cout << "Password too short, access denied." << endl;
    }
    else if (password.length() > 8 && age < 18)
    {
        cout << "Too young, access denied." << endl;
    }
    else
    {
        cout << "Access denied" << endl;
    }
}