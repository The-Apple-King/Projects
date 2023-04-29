#include "Drone1FoodHandler.h"

Drone1Food::Drone1Food(){
  next_handler = new Drone2Uber();
}

void Drone1Food::handle_request(Drone* drone, std::vector<IEntity*> scheduler) {
  if (drone->GetName() == "drone1") {
    float minDis = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      if (entity->GetAvailability()) {
        Robot* temp = dynamic_cast<Robot*>(entity);
        if (!temp->getOrderType()) {  // if food and no uber
          float disToEntity =
              drone->GetPosition().Distance(entity->GetPosition());
          if (disToEntity <= minDis) {
            minDis = disToEntity;
            drone->SetNearestEntity(entity);
          }
        }
      }
    }

  } else {
    if (next_handler != nullptr) {
      next_handler->handle_request(drone, scheduler);
    }
  }
}
