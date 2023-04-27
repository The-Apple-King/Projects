#ifndef SIMULATION_DATA_COLLECTOR_H
#define SIMULATION_DATA_COLLECTOR_H

#include <vector>
#include <string>
#include "Data.h"

class SimulationDataCollector {
public:

    /**
     * @brief singleton constructor
     * 
     * @return SimulationDataCollector* 
     */
    static SimulationDataCollector* getInstance();

    /**
     * @brief adds a Data object to vector collected data 
     * 
     * @param data the data object containing trip info
     */
    void collectData(Data* data);

    /**
     * @brief prints the data to a csv
     * 
     * @param fileName the name of the file to output to
     */
    void outputDataToCSV(std::string fileName);

    /**
     * @brief not implemented but should cycle through collectedData and determine info
     * 
     */
    void organizeData();

private:
    SimulationDataCollector(); // Private constructor to prevent direct instantiation
    SimulationDataCollector(SimulationDataCollector const&) = delete; // Delete copy constructor
    void operator=(SimulationDataCollector const&) = delete; // Delete assignment operator

protected:
    std::vector<Data*> collectedData;
    static SimulationDataCollector* singleton_;
};


#endif /* SIMULATION_DATA_COLLECTOR_H */
