#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

    int white[70] = {0};
    int red[27] = {0};

    ifstream infile;
    int num;
    infile.open("C:/Users/gifte/Documents/projects/csci1113/Labs/lab8/winning_numbers.txt");
    if (!infile)
    {
        cout << "Error opening the file.";
    }

    string temp = "";
    infile >> temp >> temp >> temp >> temp >> temp;
    while (infile >> temp)
    { // Read a name from the file
        for (size_t i = 0; i < 5; i++)
        {
            infile >> num;
            white[num]++;
        }
        infile >> num;
        red[num]++;
        infile >> temp >> temp;


    }
    infile.close(); // Close the file

    ofstream outfile;
    outfile.open("C:/Users/gifte/Documents/projects/csci1113/Labs/lab8/frequency.txt");
    outfile << "White Ball Frequency: \n";
    for (size_t i = 1; i < 70; i++)
    {
        outfile << i << ": " << white[i] << "\n";
    }

    outfile << "Powe Ball Frequency: \n";
    for (size_t i = 1; i < 27; i++)
    {
        outfile << i << ": " << red[i] << "\n";
    }
    
    
    outfile.close();
    return 0;
}