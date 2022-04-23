// Owen Swearingen
// Center of mass
#include <iostream>
#include <fstream>
using namespace std;

class PointMass
{
private:
    double loc[3];
    double mass;

public:
    PointMass();
    PointMass(double, double, double, double);
    double getX();
    double getY();
    double getZ();
    double getMass();
};

PointMass centerOfMass(PointMass* points, double numPoints);
ostream &operator<<(ostream &out, PointMass &a);

int main()
{

    ifstream infile;

    infile.open("pointMass.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    PointMass points[10];
    double numPoints = 0;
    infile >> numPoints;
    while (numPoints <= 0)// extra test in case negative or 0 points
    {
        infile >> numPoints;
    }
    for (size_t i = 0; i < numPoints; i++)
    {
        double x,y,z,mass;
        infile >> x >> y >> z >> mass;
        points[i] = PointMass(x,y,z,mass);
    }
    
    cout << "Location matrix: " << endl;
    for (size_t i = 0; i < numPoints; i++)
    {
            cout << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << endl;
    }

    cout << "Masses vector: " << endl;
    for (size_t i = 0; i < numPoints; i++)
    {
        cout << points[i].getMass() << endl;
    }
    cout << "N:\n" << numPoints << endl;
    
    PointMass COM = centerOfMass(points, numPoints);
    cout << "Center of Gravity: " << endl;
    cout << COM;

}


PointMass::PointMass()
{
    for (size_t i = 0; i < 3; i++)
    {
        loc[i] = 0;
    }
    mass = 0;
}

PointMass::PointMass(double x, double y, double z, double massval)
{
    loc[0] = x;
    loc[1] = y;
    loc[2] = z;
    mass = massval;
}

double PointMass::getX()
{
    return loc[0];
}
double PointMass::getY()
{
    return loc[1];
}
double PointMass::getZ()
{
    return loc[2];
}
double PointMass::getMass()
{
    return mass;
}

PointMass centerOfMass(PointMass* points, double numPoints){
    double numerator[3] = {0,0,0};
    double massSum = 0;

    for (size_t i = 0; i < numPoints; i++)
    {
        double x = points[i].getX();
        double y = points[i].getY();
        double z = points[i].getZ();
        double mass = points[i].getMass();

        numerator[0] += (x*mass);
        numerator[1] += (y*mass);
        numerator[2] += (z*mass);
        massSum += mass;
    }
    for (size_t i = 0; i < 3; i++)
    {
        numerator[i] = numerator[i] / massSum;
    }

    PointMass val = PointMass(numerator[0], numerator[1], numerator[2], massSum);
    return val;
    
}

ostream &operator<<(ostream &out, PointMass &a){
    out << a.getX() << " " << a.getY() << " " << a.getZ() ;
    return out;
}

//ifstream &operator>>(ifstream in, double x){}



