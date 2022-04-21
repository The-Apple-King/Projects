#include <iostream>
using namespace std;
#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

class complexNum {
private:
    double real;
    double imag;

public:
    complexNum();
    complexNum(double, double);
    void input(istream&);
    void output(ostream&);
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);
    void operator-();

};

ostream &operator<<(ostream &, complexNum &);
istream &operator>>(istream &, complexNum &);
complexNum operator+(complexNum &, complexNum &);

#endif