#ifndef SIMULATION_DATA_COLLECTOR_H_
#define SIMULATION_DATA_COLLECTOR_H_

#include <string>
#include <vector>

#include "Data.h"

class SimulationDataCollector {
 public:
  /**
   * @brief Singleton constructor
   *
   * @return SimulationDataCollector*
   */
  static SimulationDataCollector* getInstance();

  /**
   * @brief Adds a Data object to vector collected data
   *
   * @param data The data object containing trip info
   */
  void collectData(Data* data);

  /**
   * @brief Prints the data to a CSV file
   *
   * @param fileName The name of the file to output to
   */
  void outputDataToCSV(std::string fileName);

  /**
   * @brief Looks through data collected and outputs it to a TXT file with
   * interesting info
   */
  void organizeData();

 private:
  SimulationDataCollector();  // Private constructor to prevent direct
                              // instantiation
  SimulationDataCollector(SimulationDataCollector const&) =
      delete;  // Delete copy constructor
  void operator=(SimulationDataCollector const&) =
      delete;  // Delete assignment operator

 protected:
  std::vector<Data*> collectedData;
  static SimulationDataCollector* singleton_;
};

#endif  // SIMULATION_DATA_COLLECTOR_H_
