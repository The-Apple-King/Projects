#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int timeToMinutes(int, int);
void min(vector<int> delay, vector<string> name);
void max(vector<int> delay, vector<string> name);
void average(vector<int> delay, vector<string> name);

int main()
{
    ifstream infile;
    string flightName, actual, expected;
    vector<int> delay;
    vector<string> flight;
    char temp;

    infile.open("flightdata.txt");
    while(infile >> flightName){
        flight.push_back(flightName);
        int expectedh, expectedm;
        int actualh, actualm;
        char temp;

        infile >> expectedh >> temp >> expectedm;
        infile >> actualh >> temp >> actualm;

        delay.push_back((timeToMinutes(actualh, actualm)-timeToMinutes(expectedh, expectedm)));
    }
    infile.close();
    
    average(delay, flight);
    cout << "\n";
    min(delay, flight);
    cout << "\n";
    max(delay, flight);

    cin >> actual;
}

int timeToMinutes(int hours, int min){
    return ((hours * 60) + min);
}


void min(vector<int> delay, vector<string> name)
{
    int min = INT_MAX;
    int num;
    string minName;
    string curName;
    for(int i = 0; i < name.size(); i++)
    {
        num = delay[i];
        curName = name[i];
        if (min > num)
        {
            minName = curName;
            min = num;
        }
        
    }
        cout << "the minimum is " << min << " by " << minName;
}

void max(vector<int> delay, vector<string> name)
{
    int max = INT_MIN;
    int num;
    string maxName;
    string curName;
    for(int i = 0; i < name.size(); i++)
    {
        num = delay[i];
        curName = name[i];
        if (max < num)
        {
            maxName = curName;
            max = num;
        }
        
    }
        cout << "the maximum is " << max << " by " << maxName;
}

void average(vector<int> delay, vector<string> name)
{
    int sum =0;
    int count = 0;
    for(int i = 0; i < name.size(); i++)
    {
        sum += delay[i];
        count++;
    }
        cout << "the average is " << sum/count;
}