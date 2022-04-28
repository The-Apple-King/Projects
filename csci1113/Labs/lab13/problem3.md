 
 
Problem Three 
 
What is wrong with the following code snippets? 
 
a)  
int* p; 
int* q; 
 
p = new int[5]; 
*p = 2; 
 
for (int i = 1; i < 5; i++) { 
 p[i] = p[i - 1] + i; 
} 
 
q = p; 
 
delete[] p; 
 
for (int i = 0; i < 5; i++) { 
 cout << q[i] << " "; 
} 
cout << endl; 
 
 this just outputs random data because p was deleted and q points to the same location

b) 
 int* p; 
int* q; 
 
p = new int; 
*p = 43; 
 
q = p; 
 
delete q; 
 
cout << *p << " " << *q << endl; 
 
 the location p and q point at is the same, as soon as q gets deleted so does p
  

  #include <iostream> 
using namespace std; 
 
int main() { 
 
 int* secret; 
 int* p; 
 
 secret = new int[10]; 
 
 *secret = 10; 
 p = &secret[1]; 
 
 for (int j = 1; j < 10; j++) { 
  *p = *(p - 1) + 5; 
  p++; 
 } 
 
 for (int j = 0; j < 10; j++) { 
  cout << *(secret + j) << "  "; 
 } 
 
 cout << endl; 
 
 return 0; 
}

output: 10 15 20 25 30 35 40 45 50 55