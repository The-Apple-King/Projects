#include "Restaurant.h"

Restaurant::Restaurant(JsonObject& obj) : details(obj){
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};
    destination = {0, 0, 0};
    
    available = true;
}

Restaurant::~Restaurant() {}

// Menu MenuCreation() {}

