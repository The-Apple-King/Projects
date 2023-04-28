#include "SimulationDataCollector.h"
#include "Data.h"
#include <fstream>

SimulationDataCollector* SimulationDataCollector::singleton_ = 0;

SimulationDataCollector::SimulationDataCollector(){}



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

void SimulationDataCollector::outputDataToCSV(std::string filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write the header row
        outputFile << "Drone Name,Start x,y,z,End x,y,z,Distance,Strategy,Money Made,Distance Flown,Restaurant Name,Meal Name\n";

    // Write the data rows
        for (int i = 0; i < collectedData.size(); i ++) {
            outputFile << collectedData.at(i)->toString();
        }
    

    // Close the file
    outputFile.close();
}

