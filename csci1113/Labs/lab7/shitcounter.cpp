#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    string sentence = "";
    int caps = 0;
    int low = 0;
    int alph = 0;
    int nums = 0;
    int punct = 0;
    int whitespace = 0;

    infile.open("C:/Users/gifte/Documents/projects/csci1113/Labs/lab7/GettysburgAddress.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    while (infile >> sentence)
    {
        whitespace++;
        for (size_t i = 0; i < sentence.length(); i++)
        {
            char c = sentence[i];
             if (isalpha(c))
            {
                alph++;
                if(isupper(c)){
                    caps++;
                }
                else{
                    low++;
                }
            }
            else if(isdigit(c))
            {
                nums++;
            }
            else if(ispunct(c)){
                punct++;
            }
        }
    }
    cout << "Alphabetic characters: " << alph << "\n";
    cout << "Uppercase characters: " << caps << "\n";
    cout << "Lowercase characters: " << low << "\n";
    cout << "punctuation characters: " << punct << "\n";
    cout << "whitespace characters: " << whitespace << "\n";
    infile.close();
}
