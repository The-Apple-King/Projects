#include "Drone2FoodHandler.h"
#include "Drone1FoodHandler.h"

Drone2Food::Drone2Food(){
  next_handler = dynamic_cast<Handler*>(new Drone1Food());
}

IEntity* Drone2Food::handle_request(std::string name, Vector3 pos,
                                    std::vector<IEntity*> scheduler) {
  if (name == "Drone2") {
    float minDis = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      if (entity->GetAvailability()) {
        Robot* temp = dynamic_cast<Robot*>(entity);
        if (temp != nullptr && !temp->getOrderType()) {  // if food
          float disToEntity = pos.Distance(entity->GetPosition());
          if (disToEntity <= minDis) {
            minDis = disToEntity;
            return entity;
          }
        }
      }
    }
  }
  if (next_handler != nullptr) {
    return next_handler->handle_request(name, pos, scheduler);
  }
  else{
    return nullptr;
  }
}
