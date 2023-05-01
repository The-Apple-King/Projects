#include "Drone2FoodHandler.h"

#include "Drone1FoodHandler.h"

Drone2Food::Drone2Food() {
  next_handler = dynamic_cast<Handler*>(new Drone1Food());
}

void Drone2Food::handle_request(std::vector<Drone*> drones,
                                    std::vector<IEntity*> scheduler) {
  for (size_t i = 0; i < drones.size(); i++) {
    if (drones[i]->GetName() == "Drone2" && drones[i]->GetAvailability()) {
      float minDis = std::numeric_limits<float>::max();
      for (auto entity : scheduler) {
        if (entity->GetAvailability()) {
          Robot* temp = dynamic_cast<Robot*>(entity);
          if (temp != nullptr && !temp->getOrderType()) {  // if food
            float disToEntity = drones[i]->GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
              minDis = disToEntity;
              drones[i]->SetNearestEntity(entity);
            }
          }
        }
      }
      break;
    }
  }
  if (next_handler != nullptr) {
    next_handler->handle_request(drones, scheduler);
  }
}
