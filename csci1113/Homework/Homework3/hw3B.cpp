#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

double sum(vector<double> nums);
double sumProd(vector<double> x, vector<double> y);
double sumSquare(vector<double> nums);
double square(double num);

int main(){
    vector<double> x, y;
    double tempx, tempy;
    int counter = 0;
    cout <<"x    y \n";
    cin >> tempx >> tempy;
    
    while (tempx != -1 && tempy != -1)
    {
        x.push_back(tempx);
        y.push_back(tempy);
        cin >> tempx >> tempy;
        counter++;
        
    }

    double sumx = sum(x);
    double sumy = sum(y);
    double sumsquarex = sumSquare(x);
    double sumsquarey = sumSquare(y);
    double sumprod = sumProd(x,y);

    double top = ((counter*sumprod)-(sumx*sumy));
    double bottomleft = (counter*sumsquarex)-(square(sumx));
    double bottomright = (counter*sumsquarey)-(square(sumy));

    cout << "Correlation coefficient is " << top/sqrt(bottomleft*bottomright);

}

double sum(vector<double> nums){
    double sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

double sumSquare(vector<double> nums){
    double sum = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += (nums[i]*nums[i]);
    }
    return sum;
}

double sumProd(vector<double> x, vector<double> y){
double sum = 0;
   for (size_t i = 0; i < x.size(); i++)
   {
       sum += (x[i]*y[i]);
   }
   return sum;
}

double square(double num){
    return num*num;
}