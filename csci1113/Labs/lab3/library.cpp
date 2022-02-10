#include <iostream>
using namespace std;

int main() {

	int books = 0;
    int users = 0;
    char loc = 0;
    int change = 0;
    cout << "Enter books: ";
    cin >> books;
    cout << "Enter users: ";
    cin >> users;
    cout << "Enter (R)ural or (U)rban: ";
    cin >> loc;
    if(toupper(loc) == 'R'){
        cout << (0.0039 * books + 0.0166 * users - 23.42) << " Staff Hours";
    }
    else if(toupper(loc) == 'U'){
        cout << (0.0026 * books + 0.0166 * users + 249.97) << " Staff Hours";
    }
    else{
        cout << "invalid character";
    }
    
}