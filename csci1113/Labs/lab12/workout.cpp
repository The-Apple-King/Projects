#include <iostream>
#include <cmath>
#include "stretch.cpp"
using namespace std;

class Poly
{
private:
    double a, b, c;

public:
    Poly();
    Poly(double, double, double);
    double eval(double);
    double getA();
    double getB();
    double getC();
    void setA(double);
    void setB(double);
    void setC(double);
    void roots(complexNum &, complexNum &);
};
Poly::Poly()
{
    a = 0;
    b = 0;
    c = 0;
}

Poly::Poly(double j, double k, double l)
{
    a = j;
    b = k;
    c = l;
}

double Poly::eval(double x)
{
    return (a * (x * x)) + (b * x) + c;
}

void Poly::roots(complexNum &plus, complexNum &minus)
{
    if ((b * b) - (4 * a * c) < 0)
    {
        double real = -b / (2 * a), imag = sqrt((4 * a * c) - (b * b)) / (2 * a);
        plus.setReal(real);
        plus.setImag(imag);
        minus.setReal(real);
        minus.setImag(-imag);
    }
    else
    {
        plus.setReal((-b + (sqrt((b * b) - (4 * a * c)))) / (2 * a));
        minus.setReal((-b - (sqrt((b * b) - (4 * a * c)))) / (2 * a));
        plus.setImag(0);
        minus.setImag(0);
    }
}

void Poly::setA(double val)
{
    a = val;
}

void Poly::setB(double val)
{
    b = val;
}

void Poly::setC(double val)
{
    c = val;
}

double Poly::getA()
{
    return a;
}

double Poly::getB()
{
    return b;
}

double Poly::getC()
{
    return c;
}

Poly operator+(Poly &a, Poly &b)
{
    return Poly{(a.getA() + b.getA()), (a.getB() + b.getB()), (a.getB() + b.getB())};
}

ostream &operator<<(ostream &out, Poly &a)
{
    if (a.getA() < 0)
    {
        out << a.getA() << "X^2 ";
    }
    else if (a.getA() > 0)
    {
        out << a.getA() << "X^2 ";
    }
    if (a.getB() < 0)
    {
        out << a.getB() << "X ";
    }
    else if (a.getB() > 0)
    {
        out << "+" << a.getB() << "X ";
    }
    if (a.getC() < 0)
    {
        out << a.getC();
    }
    else if (a.getC() > 0)
    {
        out << "+" << a.getC();
    }
    return out;
}

istream &operator>>(istream &in, Poly &a)
{
    double a1, b, c;
    cout << "enter a b c: ";
    in >> a1 >> b >> c;
    a = Poly(a1, b, c);
    return in;
}

int main()
{

    // part 1
    Poly q1 = Poly(3, 4, -2);
    Poly q2 = Poly(0, -4, 10);
    Poly sum = Poly(0, 0, 0);
    sum = q1 + q2;
    cout << q1 << " : q1\n";
    cout << q2 << " : q2\n";
    cout << sum << " : q1+q2\n";

    /*//part 2
    Poly  inpoly;
    cout << "Input a quadratic polynomial: ";
    cin >> inpoly;
    for( int i=0; i<= 10; i++)
        cout << "f(" << i << ") is: "
             << inpoly.eval(i) << endl;
    complexNum c1,c2;
    inpoly.roots(c1,c2);
    cout << "The roots of f(x) are " << c1 << "\t" << c2 << endl;*/
}