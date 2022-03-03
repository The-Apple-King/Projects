#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    int num;
    infile.open("pb_2021.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    int tempi;
    char tempc;
    outfile.open("pb_20212.txt");

    while (infile >> tempi >> tempc >> tempi >> tempc >> tempi)
    { // Read a name from the file
        for(int i = 0; i < 6; i++){
            int num;
            infile >> num;
            outfile << num << " ";
        }
        outfile << "\n";
        infile >> tempc >> tempc >>tempc;
    }
    infile.close(); // Close the file
    outfile.close();
}
