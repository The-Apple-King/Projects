// Owen Swearingen
//Homework 5A
//opens and closes mailboxes to output list of squares

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool testBox(bool opened);

int main(){
    bool mailboxes[151] = {false};
    
    //goes through and opens/closes mailboxes
    //loops the starting location/how many are skipped
    for (int place = 2; place < 151; place++)
    {  
        //cycles through all the mailboxes using place as a step value
        for (size_t i = place; i < 151; i+=place)
        {
           mailboxes[i] = testBox(mailboxes[i]);
        }
    }

    //cycles through and prints out the location of the mailbox
    for (size_t i = 1; i < 151; i++)
    {
        if (!mailboxes[i])
        {
            cout << i << " ";
        }
        
    }
    
    
}

/**
 * @brief changes the value of mailbox
 * 
 * @param opened value from mailboxes[]
 * @return true opened mailbox
 * @return false closed mailbox
 */
bool testBox(bool opened){
    return !opened;
}