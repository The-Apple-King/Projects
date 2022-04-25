// Owen Swearingen
// Center of mass
#include <iostream>
#include <fstream>
using namespace std;

class PointMass
{
private:
    double loc[3]; // x, y, z
    double mass;// mass of point object

public:
    PointMass(); //default constructor
    PointMass(double, double, double, double); //constructor
    double getX(); //return x
    double getY(); //return y
    double getZ(); //return z
    double getMass(); // return mass
};

PointMass centerOfMass(PointMass* points, double numPoints); // takes an array of pointmass objects and finds center of mass
ostream &operator<<(ostream &out, PointMass &a); //outputs point objects
istream &operator>>(istream &l, PointMass &r); // inputs for point objects

int main()
{
    //create the ifstream and make sure it works
    ifstream infile;
    infile.open("pointMass.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    //create the array of pointMasses
    PointMass *points;
    int numPoints = 0;
    infile >> numPoints;
    while (numPoints <= 0)// extra test in case negative or 0 points
    {
        infile >> numPoints;
    }

    //creates puts data into the pointMass array
    points = new PointMass[numPoints];
    for (size_t i = 0; i < numPoints; i++)
    {
        infile >> points[i];
    }
    
    //output for location of pointMasses
    cout << "Location matrix: " << endl;
    for (size_t i = 0; i < numPoints; i++)
    {
            cout << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << endl;
    }

    //output for masses of each pointMass 
    cout << "Masses vector: " << endl;
    for (size_t i = 0; i < numPoints; i++)
    {
        cout << points[i].getMass() << endl;
    }
    //output for number of pointMasses
    cout << "N:\n" << numPoints << endl;
    
    //output for center of masses
    PointMass COM = centerOfMass(points, numPoints);
    cout << "Center of Gravity: " << endl;
    cout << COM;
}

/**
 * @brief Construct a new Point Mass:: Point Mass object
 * 
 */
PointMass::PointMass()
{
    for (size_t i = 0; i < 3; i++)
    {
        loc[i] = 0;
    }
    mass = 0;
}

/**
 * @brief Construct a new Point Mass:: Point Mass object
 * 
 * @param x x value
 * @param y y value
 * @param z z value
 * @param massval mass value
 */
PointMass::PointMass(double x, double y, double z, double massval)
{
    loc[0] = x;
    loc[1] = y;
    loc[2] = z;
    mass = massval;
}

/**
 * @brief returns x
 * 
 * @return double x val
 */
double PointMass::getX()
{
    return loc[0];
}

/**
 * @brief returns y
 * 
 * @return double y val
 */
double PointMass::getY()
{
    return loc[1];
}

/**
 * @brief returns z
 * 
 * @return double z val
 */
double PointMass::getZ()
{
    return loc[2];
}

/**
 * @brief returns mass
 * 
 * @return double mass val
 */
double PointMass::getMass()
{
    return mass;
}

/**
 * @brief finds the center of mass
 * 
 * @param points array of pointMass objects
 * @param numPoints the size of pointMass array
 * @return PointMass a pointmass of the center of the mass
 */
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

/**
 * @brief prints out pointMasses
 * 
 * @param out ostream
 * @param a the pointMass
 * @return ostream& the output
 */
ostream &operator<<(ostream &out, PointMass &a){
    out << a.getX() << " " << a.getY() << " " << a.getZ() ;
    return out;
}
/**
 * @brief takes input for point objects
 * 
 * @param l the istream
 * @param r the pointmass object
 * @return istream& the input for the pointmass object
 */
istream &operator>>(istream &l, PointMass &r) {
    double x,y,z,mass;
        l >> x >> y >> z >> mass;
        r = PointMass(x,y,z,mass);
        return l;
}



