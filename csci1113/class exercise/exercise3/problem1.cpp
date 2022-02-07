#include <iostream>
using namespace std;

int main() {

    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double m =0;
	cout << "enter x and y format \"x y\" \n";
    cin >> x1 >> y1;
    cout << "enter second x and y format \"x y\" \n";
    cin >> x2 >> y2;

    if (x1 == x2){
        cout << "verticle line/undefined";
    }
    else{
        m =(y2-y1)/(x2-x1);
        cout << "y=" << m << "x +" << (min(y1,y2)) << "\n";
        if (m>0){
            cout << "increasing";
        }
        else if (m<0){
            cout << "decreasing";
        }
        else if (m==0){
            cout << "flat";
        }
        
    }
	return 0;

}