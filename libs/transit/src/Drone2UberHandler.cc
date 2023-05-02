#include "Drone2UberHandler.h"

Drone2Uber::Drone2Uber() { next_handler = nullptr; }

void Drone2Uber::handle_request(std::vector<Drone*> drones,
                                std::vector<IEntity*> scheduler) {
  bool assignedATask = false;
  for (size_t i = 0; i < drones.size(); i++) {
    if (drones[i]->GetName() == "Drone2" && drones[i]->GetAvailability()) {
      float minDis = std::numeric_limits<float>::max();
      for (auto entity : scheduler) {
        if (entity->GetAvailability()) {
          Robot* temp = dynamic_cast<Robot*>(entity);
          if (temp != nullptr && temp->getOrderType()) {  // if uber
            float disToEntity =
                drones[i]->GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
              std::cout << "made it to drone 2 uber if" << std::endl;
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
  else{
    return;
  }
}
