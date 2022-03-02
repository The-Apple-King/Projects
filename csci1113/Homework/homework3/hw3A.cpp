#include <iostream>
#include <string>
using namespace std;

int height(int, double);

int main()
{

    double velocity;
    cin >> velocity;
    cout << " projectile launched straight up at " << velocity << "m/s\n";
    cout << "Time \t Height\n";
    for (size_t i = 0; height(i, velocity) >= 0; i++)
    {
        cout << i << "\t" << height(i, velocity) << "\n";
    }
}

//*************************************************
//finds the height given a time and original speed
//time is the amount of time that has passed
//velocity is the original speed
//*************************************************

int height(int time, double velocity)
{
    return double((velocity * time) - (.5 * 9.8 * (time * time)));
}