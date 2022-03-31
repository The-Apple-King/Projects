#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    int b = 2;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    *p1 = *p2;
    *p2 = 10;
    cout << *p1 << ' ' << b << ' ' << a << endl; // 2 10 2
    *p2 += *p1;
    cout << *p2 << " " << b << " " << a << endl; // 12 12 2
    int **p;                                       // declare a pointer to a pointer. What does this mean?
    p = &p1;
    cout <<"Value of p1 is " << p1 << "Value of * p is " << *p << endl; // 2 2
    cout << "**p = " << **p << endl;                                    // 2
}