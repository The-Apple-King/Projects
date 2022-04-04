#include <iostream> 
 using namespace std; 
 int alter( int &, int &); 
 int c; 
 int main(){ 
  int a, b, d; 
  a = 1; 
  b = 2; 
  c = 3; 
  d = 4; 
  a = alter(d, b); 
  cout << "a = " << a << " b = " << b << " c = " << c << " d = " << 
d << endl; 
int alter(int &a, int &b){ 
  int d; 
 
cout << "a = " << a << " b = " << b << " c = " << c << " d = " << 
d << endl; 
   
d = a * b; 
  c = a + b; 
  b = 9; 
  a = 7; 
   
cout << " " << a << " " << b << " " << c << " " << d << endl; 
  
   
return b; 
}
 } 
 