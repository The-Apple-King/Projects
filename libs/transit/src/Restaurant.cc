#include "Restaurant.h"

Restaurant::Restaurant(JsonObject& obj) : details(obj){
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};
    
    available = true;


    // fix this if you want, use an if for name then menu for it
    menu = {"burger", "fries", "soda"};
}

Restaurant::~Restaurant() {}

// Menu MenuCreation() {}

