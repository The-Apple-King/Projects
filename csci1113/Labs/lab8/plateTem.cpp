#include <cmath>
#include <iostream>

using namespace std;

#define NROWS 20
#define NCOLS 20

double promptDouble(const char *prompt) {
    cout << prompt;
    double out;
    cin >> out;
    return out;
}

void print2DArr(double (*arr)[NCOLS]) {
    bool flag = false;
    for (int i = 0; i < NROWS; i++) {
        if (!flag) {
            flag = true;
        } else {
            cout << ", " << endl;
        }
        bool flag2 = false;
        for (int j = 0; j < NCOLS; j++) {
            if (!flag2) {
                flag2 = true;
            } else {
                cout << ", ";
            }
            cout << arr[i][j];
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    auto old = new double[NROWS][NCOLS], temp = new double[NROWS][NCOLS];
    double top = promptDouble("Input the top temp: "),
           bottom = promptDouble("Input the bottom temp: "),
           left = promptDouble("Input the left temp: "),
           right = promptDouble("Input the right temp: "),
           center = promptDouble("Input the center temp: ");
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (i == 0) {
                old[i][j] = temp[i][j] = top;
            } else if (i == NROWS - 1) {
                old[i][j] = temp[i][j] = bottom;
            } else if (j == 0) {
                old[i][j] = temp[i][j] = left;
            } else if (j == NCOLS - 1) {
                old[i][j] = temp[i][j] = right;
            } else {
                old[i][j] = center;
            }
        }
    }

    double converge = promptDouble("Input the minuimum delta for convergence: ");

    print2DArr(old);
    cout << "---" << endl;

    bool steady;
    do {
        steady = true;
        for(int i = 1; i < NROWS - 1; i++) {
            for(int j = 1; j < NCOLS - 1; j++) {
                double d = (old[i-1][j] + old[i+1][j] + old[i][j-1] + old[i][j+1])/4.0;
                temp[i][j] = d;
                steady = steady && abs(d - old[i][j]) <= converge;
            }
        }
        
        for(int i = 1; i < NROWS - 1; i++) {
            for(int j = 1; j < NCOLS - 1; j++) {
                old[i][j] = temp[i][j];
            }
        }
    } while(!steady);
    print2DArr(old);
    return 0;
}