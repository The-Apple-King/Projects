#include <iomanip>

bool End(char game[3][3]);

int main(){
    char game [3][3];
    bool xTurn = true

    while (!End(game))
    {
        if(xTurn){
            cout << "x's turn";
            cout << "x";
            int x, y;
            cin >> x;
            cin >> y;
            game[x][y] = 'x';
        }
    }
    

}