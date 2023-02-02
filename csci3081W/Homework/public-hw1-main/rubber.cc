#include "duck.cc"


class Rubber:public Duck
{
private:
    /* data */
public:
    using Duck::Duck;
    Rubber(/* args */);
    ~Rubber();
    string quack();
    string display();
    string swim();
    string fly();
};

Rubber::Rubber(/* args */)
{
}

Rubber::~Rubber()
{
}

string Rubber::quack()
{
    return "Squeak!";
}

string Rubber::display()
{
    return "I am a Rubber Duck!";
}

string Rubber::fly()
{
    return "I can't fly!";
}

