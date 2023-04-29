#include "Drone1UberHandler.h"

Drone1Uber::Drone1Uber(){
  next_handler = new Drone2Food();
}


void Drone1Uber::handle_request(Drone* drone, std::vector<IEntity*> scheduler) {
  if (drone->GetName() == "drone1") {
    float minDis = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      if (entity->GetAvailability()) {
        Robot* temp = dynamic_cast<Robot*>(entity);
        if (temp->getOrderType()) {  // if uber
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
