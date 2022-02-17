#include <iostream>
using namespace std;

int main() {

	double initTemp = 0;
    double surroundTemp = 0;
    double growth =0;
    double time = 0;
    double simLength = 0;
    cout << "Enter the initial temperature: ";
    cin >> initTemp;
    cout << "Enter the temperature of the surroundings: ";
    cin >> surroundTemp;
    cout << "Enter the growth (decay) rate: ";
    cin >> growth;
    cout << "Enter the time step in hours: ";
    cin >> time;
    cout << "Enter the simulation length in hours: ";
    cin >> simLength;
    
    //do math and output
    for (double i = time; i < simLength+1; i+=time)
    {
        initTemp = initTemp + (growth*(surroundTemp-initTemp)*time);
        cout << i << " " << initTemp << "\n";
    }
    
    
}