#include "Dragon.h"

#include <cmath>
#include <limits>

#include "BeelineStrategy.h"

Dragon::Dragon(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};
  speed = obj["speed"];
  available = true;
  srand(time(NULL));
}

Dragon::~Dragon() {
  delete toRandomPosition;
  delete parrot;
}

void Dragon::findDestination() {
  destination = {((rand() % 2900) - 1400), 700, (rand() % 1600 - 800)};
  available = false;
  toRandomPosition = new BeelineStrategy(position, destination);
}

void Dragon::Update(double dt, std::vector<IEntity*> scheduler) {
  if (available) findDestination();

  if (toRandomPosition) {
    toRandomPosition->Move(this, dt);
    Rotate(8);
    if (toRandomPosition->IsCompleted()) {
      delete (toRandomPosition);
      toRandomPosition = nullptr;
      available = true;
    }
  }
}

void Dragon::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
