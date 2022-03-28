#include <iostream>
using namespace std;

bool End(char game[3][3]);
void turn(char game[3][3], bool xTurn);
void fill(char game[3][3], char c);
void display(char game[][3]);
int turns = 0;

int main()
{
    char game[3][3];
    fill(game, '-');
    int x, y;

    while (!End(game))
    {
        turns++;
        if(turns%2 ==1){
            turn(game, true);
        }
        else{
            turn(game, false);
        }
        display(game);
    }
}

bool End(char game[3][3])
{
    if (turns >= 9)
    {
        cout << "draw";
        return true;
    }
    else
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (game[i][0] != '-' && game[i][0] == game[i][1] && game[i][1] == game[i][2])
            {
                cout << game[i][0] << " wins";
                return true;
            }
            else if (game[0][i] != '-' && game[0][i] == game[1][i] && game[1][i] == game[2][i])
            {
                cout << game[0][i] << " wins";
                return true;
            }
        }
        if (game[1][1] != '-' && (game[0][0] == game[1][1] && game[0][0] == game[2][2] || game[2][0] == game[1][1] && game[2][0] == game[0][2]))
            {
                cout << game[1][1] << " wins";
                return true;
            }
    }
    return false;
}

void turn(char game[][3], bool xTurn)
{
    int x, y;
    char player = 'O';
    if (xTurn)
    {
        player = 'X';
    }
    cout << player << "'s turn\n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    while (game[x][y] != '-')
    {
        cout << "invalid location \n";
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
    }
    game[x][y] = player;
}

void fill(char game[][3], char c){
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            game[i][j] = '-';
        }
    }
}


/**
 * @brief prints out array
 *
 * @param game array to print
 */
void display(char game[3][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << game[j][i] << " ";
        }
        cout << "\n";
    }
}