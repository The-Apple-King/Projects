#include "Drone1UberHandler.h"

#include "Drone2FoodHandler.h"

Drone1Uber::Drone1Uber() { next_handler = new Drone2Food(); }

void Drone1Uber::handle_request(std::vector<Drone*> drones,
                                    std::vector<IEntity*> scheduler) {
  for (size_t i = 0; i < drones.size(); i++) {
    if (drones[i]->GetName() == "Drone1" && drones[i]->GetAvailability()) {
      float minDis = std::numeric_limits<float>::max();
      for (auto entity : scheduler) {
        if (entity->GetAvailability()) {
          Robot* temp = dynamic_cast<Robot*>(entity);
          if (temp != nullptr && temp->getOrderType()) {  // if uber
            float disToEntity =
                drones[i]->GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
              std::cout << "inside of the if" << std::endl;
              minDis = disToEntity;
              drones[i]->SetNearestEntity(entity);
            }
          }
        }
      }
    }
  }
  if (next_handler != nullptr) {
    next_handler->handle_request(drones, scheduler);
  }
}
