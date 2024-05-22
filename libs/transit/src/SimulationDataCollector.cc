#include "SimulationDataCollector.h"

#include <fstream>

#include "Data.h"

SimulationDataCollector* SimulationDataCollector::singleton_ = 0;

SimulationDataCollector::SimulationDataCollector() {}

SimulationDataCollector* SimulationDataCollector::getInstance() {
  /**
   * This is a safer way to create an instance. instance = new Singleton is
   * dangeruous in case two instance threads wants to access at the same time
   */
  if (singleton_ == nullptr) {
    std::cout << "SINGLETON_ IS A NULLPTR -- CREATING NEW INSTANCE"
              << std::endl;
    singleton_ = new SimulationDataCollector();
  }
  return singleton_;
}

void SimulationDataCollector::collectData(Data* data) {
  // Add data to the internal data vector
  collectedData.push_back(data);
}

void SimulationDataCollector::organizeData() {
  // can put these all into one loop later

  // determine which drone went further
  int dis1 = 0, dis2 = 0;
  // determine which drone made more
  int mon1 = 0, mon2 = 0;
  // number of trips made by each drone
  int tripsMade1 = 0, tripsMade2 = 0;
  // determine which restaurant got the most business
  int canesOrders = 0, chipotleOrders = 0, chickfilaOrders = 0, uber = 0;
  // determine number of times different strategies were used
  int astar = 0, dfs = 0, djikstra = 0;
  for (size_t i = 0; i < collectedData.size(); i++) {
    if (collectedData[i]->getName() == "Drone1") {
      dis1 += collectedData[i]->getDistance();
      tripsMade1++;
    } else if (collectedData[i]->getName() == "Drone2") {
      dis2 += collectedData[i]->getDistance();
      tripsMade2++;
    }

    // restaurant type test, also number of normal trips
    if (collectedData[i]->getRestaurantName() == "Canes") {
      canesOrders++;
    } else if (collectedData[i]->getRestaurantName() == "Chipotle") {
      chipotleOrders++;
    } else if (collectedData[i]->getRestaurantName() == "Chick-Fil-A") {
      chickfilaOrders++;
    } else {  // not a restaurant
      uber++;
    }

    // strategy type test
    if (collectedData[i]->getStrategy() == "astar") {
      astar++;
    } else if (collectedData[i]->getStrategy() == "dfs") {
      dfs++;
    } else {
      djikstra++;
    }
  }

  std::ofstream outputFile("output.txt");

  // print furthest distances
  if (dis1 > dis2) {
    outputFile << "Drone 1 went further at " << dis1 << ", Drone 2 went only "
               << dis2 << std::endl;
  } else {
    outputFile << "Drone 2 went further at " << dis2 << ", Drone 1 went only "
               << dis1 << std::endl;
  }

  // print number of trips
  outputFile << "Drone 1 made " << tripsMade1 << " trips" << std::endl;
  outputFile << "Drone 2 made " << tripsMade2 << " trips" << std::endl;

  // print restaurant orders
  outputFile << "Canes got " << canesOrders << " orders" << std::endl;
  outputFile << "Chick-Fil-A got " << chickfilaOrders << " orders" << std::endl;
  outputFile << "Chipotle got " << chipotleOrders << " orders" << std::endl;
  outputFile << "Uber got " << uber << " orders" << std::endl;

  // print strategy type
  outputFile << "Astar was used " << astar << " times" << std::endl;
  outputFile << "Depth First Search was used " << dfs << " times" << std::endl;
  outputFile << "Djikstra's was used " << djikstra << " times" << std::endl;

  outputFile.close();
}

void SimulationDataCollector::outputDataToCSV(std::string filename) {
  // Open the file for writing
  this->organizeData();
  std::ofstream outputFile(filename);

  // Write the header row
  outputFile
      << "Drone Name,Start x,y,z,End x,y,z,Distance,Strategy,Restaurant Name\n";

  // Write the data rows
  for (int i = 0; i < collectedData.size(); i++) {
    outputFile << collectedData.at(i)->toString();
  }

  // Close the file
  outputFile.close();

  organizeData();
}
