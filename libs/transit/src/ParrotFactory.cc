#include "ParrotFactory.h"

IEntity* ParrotFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("parrot") == 0) {
    std::cout << "parrot Created" << std::endl;
    return new Parrot(entity);
  }
  return nullptr;
}
