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
     * @param start start location of a trip
     * @param end end location of a trip
     * @param distance distance traveled by the drone
     * @param strategy movement strategy used
     * @param deliveryType whether we moved a person or delivered food
     */
    Data(Vector3 start, Vector3 end, double distance, std::string strategy, std::string deliveryType);

    /**
     * @brief formats the data from the object into a csv friendly format
     * 
     * @return std::string string containing data to output
     */
    std::string toString();

private:
    // any data we want to save
    Vector3 start; // start position
    Vector3 end; // end position
    double distance; // distance traveled
    std::string strategy; // movement strategy
    std::string deliveryType; // uber or uberEats
};

#endif /* DATA_H */
