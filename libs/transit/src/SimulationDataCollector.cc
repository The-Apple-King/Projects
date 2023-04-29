#include "SimulationDataCollector.h"
#include "Data.h"
#include <fstream>

SimulationDataCollector* SimulationDataCollector::singleton_ = 0;


SimulationDataCollector::SimulationDataCollector() {}

SimulationDataCollector *SimulationDataCollector::getInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(singleton_== nullptr){
        std::cout << "SINGLETON_ IS A NULLPTR -- CREATING NEW INSTANCE" << std::endl;
        singleton_ = new SimulationDataCollector();
    }
    return singleton_;
}

void SimulationDataCollector::collectData(Data* data) {
    // Add data to the internal data vector
    collectedData.push_back(data);
}

std::string SimulationDataCollector::organizeData() {
    // can put these all into one loop later

    // determine which drone went further
    int dis1, dis2 = 0;
    // determine which drone made more
    int mon1, mon2 = 0;
    // number of trips made by each drone
    int tripsMade1, tripsMade2 = 0;
    // determine which restaurant got the most business
    int rest1, rest2, rest3, uber = 0;
    // determine number of times different strategies were used
     int astar, dfs, djikstra = 0;
    for (size_t i = 0; i < collectedData.size(); i++)
    {
        if (collectedData[i]->getName() == "drone1")
        {
            dis1 += collectedData[i]->getDistance();
            mon1 += collectedData[i]->getMoneyMade();
            tripsMade1 ++;
        }
        else if (collectedData[i]->getName() == "drone2")
        {
            dis1 += collectedData[i]->getDistance();
            mon2 += collectedData[i]->getMoneyMade();
            tripsMade2 ++;
        }


        // restaurant type test, also number of normal trips
        if (collectedData[i]->getRestaurantName() == "RESTAURANT NAME")
        {
            rest1 ++;
        }
        else if (collectedData[i]->getRestaurantName() == "RESTAURANT NAME")
        {
            rest2 ++;
        }
        else if (collectedData[i]->getRestaurantName() == "RESTAURANT NAME")
        {
            rest3 ++;
        }
        else{ // not a restaurant
            uber++;
        }

        // strategy type test
        if (collectedData[i]->getStrategy() == "astar")
        {
            astar ++;
        }
        else if (collectedData[i]->getStrategy() == "dfs")
        {
            dfs++;
        }
        else{
            djikstra ++;
        }
    }


}

void SimulationDataCollector::outputDataToCSV(std::string filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write the header row
    outputFile << "Drone Name,Start x,y,z,End x,y,z,Distance,Strategy,Money Made,Distance Flown,Restaurant Name,Meal Name\n";

    outputFile << organizeData();

    // Write the data rows
    for (int i = 0; i < collectedData.size(); i ++) {
        outputFile << collectedData.at(i)->toString();
    }
    

    // Close the file
    outputFile.close();
}

