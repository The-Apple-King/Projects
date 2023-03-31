#include "Parrot.h"

Parrot::Parrot(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {(pos[0]), pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  //set on shoulder
  position.x = position.x +1;
  position.y = position.y +5;

}

JsonObject Parrot::GetDetails() const { return details; }

void Parrot::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
