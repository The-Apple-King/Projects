#include <iostream>
#include "stretch.h"
using namespace std;



complexNum::complexNum(){
    real = 0;
    imag = 0;
}

complexNum::complexNum(double a, double b){
    real = a;
    imag = b;
}

int main(){
    complexNum c1,c2,c3; 
    cout << "Enter two complex values: "; 
    cin >> c1 >> c2; 
    c3 = c1+c2; 
    cout << "The sum is: " << c3 << endl; 
    -c3;
    cout << "and negating the sum yields: " << c3 << endl;
}

void complexNum::input(istream& instream){
    double temp;
    cout << "enter real number: ";
    instream >> temp;
    setReal(temp);
    cout << "enter imaginary number: ";
    instream >> temp;
    setImag(temp);
}

void complexNum::output(ostream& outstream){
    if(getImag() > 0){
        outstream << getReal() << " + " << getImag() << "i" << endl;
    }
    else{
        outstream << getReal() << " - " << getImag() << "i" << endl;
    }
}

ostream &operator<<(ostream &out, complexNum &a){
    bool test = false;
    bool test2 = false;
    if(a.getReal() != 0){
        out << a.getReal();
        test = true;
    }
    if(a.getImag() > 0){
        if(test){
            out << " + ";
        }
        out << a.getImag() << "i" << endl;
        test2 = true;
    }
    else if(a.getImag() < 0){
        out << " - " << a.getImag() << "i" << endl;
        test2 = true;
    }
    if (!test && !test2)
    {
        out << 0;
    }
    
    return out;
}

istream &operator>>(istream &in, complexNum &a){
    double temp;
    cout << "enter real number: ";
    in >> temp;
    a.setReal(temp);
    cout << "enter imaginary number: ";
    in >> temp;
    a.setImag(temp);
    return in;
}

double complexNum::getReal(){
    return real;
}

double complexNum::getImag(){
    return imag;
}

void complexNum::setReal(double realval){
    real = realval;
}

void complexNum::setImag(double imagval){
    imag = imagval;
}

complexNum operator+(complexNum &a, complexNum &b){
    return complexNum { (a.getReal() + b.getReal()), (a.getImag() + b.getImag())};
}

void complexNum::operator-() {
    real = -real;
    imag = - imag;
}