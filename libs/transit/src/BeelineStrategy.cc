#include "BeelineStrategy.h"
#include "Drone.h"

BeelineStrategy::BeelineStrategy(Vector3 position, Vector3 destination)
  : position(position), destination(destination) {}

void BeelineStrategy::Move(IEntity* entity, double dt) {
  if (IsCompleted())
    return;

  Vector3 dir = (destination - position).Unit();

  position = position + dir * entity->GetSpeed() * dt;
  entity->SetPosition(position);
  entity->SetDirection(dir);
  if(dynamic_cast<Drone*>(entity)){
    std::cout << "name: " << dynamic_cast<Drone*>(entity)->GetName();
    std::cout << "pos: " << entity->GetPosition()[0] << ", " << entity->GetPosition()[1] << ", " << entity->GetPosition()[2] << ", " << std::endl;
  }

}

bool BeelineStrategy::IsCompleted() {
  return position.Distance(destination) < 1.0;
}
