#include <iostream>
using namespace std;

int main() {
    char color = ' ';
    cout << "Enter the first letter of the color";
    cin >> color;
    if(toupper(color) == 'O'){
        cout << "the container has Ammonia";
    }
    else if(toupper(color) == 'Y'){
        cout << "the container has Hydrogen";
    }
    else if(toupper(color) == 'B'){
        cout << "The container has Carbon Monoxide";
    }
    else if (toupper(color) == 'G'){
        cout << "The container has Oxygen";
    }
}