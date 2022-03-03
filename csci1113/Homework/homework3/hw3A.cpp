#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double height(int, double);

/*
asks for velocity and outputs the height of the object
 at each point in time
*/
int main()
{
    int track;
    double velocity = 0;
    cout << "Enter initial Velocity: ";
    cin >> velocity;
    cout << "Projectile launched straight up at " << velocity << " m/s\n";
    cout << "Time \t Height\n";
    cout << std::fixed << std::setprecision(1);
    for (size_t i = 0; height(i, velocity) >= 0; i++)
    {
        cout << i << "\t" << height(i, velocity) << "\n";
        track = i;
    }
    if(height(track, velocity) > 0 && height((track+1), velocity) <= 0){
        cout << (track+1) << "\t" << "0.0" << "\n";
    }
}

//*************************************************
//finds the height given a time and original speed
//time is the amount of time that has passed
//velocity is the original speed
//*************************************************

double height(int time, double velocity)
{
    return (velocity * (double)time) - (.5 * 9.8 * (time * time));
}