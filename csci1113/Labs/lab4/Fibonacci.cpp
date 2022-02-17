#include <iostream>
using namespace std;

int main()
{
    int tot = 0;
    int fib1 = 0;
    int fib2 = 1;
    int temp = 0;

    cout << "Enter the number of Fibonacci numbers: ";
    cin >> tot;

    if (tot > 0)
    {
        cout << fib1;
    }
    if (tot > 1)
    {
        cout << ", " << fib2;
    }
    if (tot > 2)
    {

        for (size_t i = 2; i < tot; i++)
        {
            cout << ", " << (fib2 + fib1);
            temp = fib1;
            fib1 = fib2;
            fib2 = temp + fib2;
        }
    }
}