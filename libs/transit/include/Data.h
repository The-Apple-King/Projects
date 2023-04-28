#ifndef DATA_H
#define DATA_H

#include <string>
#include "math/vector3.h"
#include <sstream>

class Data {

public:
    /**
     * @brief 
     * @param distance distance traveled by the drone
     * @param strategy movement strategy used
     * @param moneyMade how much money we made
     * @param distanceFlown how much the drone flew on this recorded tripConstruct a new Data:: Data object
     * @param droneName name of the drone
     * @param tripName name that the trip was given
     * @param start start location of a trip
     * @param end end location of a trip
     * @param restaurantName name of restaurant we are performing an order for
     * @param mealName name of the meal the drone is carrying
     */

    Data(std::string droneName, std::string tripName, Vector3 start, Vector3 end, double distance, std::string strategy, double moneyMade, double distanceFlown, std::string restaurantName, std::string mealName);
    // string, start, end, double, string, double, double, string, string


    /**
     * @brief formats the data from the object into a csv friendly format
     * 
     * @return std::string string containing data to output
     */
    std::string toString();

    void incrementDistance(double distance){
        this->distance += distance;
    }

    void nameOfDrone(std::string name){
        droneName = name;
    }

private:
    // any data we want to save
    std::string droneName; // what drone performed this trip?
    Vector3 start; // start position
    Vector3 end; // end position
    double distance; // distance traveled
    std::string strategy; // movement strategy
    double moneyMade; // how much money has been made?
    double distanceFlown; // how far did we fly on this trip?
    std::string restaurantName; // what's the name of this restaurant?
    std::string mealName; // what was the name of the meal we took?

};

#endif /* DATA_H */