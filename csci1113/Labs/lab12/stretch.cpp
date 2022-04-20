#include <iostream>
using namespace std;

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

};

ostream &operator<<(ostream &, complexNum &);
istream &operator>>(istream &, complexNum &);
complexNum operator+(complexNum &, complexNum &);
complexNum operator-(complexNum &);

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
    cout << "and negating the sum yields: " << -c3 << endl; 
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
    if(a.getImag() > 0){
        out << a.getReal() << " + " << a.getImag() << "i" << endl;
    }
    else{
        out << a.getReal() << " - " << a.getImag() << "i" << endl;
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

complexNum operator-(complexNum &a){
    return complexNum { -a.getReal(), -a.getImag()};
}