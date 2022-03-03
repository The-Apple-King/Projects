#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int sum(vector<int> nums);
int sumProd(vector<int> x, vector<int> y);
int sumSquare(vector<int> nums);

int main(){
    vector<int> x, y;
    int tempx, tempy, counter = 0;
    cout <<"x y";
    cin >> tempx, tempy;
    counter++;
    x.push_back(tempx);
    y.push_back(tempy);

    cout << "Correlation coefficient" << (counter*sumProd(x,y)-((sum(x)*sum(y)))/sqrt(((counter*sumSquare(x)-sum(x))*(counter*sumSquare(x)-sum(x))) * ((counter*sumSquare(y)-sum(y))*(counter*sumSquare(y)-sum(y)))));

}

int sum(vector<int> nums){
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

int sumSquare(vector<int> nums){
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += (nums[i]*nums[i]);
    }
    return sum;
}

int sumProd(vector<int> x, vector<int> y){
int sum = 0;
   for (size_t i = 0; i < x.size(); i++)
   {
       sum += (x[i]*y[i]);
   }
   return sum;
}