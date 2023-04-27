#include "DataCollection.h"
#include "Data.h"
#include <fstream>


SimulationDataCollector& SimulationDataCollector::getInstance() {
    static SimulationDataCollector instance;
    return instance;
}

void SimulationDataCollector::collectData(Data trip) {
    // Add data to the internal data vector
    collectedData.push_back(trip);
}

void SimulationDataCollector::outputDataToCSV(std::string filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write the header row, will need to be changed for more stuff we add
    outputFile << "Drone name,Start x,y,z,End x,y,z,Distance,Strategy,moneyMade,distanceFlown,restaurantName,mealName\n";

    // Write the data rows
    for (size_t i = 0; i < collectedData.size(); i++)
    {
        outputFile << collectedData[i].toString();
    }

    // Close the file
    outputFile.close();
}
