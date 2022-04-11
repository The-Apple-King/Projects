#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int* letters = new int [26];
    char vals[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (size_t i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }
    
    getline(cin, line);
    
    for (size_t i = 0; i < line.length(); i++)
    {
        if(isalpha(line[i])){
            letters[(toupper(line[i])-65)]++;
        }
    }
    
    for (size_t i = 0; i < 26; i++)
    {
        if(letters[i] != 0){
            cout << vals[i] << " " << letters[i] << endl;
        }
    }
    
    return 0;
}
