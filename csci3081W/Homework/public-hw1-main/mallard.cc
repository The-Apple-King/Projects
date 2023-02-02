#include "duck.cc"

class Mallard: public Duck
{
private:
    /* data */
public:

    using Duck::Duck;
    Mallard(/* args */);
    ~Mallard();

    string quack();
    //“Quack!”
    string display();
//    “I am a Mallard Duck!”
    string fly();
    //"I can fly!"
};

Mallard::Mallard(/* args */)
{
}

Mallard::~Mallard()
{
}

string Mallard::quack()
{
    return "Quack!";
}

string Mallard::display()
{
    return "I am a Mallard Duck!";
}

string Mallard::fly()
{
    return "I can fly!";
}
