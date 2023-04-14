#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
public:
    // constructor should also save all data
    Data();

    std::string toString() const;

private:
    // any data we want to save
};

#endif /* DATA_H */
