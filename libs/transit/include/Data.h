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
     * @param droneName name of the drone
     * @param tripName name that the trip was given
     * @param start start location of a trip
     * @param end end location of a trip
     * @param restaurantName name of restaurant we are performing an order for
     */

    Data(std::string droneName, std::string tripName, Vector3 start, Vector3 end, double distance, std::string strategy, std::string restaurantName);
    // string, string, start, end, double, string, double, string

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(){return droneName;}

    /**
     * @brief Get the Start object
     * 
     * @return Vector3 
     */
    Vector3 getStart(){return start;}

    /**
     * @brief Get the End object
     * 
     * @return Vector3 
     */
    Vector3 getEnd() {return end;}

    /**
     * @brief Get the Distance object
     * 
     * @return double 
     */
    double getDistance(){return distance;}

    /**
     * @brief Get the Strategy object
     * 
     * @return std::string 
     */
    std::string getStrategy(){return strategy;}

    /**
     * @brief Get the Restaurant Name object
     * 
     * @return std::string 
     */
    std::string getRestaurantName(){return restaurantName;}

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
    void nameOfDrone(std::string name){
        droneName = name;
    }

private:
    // any data we want to save
    std::string droneName; // what drone performed this trip?
    std::string tripName;
    Vector3 start; // start position
    Vector3 end; // end position
    double distance; // distance traveled
    std::string strategy; // movement strategy
    std::string restaurantName; // what's the name of this restaurant?

};

#endif /* DATA_H */