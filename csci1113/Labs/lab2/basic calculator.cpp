#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Enter an equation: ";
    int l, r;
    char op;
    cin >> l;
    cin >> op;
    cin >> r;

    int out;
if(op == '+') {
     out = l + r;
    }
else if(op == '-') {
        out = l - r;
    }
else if(op == '/') {
     out = l / r;
    }
else if(op == '*') {
        out = l * r;
    }
else{
        cout << "Invalid input";
        return 1;
    }

    cout << l << ' ' << op << ' ' << r << " = " << out;
    return 0;
}