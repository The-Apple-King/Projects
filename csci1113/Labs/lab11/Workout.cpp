#include <iostream>
using namespace std;

class complexNum {
private:
	double real;
    double imag;

public:
	void input(istream&);
    void output(ostream&);
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);

};

int main(){
    complexNum c1 = complexNum();
    complexNum c2 = complexNum();

    c1.input(cin);
    c2.input(cin);

    c1.output(cout);
    c2.output(cout);

    c2.setReal(22.2);
    c2.getReal();
    c2.output(cout);
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
    outstream << getReal() << " + " << getImag() << "i" << endl;
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