#include "duck.cc"

class Canvasback:public Duck
{
private:
    /* data */
public:
    using Duck::Duck;
    Canvasback(/* args */);
    ~Canvasback();

    string quack();
    //“Quack!”
    string display();
//    “I am a Canvasback Duck!”
    string fly();
    //"I can fly!"
};

Canvasback::Canvasback(/* args */)
{
}

Canvasback::~Canvasback()
{
}

string Canvasback::quack()
{
    return "Quack!";
}

string Canvasback::display()
{
    return "I am a Canvasback Duck!";
}

string Canvasback::fly()
{
    return "I can fly!";
}
