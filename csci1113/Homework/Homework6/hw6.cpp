//Owen Swearingen
//CNC machine
#include <iostream>
#include <fstream>
using namespace std;

struct Laser
{
    char output[40][40]; // output array
    int x = 0;//x position of laser
    int y = 0;//y position of laser
    //makes it easier to print out
    int maxX = 0;//max x position of laser
    int maxY = 0;//max y position of laser
    bool on = false;// whether the laser is on or off
    int direction = 0; // east = 0 south = 1 west = 2 north = 3
};

void act(struct Laser &, char, int);
void print(struct Laser &, ostream *);
void print(struct Laser &);
void turnRight(struct Laser &);
void turnLeft(struct Laser &);
void forward(struct Laser &, int);
void fillArr(struct Laser &);


int main()
{
    struct Laser laser;//contains all info for the laser
    int count = 0;//the distance for command F

    ifstream infile;
    char command;// command recieved from the file

    infile.open("laser.txt");
    if (!infile)
    {
        cout << "Error opening the file. Terminating.\n";
        return -1;
    }

    fillArr(laser);

    while (infile >> command)
    {
        if(command == 'F'){
            infile >> count;
        }
        act(laser, command, count);
        count = 0;
    }
    infile.close();

    ofstream outfile;
    outfile.open("output.txt");
    print(laser, &outfile);
    outfile.close();
    int *a = new int[69], b;
    delete[] a;
}

/**
 * @brief does the action recieved from text file
 *
 * @param action the character representing action
 * @param val only used for the forward command to represent spaces
 */
void act(struct Laser &laser, char action, int val)
{
    switch (action)
    {
    case 'U': // off
        laser.on = false;
        break;
    case 'D': // on
        laser.on = true;
        //laser.output[laser.x][laser.y] = '*';
        break;
    case 'R': // turn right
        turnRight(laser);
        break;
    case 'L': // turn left
        turnLeft(laser);
        break;
    case 'F': // move forward val spaces
        forward(laser, val);
        break;
    case 'P': // print out array
        print(laser);
        break;
    case 'Q':// end of the txt
        break;
    default:
        cout << "please enter a valid char";
        break;
    }
}
/**
 * @brief prints out the array the sent in stream
 * 
 */
void print(struct Laser &laser, ostream *stream)
{
    for (size_t i = 0; i <= laser.maxY; i++)
    {
        for (size_t j = 0; j <= laser.maxX; j++)
        {
            *stream << laser.output[j][i];
        }
        *stream << endl;
    }
}

/**
 * @brief overloaded print, outputs to console
 * 
 * @param laser the laser struct that contains everything
 */
void print(struct Laser &laser) {
    print(laser, &cout);
}


/**
 * @brief prints out the array into the console
 * 
 */
void fillArr(struct Laser &laser)
{
    for (size_t i = 0; i < 40; i++)
    {
        for (size_t j = 0; j < 40; j++)
        {
            laser.output[i][j] = ' ';
        }
    }
}

/**
 * @brief adds 1 to laser.direction unless laser.direction = 3 when its set to 0
 *
 */
void turnRight(struct Laser &laser)
{
    laser.direction++;
    if (laser.direction > 3)
    {
        laser.direction = 0;
    }
}

/**
 * @brief subtracts 1 from laser.direction unless laser.direction = 0 then laser.direction = 3
 *
 */
void turnLeft(struct Laser &laser)
{
    laser.direction--;
    if (laser.direction < 0)
    {
        laser.direction = 3;
    }
}

/**
 * @brief moves forward and if laser is on then draws
 *
 * @param count amount of steps forward
 */
void forward(struct Laser &laser, int count)
{
    int xdir = 0;
    int ydir = 0;
    switch (laser.direction)
    {
    case 0: // east
        xdir++;
        break;
    case 1: // south
        ydir++;
        break;
    case 2: // west
        xdir--;
        break;
    case 3: // north
        ydir--;
        break;
    }
    for (size_t i = 0; i < count; i++)
    {
        laser.x+= xdir;
        laser.y+= ydir;
        if(laser.x > laser.maxX) {
            laser.maxX = laser.x;
        }
        if(laser.y > laser.maxY) {
            laser.maxY = laser.y;
        }
        if (laser.on)
        {
            laser.output[laser.x][laser.y] = '*';
        }
    }
}