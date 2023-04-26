#include "Data.h"
#include "math/vector3.h"
#include <sstream>


Data::Data(Vector3 start, Vector3 end, double distance, std::string strategy, double moneyMade, double distanceFlown, str::string restaurantName, str:string mealName) : start(start), end(end), distance(distance), strategy(strategy), moneyMade(moneyMade), distanceFlown(distanceFlown), restaurantName(restaurantName), mealName(mealName) {}

std::string Data::toString(){
  std::ostringstream stream;
  stream << start.x << "," << start.y << "," << start.z << ",";
  stream << end.x << "," << end.y << "," << end.z << ",";
  stream << distance << ",";
  stream << strategy << ",";
  stream << moneyMade << ",";
  stream << distanceFlown << ",";
  stream << restaurantName << ",";
  stream << mealName << ",";
  // stream << deliveryType << "\n"; deliveryType is not defined yet
  return stream.str();
}