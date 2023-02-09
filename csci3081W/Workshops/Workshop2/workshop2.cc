#include <iostream>
#include <vector>
using namespace::std;

class MotorizedVehicle
{
public:
    MotorizedVehicle(){};

    void throttle(){cout << "speeds up";}
    virtual void refuel(){cout << "refueling";}
    virtual void display(){cout << "I am a motorized vehicle";}
    virtual void brake(){cout << "slows down";}
};

class GasPowered:public MotorizedVehicle
{
public:
    GasPowered(){};

    void display(){cout << "I run on gas";}
};

class Hybrid:public MotorizedVehicle
{
public:
    Hybrid(){};

    void display(){cout << "I am a Hybrid";}
    void brake(){cout << "battery charges as car slows";}
};

class Electric:public MotorizedVehicle
{
public:
    Electric(){};

    void display(){cout << "I am an EV";}
    void brake(){cout << "battery charges as car slows";}
    void refuel(){cout << "EV is charging";}
};

    class Shape2D
    {
    protected:
        float width;
        float height;
    public:

        virtual float getArea() = 0;
    };
    

    class Triangle:public Shape2D
    {
    public:
        Triangle(float height, float width){
            this->height = height;
            this->width = width;
        }

        float getArea(){
            return (width*height/2);
        }
    };
    
    
    class Rectangle:public Shape2D
    {
    public:
        Rectangle(float height, float width){
            this->height = height;
            this->width = width;
        }

        float getArea(){
            return (width*height);
        }
    };
    
    
    class Circle:public Shape2D
    {
    public:
        Circle(float radius){
            this->height = radius;
        }

        float getArea(){
            return (3.141592*height*height);
        }
    };
    

int main(){
    vector<MotorizedVehicle *> cars;
    MotorizedVehicle *vehicle = new MotorizedVehicle();
    GasPowered *gas = new GasPowered();
    Hybrid *hybrid = new Hybrid();
    Electric *EV = new Electric();
    cars.push_back(vehicle);
    cars.push_back(gas);
    cars.push_back(hybrid);
    cars.push_back(EV);

    for (size_t i = 0; i < cars.size(); i++)
    {
        
        cars[i]->throttle();
        cout << endl;
        cars[i]->refuel();
        cout << endl;
        cars[i]->display();
        cout << endl;
        cars[i]->brake();
        cout << endl;
    }

    //Shape2D shape;

    Circle circle = Circle(3.0);
    Rectangle rectangle = Rectangle(2.0, 3.0);
    Triangle triangle = Triangle(5.0, 2.0);

    cout << circle.getArea() << endl;
    cout << rectangle.getArea() << endl;
    cout << triangle.getArea() << endl;

}