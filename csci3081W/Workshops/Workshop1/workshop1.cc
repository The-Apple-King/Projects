#include <iostream>
#include <string.h>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    string input;           //stores the full domain
    string core;            //stores the gTLD
    int loc_first_period;   //stores the first instance of a period
    bool works = false;     //flag to test if the core is a gTLD

    //first prompt
    cout << "Enter a core gTLD (press q to quit)" << endl;
    cin >> input;

    //program loop
    while (input != "q") // while the user does not input q
    {
        if(input.find('.')) //find the first .
        {
            loc_first_period = input.find('.'); //set the location of the first .
            if (loc_first_period <= input.size()-3 && loc_first_period >= input.size()-5) //makes sure the first . is at the end
            {
                core = input.substr(loc_first_period); //takes the last few chars after the first .

                // checks if core == any one of these gTLD then sets the works flag to true
                if (core == ".com")
                {
                    works = true;
                }
                if (core == ".org")
                {
                    works = true;
                }
                if (core == ".net")
                {
                    works = true;
                }
                if (core == ".info")
                {
                    works = true;
                }
            }
            
        }

        //depending on works flag outputs the correct response
        if(works){
            cout << input << " is a second-level domain followed by a core gTLD of " << core << endl;
            works = 0;
        }
        else{
            cout << input << " is not a second-level domain followed by a core gTLD" << endl;
        }

        //asks for next round of input
        cout << "Enter the next domain name (or Type q to exit): ";
        cin >> input;
    }
    


    return 0;
}