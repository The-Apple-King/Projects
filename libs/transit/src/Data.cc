#include "Data.h"
#include "vector3.h"

Data::Data(Vector3 start, Vector3 end, double distance, std::string strategy,
           std::string deliveryType)
    : start(start), end(end), distance(distance), strategy(strategy),
      deliveryType(deliveryType) {}

std::string Data::toString(std::ofstream& stream) const {
  stream << start.x << "," << start.y << "," << start.z << ",";
  stream << end.x << "," << end.y << "," << end.z << ",";
  stream << distance << ",";
  stream << strategy << ",";
  stream << deliveryType << ",";
  return "";
}
