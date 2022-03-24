#include <iostream>
using namespace std;

const int NROWS = 20;
const int NCOLS = 20;

void display(double temp[NCOLS][NROWS]);
bool converge(double old[NCOLS][NROWS], double temp[NCOLS][NROWS], double convergence);

int main()
{
    double old[NCOLS][NROWS];
    double temp[NCOLS][NROWS];
    double heat;

    cout << "top?";
    cin >> heat;
    for (size_t i = 0; i < NCOLS; i++)
    {
        temp[i][0] = heat;
    }
    cout << "bottom?";
    cin >> heat;
    for (size_t i = 0; i < NCOLS; i++)
    {
        temp[i][NROWS - 1] = heat;
    }
    cout << "left?";
    cin >> heat;
    for (size_t i = 1; i < NROWS - 1; i++)
    {
        temp[0][i] = heat;
    }
    cout << "right?";
    cin >> heat;
    for (size_t i = 1; i < NROWS - 1; i++)
    {
        temp[NCOLS - 1][i] = heat;
    }

    cout << "enter starting temp of the plate";
    cin >> heat;
    for (size_t i = 1; i < NROWS - 1; i++)
    {
        for (size_t j = 1; j < NCOLS - 1; j++)
        {
            temp[j][i] = heat;
        }
    }

    display(temp);

    double convergence;

    cout << "convergence?";
    cin >> convergence;

    for (size_t i = 0; i < NROWS; i++)
    {
        for (size_t j = 0; j < NCOLS; j++)
        {
            old[j][i] = temp[j][i];
        }
    }

    int counter = 0;
    while (!converge(old, temp, convergence))
    {
        for (size_t i = 0; i < NROWS; i++)
        {
            for (size_t j = 0; j < NCOLS; j++)
            {
                old[j][i] = temp[j][i];
            }
        }
        counter++;
    }
    display(temp);
    cout << counter;
}

/**
 * @brief prints out array
 *
 * @param temp array to print
 */
void display(double temp[NCOLS][NROWS])
{
    for (size_t i = 0; i < NROWS; i++)
    {
        for (size_t j = 0; j < NCOLS; j++)
        {
            cout << temp[j][i] << " ";
        }
        cout << "\n";
    }
}



bool converge(double old[NCOLS][NROWS], double temp[NCOLS][NROWS], double convergence)
{
    bool steady = true;
    for (size_t i = 1; i < NROWS - 1; i++)
    {
        for (size_t j = 1; j < NCOLS - 1; j++)
        {
            temp[j][i] = .25 * ((old[j - 1][i] + old[j + 1][i] + old[j][i - 1] + old[j][i + 1]) / 4);
            if (temp[j][i] - old[j][i] > convergence)
            {
                steady = false;
            }
        }
    }
    return steady;
}