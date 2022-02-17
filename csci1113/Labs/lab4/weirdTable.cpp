#include <iostream>
using namespace std;

int main()
{
    for (size_t i = 11; i < 67; i++)
    {
        for (size_t j = 1; j < 7; j++)
        {
            if ((i%10) != j && (i/10) != j && (i%10) != (i/10))
            {
                cout << "*" << i << j << " ";
            }
            else{
            cout << i << j << " ";
            }
        }
        cout << "\n";
        if (i%10 ==6){
            i+=4;
        }
    }
}