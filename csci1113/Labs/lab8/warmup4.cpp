#include <iostream>
using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void output(string[], double[], int);


int main() 
{
	string fullName[100];
	double height[100];
    
    
    int count = requestNumberOfPartners();
    

    for (size_t i = 0; i < count; i++)
    {
        fullName[i] = requestName();
	    height[i] = requestHeight(fullName[i]);
    }
	
    output(fullName, height, count);

}

string requestName()
{
	string name;
	cout << "Please enter full name: ";
	cin >> name;
	return name;
}

double requestHeight(string fullName)
{
	double height;
	cout << "Please enter " << fullName << "'s height: ";
	cin >> height;
	cin.ignore(2, '\n'); // gets rid of \n in the buffer
	
	return height;
}

int requestNumberOfPartners()
{
	int numberOfPartners; 
	cout << "How many partners are there? ";
	cin >> numberOfPartners;
	return numberOfPartners;
}

void output(string fullName[], double height[], int count){
    int tot = height[0];
    cout << "If " << fullName[0];
    for (size_t i = 1; i < count; i++)
    {
        tot += height[i];
        cout << " and " << fullName[i];
    }
    
			cout << " stand on top of each other, their combined height will be "
			<< (tot);
} 