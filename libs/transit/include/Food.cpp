#include <iostream>
#include <unordered_map>
#include <string>

class Food {
private:
    std::string name;
    double price;

public:
    Food(std::string name, double price) {
        this->name = name;
        this->price = price;
    }

    std::string getName() {
        return name;
    }
};