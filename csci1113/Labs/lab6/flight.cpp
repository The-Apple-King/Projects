#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile;
    string flightName, actual, expected;
    char temp;

    outfile.open("flightdata.txt");

    while (true)
    {

        // enter info
        cout << "Enter the flight num ";
        cin >> flightName;
        if(flightName == "end"){
            break;
        }
        cout << "Enter the scheduled/actual arrival times: ";
        cin >> expected >> actual;

        outfile << flightName << " " << expected << " " << actual << "\n";
    }
    outfile.close();
    cin >> actual;
}
