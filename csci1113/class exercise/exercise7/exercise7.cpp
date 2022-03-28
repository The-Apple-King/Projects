#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

double avg(int scores[100]);
double findsd(int scores[]);
void curvedScore(int scores[], double average, double sd);

int main()
{
    int total;
    double average;
    double sd;

    int scores[100] = {0};

    ifstream infile;
    int num;
    infile.open("C:/Users/gifte/Documents/projects/csci1113/class exercise/exercise7/numbers.txt");
    if (!infile)
    {
        cout << "Error opening the file.";
    }

    for (size_t i = 0; i < 101; i++)
    {
        infile >> scores[i];
    }

    average = avg(scores);
    sd = findsd(scores);
    curvedScore(scores,average,sd);

}

/**
 * @brief returns the average
 * 
 * @param scores array of scores
 * @return double average
 */
double avg(int scores[100])
{
    int tot = 0;
    for (size_t i = 0; i < 100; i++)
    {
        tot += scores[i];
    }
    return (tot / 100.0);
}

/**
 * @brief returns the standard deviation of an array
 * 
 * @param scores array of scores
 * @return double standard deviation
 */
double findsd(int scores[])
{
    double sum = 0, average, standardDeviation = 0;
    int i;

    for (i = 0; i < 100; ++i)
    {
        sum += scores[i];
    }
    average = sum / 100.0;

    for (i = 0; i < 100; ++i)
    {
        standardDeviation += pow(scores[i] - average, 2);
    }

    return sqrt(standardDeviation / 100.0);
}


/**
 * @brief prints out the letter grade of the scores in the console
 * 
 * @param scores array of scores
 * @param average average of the scores
 * @param sd standard deviation of the scores
 */
void curvedScore(int scores[], double average, double sd)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (scores[i] < (average - ((3 / 2) * sd)))
        {
            cout << scores[i] << " F\n";
        }
        else if (scores[i] < (average - ((1 / 2) * sd)))
        {
            cout << scores[i] << " D\n";
        }
        else if (scores[i] < (average + ((1 / 2) * sd)))
        {
            cout << scores[i] << " C\n";
        }
        else if (scores[i] < (average + ((3 / 2) * sd)))
        {
            cout << scores[i] << " B\n";
        }
        else if (scores[i] > (average + ((3 / 2) * sd)))
        {
            cout << scores[i] << " A\n";
        }
    }
}