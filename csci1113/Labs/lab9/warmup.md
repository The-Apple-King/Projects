1. cout << *ptr

2. int arr[20] = {0}
int *loc = &arr
for(int i =0; i < 20; i++){
    cin >> *loc;
    loc++;
}

3. delete [] arr;

4. void getNumber(int *n){ 
 
   cout << "Enter a number: "; 
   cin >> *n; 
 
}// end getNumber 

5. 
a.  int x, *ptr; 
&x = *ptr;   // Assign the address of x to ptr 

b.  int x, *ptr; 
ptr = &x;  // Assign the address of x to ptr 

c.  int x, *ptr; 
ptr = &x; 
*ptr = 100; // Store 100 in x 
cout << x << endl; 

d.  int numbers[] = {10, 20, 30, 40, 50}; 
cout << "The third element in the array is "; 
cout << *(numbers + 2) << endl; 

e.  int values[20], *iptr; 
iptr = values; 
*iptr *= 2;  // multiply the first element by 2

6. 
int pointerFun(int &x, int &y){ 
   int temp = x; 
   x = y * 10; 
   y = temp * 10; 
   return x + y; 
} 

int pointerFun(int *x, int *y){ 
   int temp = *x; 
   *x = *y * 10; 
   *y = temp * 10; 
   return *x + *y; 
}

2.
a) What is the output of the following code segment? 
 
int a = 1; 
int b = 2; 
int *p1, *p2; 
p1 = &a; 
p2 = &b; 
*p1 = *p2; 
*p2 = 10; 
cout << *p1 << ' ' << b << ' ' << a << endl;                            //2 10 2
*p2 += *p1; 
cout << *p2 << “  “ << b << “  “ << a << endl;                          //12 12 2
int **p;  // declare a pointer to a pointer. What does this mean? 
p = &p1; 
cout <<”Value of p1 is “ << p1 << “Value of  *p is “ <<  *p << endl;    //mem address * 2
cout << “**p = “ <<  **p  << endl; //2
 
 


b) Describe the problem with this function:  
    void foo(){  
 
int *a = new int[100]; 
 for(int i = 0; i < 100; i++){ //do something } }

 *a is a memory address its much easier if its just a normal variable.