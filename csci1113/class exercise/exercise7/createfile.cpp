#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    ofstream outfile;

    outfile.open("C:/Users/gifte/Documents/projects/csci1113/class exercise/exercise7/numbers.txt");
    srand(time(NULL));
    for (size_t i = 0; i < 101; i++)
    {
        outfile << rand()%100 << "\n";
    }
    
    outfile.close();
}
