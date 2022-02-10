#include <iostream>
using namespace std;

int main() {
    int hour = 0;
    int minute = 0;
    int hourleave = 0;
    int minuteleave = 0;
    int time = 0;
    double tot = 0;
    char vehicle = ' ';
    string ve = "";
    char temp = ' ';
    //enter info
    cout << "Enter when you entered in Hour:Min format: ";
    cin >> hour >> temp >> minute;
    cout << "Enter when you left in Hour:Min format: ";
    cin >> hourleave >> temp >> minuteleave;
    cout << "Enter char for vehicle (C)ar, (B)us, (T)ruck: ";
    cin >> vehicle;
    time = hourleave-hour;
    if((minuteleave - minute) > 0){
        time++;
    }

    //do math
    if(toupper(vehicle) == 'C'){
        ve = "Car";
        if(time > 3){
            tot = (time-3)*1.5;
        }
    }
    else if(toupper(vehicle) == 'B'){
        ve = "Bus";
        if(time > 2){
            tot = ((time-2)*2.3) + 2;
        }
        else{
            time*=1;
        }
    }
    else if(toupper(vehicle) == 'T'){
        ve = "Truck";
        if(time > 1){
            tot = ((time-1)*3.7) + 2;
        }
        else{
            time*=2;
        }
    }

    //print out
    cout << "Type of vehicle: " << ve << "\n";
    if(minute<10){
        cout << "TIME-IN: " << hour << ":0" << minute << "\n";
    }
    else{
        cout << "TIME-IN: " << hour << ":" << minute << "\n";
    }
    if(minuteleave<10){
        cout << "TIME-OUT: " << hourleave << ":0" << minuteleave << "\n";
    }
    else{
        cout << "TIME-OUT: " << hourleave << ":" << minuteleave << "\n";
    }
    cout << "----------------" << "\n";
    cout << "PARKING TIME: " << time << "\n";
    cout << "\nTOTAL CHARGE: $" << tot << "0";
}