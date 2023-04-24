#ifndef DATA_H
#define DATA_H

#include <string>
#include "math/vector3.h"
#include <sstream>

class Data {
public:
    // constructor should also save all data
    Data(Vector3 start, Vector3 end, double distance, std::string strategy, std::string deliveryType);

    std::string toString();

private:
    // any data we want to save
    Vector3 start;
    Vector3 end;
    double distance;
    std::string strategy;
    std::string deliveryType;
};

#endif /* DATA_H */
