#include "Handler.h"

void Handler::setTrip(Drone* drone) {
  IEntity* nearestEntity = drone->GetNearestEntity();

  // add trip to vector here
  drone->SetData(dynamic_cast<Robot*>(nearestEntity)->getData());
  drone->GetData()->nameOfDrone(drone->GetDetails()["name"]);
  std::cout << "the name of this drone is" << drone->GetDetails()["name"]
            << std::endl;

  drone->SetAvailability(false);
  nearestEntity->SetAvailability(false);
  drone->SetPickedUp(false);

  // maybe flip dest and pos if we are moving to stuff
  Vector3 dest, finalDestination;
  if (drone->GetData()->getRestaurantName() == "") {
    dest = nearestEntity->GetPosition();
    drone->SetDestination(dest);
    finalDestination = nearestEntity->GetDestination();
  } else {
    dest = nearestEntity->GetDestination();
    drone->SetDestination(dest);
    finalDestination = nearestEntity->GetPosition();
  }

  drone->SetToRobot(new BeelineStrategy(drone->GetPosition(), dest));

  std::string strat = nearestEntity->GetStrategyName();
  if (strat == "astar") {
    drone->SetToFinalDestination(new JumpDecorator(
        new AstarStrategy(dest, finalDestination, drone->GetGraph())));
  } else if (strat == "dfs") {
    drone->SetToFinalDestination(new SpinDecorator(new JumpDecorator(
        new DfsStrategy(dest, finalDestination, drone->GetGraph()))));
  } else if (strat == "dijkstra") {
    drone->SetToFinalDestination(new JumpDecorator(new SpinDecorator(
        new DijkstraStrategy(dest, finalDestination, drone->GetGraph()))));
  } else {
    drone->SetToFinalDestination(new BeelineStrategy(dest, finalDestination));
  }
}
