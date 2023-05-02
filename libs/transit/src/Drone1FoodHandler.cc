#include "Drone1FoodHandler.h"

#include "Drone2UberHandler.h"

Drone1Food::Drone1Food() { next_handler = new Drone2Uber; }

void Drone1Food::handle_request(std::vector<Drone*> drones,
                                    std::vector<IEntity*> scheduler) {
  bool assignedATask = false;
  for (size_t i = 0; i < drones.size(); i++) {
    if (drones[i]->GetName() == "Drone1" && drones[i]->GetAvailability()) {
      float minDis = std::numeric_limits<float>::max();
      for (auto entity : scheduler) {
        if (entity->GetAvailability()) {
          Robot* temp = dynamic_cast<Robot*>(entity);
          if (temp != nullptr && !temp->getOrderType()) {  // if Food
            float disToEntity = drones[i]->GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
              assignedATask = true;
              minDis = disToEntity;
              drones[i]->SetNearestEntity(entity);
            }
          }
        }
      }
      if (drones[i]->GetNearestEntity()) {
        drones[i]->SetAvailability(false);
        setTrip(drones[i]);
      }
    }
  }
  if (next_handler != nullptr && !assignedATask) {
    next_handler->handle_request(drones, scheduler);
  }
}
