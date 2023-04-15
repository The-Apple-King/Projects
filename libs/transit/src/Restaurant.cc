#include "Restaurant.h"

Restaurant::Restaurant(JsonObject& obj) : details(obj){
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};

    available = true;
}

Restaurant::~Restaurant() {
    delete toRandomPosition;
}
