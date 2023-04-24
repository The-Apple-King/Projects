#ifndef SIMULATION_DATA_COLLECTOR_H
#define SIMULATION_DATA_COLLECTOR_H

#include <vector>
#include <string>
#include "Data.h"

class SimulationDataCollector {
public:

    /**
     * @brief create only a single instance of this class
     * 
     * @return SimulationDataCollector& 
     */
    static SimulationDataCollector& getInstance();

    /**
     * @brief add a Data object to our collected data vector
     * 
     * @param trip the Data object created to store data for a trip
     */
    void collectData(Data trip);

    /**
     * @brief outputs data to a file with name filename
     * 
     * outputs a header and then loops through data in collectedData and prints it out 
     * using Data's toString function
     * 
     * @param filename the name of the file to output to
     */
    void outputDataToCSV(std::string fileName);

private:
    SimulationDataCollector(); // Private constructor to prevent direct instantiation
    SimulationDataCollector(SimulationDataCollector const&) = delete; // Delete copy constructor
    void operator=(SimulationDataCollector const&) = delete; // Delete assignment operator

    std::vector<Data> collectedData; // vector storing all collected data objects
};

#endif /* SIMULATION_DATA_COLLECTOR_H */
