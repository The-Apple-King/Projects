#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int a[10] = {0,1,2,4,5,0,0,0,0,0};
    int value = 3;
    
    bool placed = false;
    for(int i = 0; i < n; i++ ){
        if(a[i] > value){
            for (size_t k = n+1; k >= i; k--){
                a[k] = a[k-1];
            }
            a[i] = value;
            placed = true;
        }
    }
    if(!placed){
        a[n] = value;
    }
    n++;
}