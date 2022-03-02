#include <iostream>
#include <string>
using namespace std;

int sim(double throws);

int main(){
    double hits = 0;
    double throws = 10000;
    hits = sim(throws);
    cout << "Pi is approximately:  " <<(double(hits/throws))*4;
}

int sim(double throws){
    double x = 0;
    double y = 0;
    double hits = 0;
    while(hits/throws <10e-3)
    {
        x = (rand()%1000)/1000;
        y = (rand()%1000)/1000;
        if ((x*x)+(y*y) <= 1){
            hits++;
        }
    }
    return hits;
}