#include <iostream> 
#include <string> 
using namespace std; 
 
string* getFullName(); 
int main() { 
 
    string* name; 
 
    name = getFullName(); 
    for (int i = 0; i < 3; i++) { 
        cout << name[i] << " "; 
    } 
    cout << endl; 
 
    delete[] name; 
 
    return 0; 
} 
string* getFullName() { 
 
    string fullName[3]; 
    cout << "Enter your first name "; 
    getline(cin, fullName[0]); 
    cout << "Enter your second name "; 
    getline(cin, fullName[1]); 
    cout << "Enter your last name "; 
    getline(cin, fullName[2]); 
 
    return fullName; 
}