Consider the following class declaration: 
class Point{  
  public: 
      Point(); 
      Point(int xval, int yval); 
      int getX() const;  // return xloc 
      int getY() const;  // return yloc 
      void setX(int x); 
      void setY(int y); 
      Point &operator+(const Point) //b
  private: 
      int  xloc; 
      int  yloc; 
   
} ; 
// creates a new Point by adding both the x and y coordinates. 
Point &operator+(const Point &lhs, const Point &rhs); 
 
a. Point &operator+(const Point &a, const Point &b){
    int x = a.getX() + b.getX();
    int y = a.getY() + b.getY();
    Point c = Point(x, y);
    return c;
}

b.

c.Point &operator+(const Point &b){
    int x = x + b.X;
    int y = y + b.Y;
    Point c = Point(x, y);
    return c;
}

d. ostream because it does the same thing as writing cout over and over;

e. we need to use << for a different value type when using cout not for any private items in class
 
f. ostream &operator<<(ostream& outstream, const Point a){
    outstream << a.getX() + ',' + a.getY();
    return outstream;
}