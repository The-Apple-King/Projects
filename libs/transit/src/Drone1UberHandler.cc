#include "Drone1UberHandler.h"
#include "Drone2FoodHandler.h"

Drone1Uber::Drone1Uber() { next_handler = new Drone2Food(); }

IEntity* Drone1Uber::handle_request(std::string name, Vector3 pos,
                                    std::vector<IEntity*> scheduler) {
  if (name == "drone1") {
    float minDis = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      if (entity->GetAvailability()) {
        Robot* temp = dynamic_cast<Robot*>(entity);
        if (temp != nullptr && temp->getOrderType()) {  // if uber
          float disToEntity = pos.Distance(entity->GetPosition());
          if (disToEntity <= minDis) {
            minDis = disToEntity;
            std::cout << "returning entity, " << entity << std::endl;
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
