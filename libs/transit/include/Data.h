#ifndef DATA_H
#define DATA_H

#include <string>
#include "vector3.h"

class Data {
public:
    // constructor should also save all data
    Data(Vector3 start, Vector3 end, double distance, std::string strategy, std::string deliveryType);

    std::string toString(std::ofstream& stream) const;

private:
    // any data we want to save
    Vector3 start;
    Vector3 end;
    double distance;
    std::string strategy;
    std::string deliveryType;
};

#endif /* DATA_H */
