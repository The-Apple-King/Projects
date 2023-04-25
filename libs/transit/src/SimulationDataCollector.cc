#include "SimulationDataCollector.h"
#include "Data.h"
#include <fstream>

SimulationDataCollector& SimulationDataCollector::getInstance() {
    static SimulationDataCollector instance;
    return instance;
}

void SimulationDataCollector::collectData(Data* trip) {
    // Add data to the internal data vector
    collectedData.push_back(trip);
}

void SimulationDataCollector::outputDataToCSV(std::string filename) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write the header row
    outputFile << "Simulation ID,Simulation Value\n";

    // Write the data rows
    for (int i = 0; i < collectedData.size(); i ++) {
        outputFile << collectedData[i].toString();
    }

    // Close the file
    outputFile.close();
}
