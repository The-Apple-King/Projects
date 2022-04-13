#include <iostream>
#include <cmath>
using namespace std;

class Vec2D {
private:
	int xPosition;
	int yPosition;

	int xVelocity;
	int yVelocity;

public:
	Vec2D();
	Vec2D(int xPos, int yPos, int xVel, int yVel);
	void showVector();
	void move();
	float distanceTo(Vec2D v2);

};
void Vec2D::showVector() {
	cout << "Position: (" << xPosition << ", " << yPosition << ")\n";
	cout << "Velocity: (" << xVelocity << ", " << yVelocity << ")\n\n";

}

int main() {

	Vec2D v = Vec2D(0, 0, 1, -5); 
 v.showVector(); 
 v.move(); 
 v.showVector(); 
 v.move(); 
 v.move(); 
 v.showVector();  
}


Vec2D::Vec2D(){
	xPosition = 0;
	yPosition = 0;
	xVelocity = 0;
	yVelocity = 0;
}

Vec2D::Vec2D(int xPos, int yPos, int xVel, int yVel){
	xPosition = xPos;
	yPosition = yPos;
	xVelocity = xVel;
	yVelocity = yVel;
}

void Vec2D::move(){
	xPosition += xVelocity;
	yPosition += yVelocity;
}

float Vec2D::distanceTo(Vec2D v2){
	return sqrt(pow((v2.xPosition - xPosition),2) + (pow((v2.yPosition - yPosition),2)));
}