Consider the following class declaration: 
class Point{  
  public: 
      Point(); 
      Point(int xval, int yval); 
      int getX() const;  // return xloc 
      int getY() const;  // return yloc 
      void setX(int x); 
      void setY(int y); 
  private: 
      int  xloc; 
      int  yloc; 
   
} ; 
// creates a new Point by adding both the x and y coordinates. 
Point &operator+(const Point &lhs, const Point &rhs); 
 
a. 

b.

c.

d.

e.
 
f.