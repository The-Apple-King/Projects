#include "Data.h"
#include "math/vector3.h"
#include <sstream>


Data::Data(std::string droneName, std::string tripName, Vector3 start, Vector3 end, double distance, std::string strategy, std::string restaurantName) : start(start), end(end), distance(distance), strategy(strategy), restaurantName(restaurantName){}

std::string Data::toString(){
  std::ostringstream stream;
  stream << droneName << ",";
  stream << start.x << "," << start.y << "," << start.z << ",";
  stream << end.x << "," << end.y << "," << end.z << ",";
  stream << distance << ",";
  stream << strategy << ",";
  stream << restaurantName << "\n";
  return stream.str();
}

