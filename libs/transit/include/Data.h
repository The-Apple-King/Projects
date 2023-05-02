#ifndef DATA_H
#define DATA_H

#include <sstream>
#include <string>

#include "math/vector3.h"

class Data {
 public:
  /**
   * @brief Creates a data object to store information from the simulation
   *
   * @param droneName name of the drone
   * @param tripName name that the trip was given
   * @param start start location of a trip
   * @param end end location of a trip
   * @param distance distance traveled by the drone
   * @param strategy movement strategy used
   * @param restaurantName name of restaurant we are performing an order for
   */
  Data(std::string droneName, std::string tripName, Vector3 start, Vector3 end,
       double distance, std::string strategy, std::string restaurantName);
  // string, string, start, end, double, string, double, string

  /**
   * @brief Get the Name of the drone
   *
   * @return std::string
   */
  std::string getName() { return droneName; }

  /**
   * @brief Get the start position of the drone
   *
   * @return Vector3 location of the drone at the start of the trip
   */
  Vector3 getStart() { return start; }

  /**
   * @brief Get the End position of the drone
   *
   * @return Vector3 location of the drone at the end of the trip
   */
  Vector3 getEnd() { return end; }

  /**
   * @brief Get the distance that the drone has traveled
   *
   * @return double the distance traveled
   */
  double getDistance() { return distance; }

  /**
   * @brief Get the name of the movement strategy
   *
   * @return std::string the name of the strategy as a string
   */
  std::string getStrategy() { return strategy; }

  /**
   * @brief Get the name of the restaurant
   *
   * @return std::string name of the restaurant as a string
   */
  std::string getRestaurantName() { return restaurantName; }

  /**
   * @brief formats the data from the object into a csv friendly format
   *
   * @return std::string string containing data to output
   */
  std::string toString();

  /**
   * @brief used to set name of drone in drone
   *
   * @param name the name of the drone
   */
  void nameOfDrone(std::string name) { droneName = name; }

  /**
   * @brief Set the name of the restaurant
   *
   * @param restaurant the new restaurant name
   */
  void setRestaurant(std::string restaurant) { restaurantName = restaurant; }

 private:
  // any data we want to save
  std::string droneName;       // what drone performed this trip?
  std::string tripName;        // the name of the client
  Vector3 start;               // start position
  Vector3 end;                 // end position
  double distance;             // distance traveled
  std::string strategy;        // movement strategy
  std::string restaurantName;  // what's the name of this restaurant?
};

#endif  // DATA_H
