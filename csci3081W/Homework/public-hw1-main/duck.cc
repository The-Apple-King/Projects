#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
Part A

Prompt: We have given you specifications for a Duck class that has a few attributes (shown below).
Your job is to complete the Duck class and
finish the main method so that the ducks get ordered based on their coolness.
Hint: Look at C++ standard library sort function

DUCK:

variables:
1. name: string - the name of the duck
2. coolness: float - how cool the duck is (float from 1-10)
3. weight: double - average weight of the duck in pounds

functions:
1. default constructor
2. constructor with paramaters
3. getName: returns string
4. getCoolness: returns float
5. getWeight: returns double
*/



/**
Part B

Add the big three to your Duck class: destructor, copy constructor, copy assignment operator.
Add comments explaining what each one does, 
how they differ from one other, 
and differences between each of these and the default constructor.
*/



/**
Part C

We will now refactor our Duck class to be an abstract parent class (Duck) with child classes (Mallard, Canvasback, and Rubber).
    Each class should be its own file (duck.cc, mallard.cc, canvasback.cc, and rubber.cc)
The parent class will have the following pure virtual methods added:
    quack: void
    display: void
    swim: void
    fly: void
The child classes have the following behavior:
    Mallard
        quack: prints “Quack!”
        display: prints “I am a Mallard Duck!”
        swim: prints “I can swim!”
        fly: prints “I can fly!”
    Canvasback
        quack: prints “Quack!”
        display: prints “I am a Canvasback Duck!”
        swim: prints “I can swim!”
        fly: prints “I can fly!”
    Rubber
        quack: prints “Squeak!”
        display: prints “I am a Rubber Duck!”
        swim: prints “I can swim!”
        fly: prints “I can’t fly!”
1. One of these four added functions can be refactored such that it is not pure virtual anymore. Refactor that function accordingly.
2. Create an instance of each of the children classes in the main function.
3. You'll also have to comment out the ducks vector, all the push_backs, and sort from part A.
Why?
[Response here]
*/

/**
Part D

Create five functions that take in two ducks and output something. 
You get to define the functions however you want. 
Feel free to add new variables to the ducks in order to complete wanted functionality. 
In addition to writing the code, comments are required. 
Comments should not only detail the logic behind the code, 
but also explain how the different classes and methods interact to create an interesting experience. 
In the main method, demonstrate each one of your five functions in action.
This is your chance to have fun!

*/

// TODO part A: Duck class goes here
// TODO part B: add the big three
// TODO part C: refactor Duck class and create a few new classes (separate files)
// TODO part D: 5 added functions and corresponding comments go here (or in your child class files depending on how you want to implement it)


class duck
{
private:
    string name;
    float coolness;
    double weight;
public:
    duck();
    duck(string, float, double);
    duck(const duck&); //creates a copy of a duck object
    duck& operator=(const duck&){}//sets a duck equal to another duck
    ~duck();    //can be called to deallocate data 
    

    string getName();
    float getCoolness();
    double getWeight();
};

duck::duck()
{
    this->name = "NA";
    this->coolness = 0;
    this->weight = 0;
}

duck::duck(string name, float coolness, double weight)
{
    this->name = name;
    this->coolness = coolness;
    this->weight = weight;
}

string duck::getName(){
    return this->name;
}

float duck::getCoolness(){
    return coolness;
}

double duck::getWeight(){
    return weight;
}

duck::~duck()
{
}
