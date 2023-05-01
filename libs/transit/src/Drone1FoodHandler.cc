#include "Drone1FoodHandler.h"
#include "Drone2UberHandler.h"

Drone1Food::Drone1Food(){
  next_handler = new Drone2Uber;
}

IEntity* Drone1Food::handle_request(std::string name, Vector3 pos,
                                    std::vector<IEntity*> scheduler) {
  if (name == "drone1") {
    float minDis = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      if (entity->GetAvailability()) {
        Robot* temp = dynamic_cast<Robot*>(entity);
        if (temp != nullptr && !temp->getOrderType()) {  // if Food
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

