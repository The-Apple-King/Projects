// Owen Swearingen
// Battery class
#include <iostream>
using namespace std;

class Battery
{
private:
    int voltage;
    int joules;
    int maxJoules;

public:
    Battery(int, int, int);
    Battery();
    bool powerDevice(int, int);
    int maxTime(int);
    void recharge();
};

/**
 * @brief Construct a new Battery:: Battery object
 *
 * @param volts voltage of battery
 * @param storing the amount of joules the battery stores
 * @param max the max number of joules the battery can store
 */
Battery::Battery(int volts, int storing, int max)
{
    voltage = volts;
    joules = storing;
    maxJoules = max;
}

/**
 * @brief Construct a new Battery:: Battery object
 * default contructor
 */
Battery::Battery()
{
    voltage = 0;
    joules = 0;
    maxJoules = 0;
}
/**
 * @brief powers a decice of amps amperage for seconds seconds and subtracts that from battery if it is possible
 *
 * @param amps amperage of the device to power
 * @param seconds seconds the device will run
 * @return true the battery can run the device and the joules will be subracted
 * @return false the battery cannot run the device
 */
bool Battery::powerDevice(int amps, int seconds)
{
    if ((voltage * amps * seconds) < joules)
    {
        joules -= (voltage * amps * seconds);
        return true;
    }
    return false;
}

/**
 * @brief will output the max time the battery can run an object that needs amps amperage
 *
 * @param amps amperage needed to run an object
 * @return int the maximum time to run an object using amps
 */
int Battery::maxTime(int amps)
{
    return joules / (voltage * amps);
}

/**
 * @brief sets joules to the max value
 *
 */
void Battery::recharge()
{
    joules = maxJoules;
}

int main()
{
    Battery batman = Battery(12.0, 5000000, 5000000);
    batman.powerDevice(4, 900);
    cout << "How long the battery's remaining energy can charge (in seconds):" << endl;
    cout << batman.maxTime(8) << endl;
    batman.recharge();
    cout << "How long the battery's remaining energy can charge after recharging (in seconds):" << endl;
    cout << batman.maxTime(8) << endl;
}

