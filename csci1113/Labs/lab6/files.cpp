#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void createfile();
int min();
int max();
int average();

int main()
{
    srand(time(0));
    int pause;
    createfile();
    cout << "min is " << min() << endl;
    cout << "max is " << max() << endl;
    cout << "average is " << average() << endl;
    cin >> pause;
}

void createfile()
{
    int numbers;
    ofstream outfile;
    outfile.open("numbers.txt");
    numbers = (rand() % 60) + 40;
    for (size_t i = 0; i < numbers; i++)
    {
        outfile << ((rand() % 499)+1) << "\n";
    }
    outfile.close();
}

int min()
{
    ifstream infile;
    int num;
    infile.open("numbers.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    int min = INT_MAX;
    while (infile >> num)
    { // Read a name from the file
        if (min > num)
        {
            min = num;
        }
    }
    infile.close(); // Close the file
    return min;
}

int max()
{
    ifstream infile;
    int num;
    infile.open("numbers.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    int max = INT_MIN;
    while (infile >> num)
    { // Read a name from the file
        if (max < num)
        {
            max = num;
        }
    }
    infile.close(); // Close the file
    return max;
}

int ()
{
    ifstream infile;
    int num;
    infile.open("numbers.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    int sum = 0;
    int totalNums = 0;
    while (infile >> num)
    { // Read a name from the file
        sum += num;
        totalNums++;
    }
    infile.close(); // Close the file
    return (sum / totalNums);
}