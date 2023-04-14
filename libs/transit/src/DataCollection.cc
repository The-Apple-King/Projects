#include "SimulationDataCollector.h"
#include "Data.h"
#include <fstream>

SimulationDataCollector& SimulationDataCollector::getInstance() {
    static SimulationDataCollector instance;
    return instance;
}

// none of these work, they are more of templates, we use data class to print and collect data

void SimulationDataCollector::collectData(int simulationId, double simulationValue) {
    // Add data to the internal data vector
    data.emplace_back(simulationId, simulationValue);
}

void SimulationDataCollector::outputDataToFile(std::string filename) const {
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write the header row
    outputFile << "Simulation ID,Simulation Value\n";

    // Write the data rows
    for (const auto& d : data) {
        outputFile << d.simulationId << "," << d.simulationValue << "\n";
    }

    // Close the file
    outputFile.close();
}
