#ifndef DUCK_CC
#define DUCK_CC

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
Part A

Prompt: We have given you specifications for a Duck class that has a few attributes (shown below).
Your job is to complete the Duck class and
finish the main method so that the Ducks get ordered based on their coolness.
Hint: Look at C++ standard library sort function

Duck:

variables:
1. name: string - the name of the Duck
2. coolness: float - how cool the Duck is (float from 1-10)
3. weight: double - average weight of the Duck in pounds

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
    Each class should be its own file (Duck.cc, mallard.cc, canvasback.cc, and rubber.cc)
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
3. You'll also have to comment out the Ducks vector, all the push_backs, and sort from part A.
Why?
[Response here]
*/

/**
Part D

Create five functions that take in two Ducks and output something.
You get to define the functions however you want.
Feel free to add new variables to the Ducks in order to complete wanted functionality.
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

class Duck
{
private:
    string name;
    float coolness;
    double weight;

public:
    Duck();
    Duck(string, float, double);
    Duck(const Duck &);            // creates a copy of a Duck object
    Duck &operator=(const Duck &); // sets a Duck equal to another Duck
    ~Duck();                       // can be called to deallocate data

    string getName();
    float getCoolness();
    bool compareCoolness(Duck, Duck);               // 1
    bool compareWeight(Duck, Duck);                 // 2
    void fightToTheDeath(Duck &duck1, Duck &duck2); // 3
    bool compareName(Duck, Duck);                   // 4
    void lemonade(Duck duck1, Duck duck2);          // 5
    double getWeight();

    string swim();
};

Duck::Duck()
{
    this->name = "NA";
    this->coolness = 0;
    this->weight = 0;
}

Duck::Duck(string name, float coolness, double weight)
{
    this->name = name;
    this->coolness = coolness;
    this->weight = weight;
}

Duck &Duck::operator=(const Duck &d)
{
    this->name = d.name;
    this->weight = d.weight;
    this->coolness = d.coolness;
    return *this;
}

Duck::Duck(const Duck &d)
{
    this->name = d.name;
    this->weight = d.weight;
    this->coolness = d.coolness;
}

string Duck::getName()
{
    return this->name;
}

float Duck::getCoolness()
{
    return coolness;
}

/**
 * @brief compares two ducks coolness and returns true if duck 1 is not as cool
 *
 * @param duck1 first duck
 * @param duck2 second duck
 * @return true if first has a smaller coolness
 * @return false if first has a bigger coolness
 */
bool Duck::compareCoolness(Duck duck1, Duck duck2)
{
    return (duck1.getCoolness() < duck2.getCoolness());
}

bool Duck::compareWeight(Duck duck1, Duck duck2)
{
    return (duck1.getWeight() < duck2.getWeight());
}

/**
 * @brief two ducks enter 1 duck leaves
 * 
 * pass by reference so we can deallocate the duck that loses
 * 
 * @param duck1 first duck
 * @param duck2 second duck
 * @return Duck* winning duck
 */
void Duck::fightToTheDeath(Duck &duck1, Duck &duck2)
{
    //allows to check for the winner and loser
    bool duck1win = false;
    bool duck2win = false;

    //compare each weight if both equal they both come out false
    duck1win = !compareWeight(duck1, duck2);
    duck2win = compareWeight(duck1, duck2);

    //if they are the same weight, test coolness
    if (duck1win == duck2win)
    {
        duck1win = !compareCoolness(duck1, duck2);
        duck2win = compareCoolness(duck1, duck2);
    }

    //if they have same weight and coolness it comes to random chance
    if (duck1win == duck2win)
    {
        int chance = rand()%2;
        switch (chance)
        {
        case 0:
            duck1win = true;
            break;
        
        default:
        duck2win = true;
            break;
        }
    }
    
    
    //output
    if (duck1win)
    {
        cout << duck1.getName() << " wins, " << duck2.getName() << " has perished" << endl;
        duck2.~Duck();
    }
    else{
        cout << duck2.getName() << " wins, " << duck1.getName() << " has perished" << endl;
        duck1.~Duck();
    }
}

bool Duck::compareName(Duck duck1, Duck duck2)
{
    if (duck1.getName() < duck2.getName())
    {
        return true;
    }
    return false;
}

void Duck::lemonade(Duck duck1, Duck duck2)
{
    cout << "the duck walked up to the lemonade stand and said to the other duck running the stand" << endl;
    cout << duck1.quack() << " (hey) " << endl;
    cout << duck1.quack() << " " <<duck1.quack() << " " << duck1.quack() << endl;
    cout << "(got any grapes?)" << endl;

    cout << duck2.getName() << " said: " << duck2.quack() << " (No.)";
    {
        cout << duck2.quack();
    }
    cout << endl <<" (We just have lemonade.)"
    
}

double Duck::getWeight()
{
    return weight;
}

string Duck::swim()
{
    return "I can swim!";
}

Duck::~Duck()
{
}

#endif