#ifndef DATA_H
#define DATA_H

#include <string>
#include "math/vector3.h"
#include <sstream>

class Data {

public:
    /**
     * @brief Construct a new Data:: Data object
     * 
     * @param droneName name of the drone
     * @param start start location of a trip
     * @param end end location of a trip
     * @param distance distance traveled by the drone
     * @param strategy movement strategy used
     * @param moneyMade how much money we made
     * @param distanceFlown how much the drone flew on this recorded trip
     * @param restaurantName name of restaurant we are performing an order for
     * @param mealName name of the meal the drone is carrying
     */

    Data(Vector3 start, Vector3 end, double distance, std::string strategy, double moneyMade, double distanceFlown, str::string restaurantName, str:string mealName);

    /**
     * @brief formats the data from the object into a csv friendly format
     * 
     * @return std::string string containing data to output
     */
    std::string toString();

private:
    // any data we want to save
    str::string droneName; // what drone performed this trip?
    Vector3 start; // start position
    Vector3 end; // end position
    double distance; // distance traveled
    std::string strategy; // movement strategy
    double moneyMade; // how much money has been made?
    double distanceFlown; // how far did we fly on this trip?
    str::string restaurantName; // what's the name of this restaurant?
    str::string mealName; // what was the name of the meal we took?

};

#endif /* DATA_H */