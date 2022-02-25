#include <iostream>
#include <string>
using namespace std;

int sim(int throws);

int main(){
    int hits = 0;
    int throws = 10000;
    hits = sim(throws);
    cout << "Pi is approximately:  " <<(double(hits/throws));
}

int sim(int throws){
    double x = 0;
    double y = 0;
    int hits = 0;
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