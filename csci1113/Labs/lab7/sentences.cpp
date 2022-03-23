#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    string sentence = "";

    infile.open("C:/Users/gifte/Documents/projects/csci1113/Labs/lab7/sentences.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    while (infile >> sentence)
    {
        for (size_t i = 0; i < sentence.length(); i++)
        {
            char c = sentence[i];
            if (c == toupper(c))
            {
                c = tolower(c);
                cout << c;
            }
            else
            {
                c = toupper(c);
                cout << c;
            }
        }
        cout << "\n";
    }
    infile.close();
}
