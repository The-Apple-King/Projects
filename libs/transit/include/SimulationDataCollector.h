#ifndef SIMULATION_DATA_COLLECTOR_H
#define SIMULATION_DATA_COLLECTOR_H

#include <vector>
#include <string>

class SimulationDataCollector {
public:
    static SimulationDataCollector& getInstance();

    void collectData(double data);

    void outputDataToCSV(std::string fileName);

private:
    SimulationDataCollector(); // Private constructor to prevent direct instantiation
    SimulationDataCollector(SimulationDataCollector const&) = delete; // Delete copy constructor
    void operator=(SimulationDataCollector const&) = delete; // Delete assignment operator

    std::vector<double> collectedData;
};

#endif /* SIMULATION_DATA_COLLECTOR_H */
