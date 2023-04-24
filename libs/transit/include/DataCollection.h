#ifndef SIMULATION_DATA_COLLECTOR_H
#define SIMULATION_DATA_COLLECTOR_H

#include <vector>
#include <string>
#include "Data.h"

class SimulationDataCollector {
public:
    static SimulationDataCollector& getInstance();

    void collectData(Data trip);

    void outputDataToCSV(std::string fileName);

private:
    SimulationDataCollector(); // Private constructor to prevent direct instantiation
    SimulationDataCollector(SimulationDataCollector const&) = delete; // Delete copy constructor
    void operator=(SimulationDataCollector const&) = delete; // Delete assignment operator

    std::vector<Data> collectedData;
};

#endif /* SIMULATION_DATA_COLLECTOR_H */
