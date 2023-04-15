#include "RestaurantFactory.h"

IEntity* RestaurantFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("Restaurant") == 0) {
    std::cout << "Restaurant Created" << std::endl;
    return new Restaurant(entity);
  }
  return nullptr;
}