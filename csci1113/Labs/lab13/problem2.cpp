#include <iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

class Array
{
public:
    Array(int = 10);                 // default constructor, since by value
    ~Array();                        // destructor used to deallocate memory
    Array &operator=(const Array &); // assignment operator
    Array(const Array &);
    void display(ostream&);
    void read(istream&);

private:
    int size; // number of elements in the array
    int *ptr; // pointer to the first element in the array
};

#endif

Array::Array(int size)
{
    this->size = size;
    ptr = new int[size];
}

Array::Array(const Array &toCopy)
{
        this->size = toCopy.size;
        this->ptr = new int[size];
        for (size_t i = 0; i < toCopy.size; i++)
        {
            this->ptr[i] = toCopy.ptr[i];
        }
}

Array::~Array()
{
    delete ptr;
}

Array &Array::operator=(const Array &toCopy)
{
    if (this->ptr != toCopy.ptr)
    {
        delete[] this->ptr;
        this->size = toCopy.size;
        this->ptr = new int[size];
        for (size_t i = 0; i < toCopy.size; i++)
        {
            this->ptr[i] = toCopy.ptr[i];
        }
    }
    return *this;
}

void Array::display(ostream &out){
    for (size_t i = 0; i < size-1; i++)
    {
        string str = ptr[i] + ", ";
        out << str;
    }
    out << ptr[size];
}

void Array::read(istream &in){
    in >> size;
    for (size_t i = 0; i < size; i++)
    {
        in >> ptr[i];
    }
    
}

istream &operator>>(istream &in,Array &val)
{
    val.read(in);
    return in;
}

ostream &operator<<(ostream &out,Array &val){
    val.display(out);
    return out;
}

int main(){
    Array a1;
    cin >>  a1;
    cout << a1;
}