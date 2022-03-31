#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void display(int *arr, int num);
void sort(int *arr, int num);
double average(int *arr, int num);
void swap(int &a, int &b);

int main()
{

    srand(time(0));
    int num;
    cout << "how many numbers: ";
    cin >> num;
    int *arr = new int[num];
    for (size_t i = 0; i < num; i++)
    {
        *(arr + i) = rand() % 9;
    }
    display(arr, num);
    cout << "\n";
    sort(arr, num);
    display(arr, num);
    cout << "\n";
    cout << "average " << average(arr, num);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
} // end swap

void sort(int *arr, int size)
{
    bool swapFlag = true;
    // int temp;
    int limit = size - 1;
    while (swapFlag)
    {
        swapFlag = false;
        for (int i = 0; i < limit; i++)
            if (*(arr+i) > *(arr+i+1))
            {
                swap(*(arr+i), *(arr+i+1));
                /*temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;*/
                swapFlag = true;
            } // end if
        limit--;
    } // end while
} // end improvedBubbleSort

double average(int *arr, int num)
{
    int sum = 0;
    for (size_t i = 0; i < num; i++)
    {
        sum += *(arr + i);
    }
    return sum / num;
}

void display(int *arr, int num)
{
    cout << "{ " << *arr;
    for (size_t i = 1; i < num; i++)
    {
        cout << ", " << *(arr + i);
    }
    cout << "}";
}