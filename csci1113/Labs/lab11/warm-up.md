1  class Point{ 
2   public:  
3     void showPoint() const;  
4     Point();  
5     Point(int, int);  
6     int  xlocation;  
7     int  ylocation;  
8   };

a.
b.public means it is accesible from anywhere so yes
c.probably not because that leaves more locations for point to go wrong
d.unchangeable value 
e. Point(int xval, int yval){
    xlocation = xval;
    ylocation = yval;
}

2. Consider the following code segment, assuming the Point class definition from Warm-up 
1, and answer the questions below.  
 
1  int main(){ 
2    
3     Point.xlocation = 3;  
4     Point.ylocation = 10;  
5  
6     Point p1;  
7     p1 = Point(5,6);  
8  
9     Point p2;  
10    return 0;  
11 }

a. there is no specific Point set. for instance Point p2; p2.xlocation
b. line 7 creates a point object with the x and y values 5 and 6
c. the x and y values aren't inputted so there is no x or y values for point
d. no values;
e. Point p2(0,0);


3. #include <iostream> 
  using namespace std; 
  
1     class Vec2D { 
2   private: 
3  int xPosition; 
4  int yPosition; 
5  
6  int xVelocity; 
7  int yVelocity; 
8 
9    public: 
10  Vec2D(); 
11  Vec2D(int xPos, int yPos, int xVel, int yVel); 
12  void showVector(); 
13 }; 
14 
15  void Vec2D::showVector(){ 
16  cout<< “Position: (“<< xPosition << “, “ << yPosition << “)\n”; 
17  cout<< “Velocity: (“<< xVelocity << “, “ << yVelocity << “)\n\n”; 
18 }

a.public sets things accesible everywhere, private only allows that object to modify them.
b. 
i. there is a default constructor for vec2D and a constructor with values
ii. the constructor with no values
iii. because constructors don't need to return anything all they do is create an object
c.show vec returns the values and because it is public it can print out the private variables for the programmer with a public method