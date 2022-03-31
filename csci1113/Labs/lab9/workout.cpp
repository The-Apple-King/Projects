#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double* randVec();
double* momentum(double *velocity, double mass);

int main()
{
    srand(time(0));
    
    double *vector = randVec();
    double **momentums = new double *[1000];

    for (size_t i = 0; i < 1000; i++)
    {
        *(momentums+i) = momentum(vector, (rand()%11));
    }
    

    double vector1, vector2, vector3 = 0;
    for (size_t i = 0; i < 1000; i++)
    {
        vector1 += *(*(momentums+i));
        vector2 += *(*(momentums+i)+1);
        vector3 += *(*(momentums+i)+2);
    }
    cout << "i: " << (vector1/1000);
    cout << "j: " << (vector2/1000);
    cout << "k: " << (vector3/1000);
    
    
}

double* randVec(){
    double *vector = new double[3];
    for (size_t i = 0; i < 3; i++)
    {
        *(vector+i) = (rand()%201)+100;
    }    
    return vector;
}


double* momentum(double *velocity, double mass){
    double *momentum = new double[3];
    for (size_t i = 0; i < 3; i++)
    {
        *(momentum+i) = *(velocity+i) * mass;
    }
    
    return momentum;
}