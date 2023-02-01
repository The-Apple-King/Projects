#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "duck.cc"
#include "rubber.cc"
#include "mallard.cc"
#include "canvasback.cc"

using namespace std;

int main()
{
    //std::vector<Duck> ducks;
    // ducks.push_back(Duck(std::string("Fulvous Whistling Duck"), 8.6f, 1.6d));
    // ducks.push_back(Duck(std::string("Domestic Duck"), 2.5f, 2.5d));
    // ducks.push_back(Duck(std::string("CanvasBack"), 5.8f, 2.7d));
    // ducks.push_back(Duck(std::string("Loon"), 10.0f, 10.0d));
    // ducks.push_back(Duck(std::string("Mallard"), 7.6f, 2.5d));

    Mallard mallard = Mallard("Mallard", 7.6f, 2.5d);
    Canvasback canvas = Canvasback("CanvasBack", 5.8f, 2.7d);
    Rubber duckie = Rubber("The best Kind of Duck", 1000.0f, 10.0d);

    // TODO part A: sort the ducks based on coolness
    // Note: You may want to double check your work here by printing to standard output

    //sort(ducks.begin(), ducks.end(), compareCoolness);// sorts ducks based on coolness
    

    // TODO part C: Create an instance of each of the children classes in the main function.
    // TODO part C: Comment out the ducks vector, all the push_backs, and sort from part A.
    
    // TODO part D: Demonstrate each one of your five defined functions.

    // compares the coolness of two ducks and returns true if the first duck has a lower coolness
    Duck.compareCoolness(canvas, duckie);

    //compares the weights of two ducks and returns true if the first duck is lighter
    if(Duck.compareWeight(mallard, canvas)){
        cout << canvas.getName() << "is the biggest duck" << endl;
    }
    else{
        cout << mallard.getName() << "is the biggest duck" << endl;
    }

    //have two ducks fight and see who would win, uses type then weight to determine winner
    Duck.fightToTheDeath(mallard, canvas);
    
    return 0;
}
