#include "Pirate.h"
#include "Parrot.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"


Pirate::Pirate(JsonObject& obj) : details(obj){
    std::cout << "started making the parrot";

  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;

    srand (time(NULL));

    parrot = new Parrot(obj);
}

Pirate::~Pirate() {

}

void Pirate::findDestination(){
    destination = {((rand()%2900)-1400), 0, (rand()%1600 -800)};
    available = false;
    toRandomPosition = new AstarStrategy(position, destination, graph);
}

void Pirate::Update(double dt, std::vector<IEntity*> scheduler) {

    if(available)
        findDestination();

    if(toRandomPosition){
        toRandomPosition->Move(this, dt);
        if (toRandomPosition->IsCompleted())
        {
            delete(toRandomPosition);
            toRandomPosition = nullptr;
            available = true;
        }
    }
}

void Pirate::Rotate(double angle) {
    Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
