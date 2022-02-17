#include <iostream>
using namespace std;

int main()
{
    for (size_t i = 1; i < 11; i++)
    {
        for (size_t j = 1; j < 11; j++)
        {
            cout << (i * j) << " ";
        }
        cout << "\n";
    }
}