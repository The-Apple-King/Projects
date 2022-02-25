#include <iostream>
#include <string>
using namespace std;

int height(int time, int velocity);

int main()
{

    double velocity = 60;

    cout << " projectile launched straight up at " << velocity << " m/s";
    cout << "Time \t\t Height";
    for (size_t i = 0; height(i, velocity) >= 0; i++)
    {
        cout << i << "\t\t" << height(i, velocity);
    }
}

int height(int time, double velocity)
{
    return (velocity * time) - (.5 * 9.8 * (time * time));
}