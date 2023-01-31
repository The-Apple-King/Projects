#include <iostream>
#include <string>
#include <vector>

#include "duck.cc"

int main()
{
    std::vector<Duck> ducks;
    ducks.push_back(Duck(std::string("Fulvous Whistling Duck"), 8.6f, 1.6d));
    ducks.push_back(Duck(std::string("Domestic Duck"), 2.5f, 2.5d));
    ducks.push_back(Duck(std::string("CanvasBack"), 5.8f, 2.7d));
    ducks.push_back(Duck(std::string("Loon"), 10.0f, 10.0d));
    ducks.push_back(Duck(std::string("Mallard"), 7.6f, 2.5d));

    // TODO part A: sort the ducks based on coolness
    // Note: You may want to double check your work here by printing to standard output

    // TODO part C: Create an instance of each of the children classes in the main function.
    // TODO part C: Comment out the ducks vector, all the push_backs, and sort from part A.
    
    // TODO part D: Demonstrate each one of your five defined functions.
    
    return 0;
}
