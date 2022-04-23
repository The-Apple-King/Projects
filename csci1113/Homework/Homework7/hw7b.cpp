// Owen Swearingen
// Center of mass
#include <iostream>
using namespace std;

class PointMass
{
private:
    int loc[3];
    int mass;

public:
    PointMass();
    PointMass(int, int, int, int);
    int getX();
    int getY();
    int getZ();
    int getMass();
};

PointMass::PointMass()
{
    for (size_t i = 0; i < 3; i++)
    {
        loc[i] = 0;
    }
    mass = 0;
}

PointMass::PointMass(int x, int y, int z, int massval)
{
    loc[0] = x;
    loc[1] = y;
    loc[2] = z;
    mass = massval;
}

int PointMass::getX()
{
    return loc[0];
}
int PointMass::getY()
{
    return loc[1];
}
int PointMass::getZ()
{
    return loc[2];
}
int PointMass::getMass()
{
    return mass;
}

int* centerOfMass(PointMass* points, int numPoints){
    int *numerator = new int[3];
    for (size_t i = 0; i < 3; i++)
    {
        numerator[i] = 0;
    }
    
    int massSum = 0;
    for (size_t i = 0; i < numPoints; i++)
    {
        int x = points[i].getX();
        int y = points[i].getY();
        int z = points[i].getZ();
        int mass = points[i].getMass();

        numerator[0] = (x*mass);
        numerator[1] = (y*mass);
        numerator[2] = (z*mass);
        massSum += mass;
    }
    for (size_t i = 0; i < 3; i++)
    {
        numerator[i]/=massSum;
    }
    return numerator;
}

int main()
{

    PointMass *points;
    int numPoints = 0;
    cout << "gimme the shit";
    cin >> numPoints;
    while (numPoints <= 0)
    {
        cout << "enter a number bigger than 0";
        cout << "gimme the shit";
        cin >> numPoints;
    }
    for (size_t i = 0; i < numPoints; i++)
    {
        int x,y,z,mass;
        cin >> x >> y >> z >> mass;
        points[i] = PointMass(x,y,z,mass);
    }
    int *COM = centerOfMass(points, numPoints);
    
    cout << "idk what you want";

}

