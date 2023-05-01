#include "Handler.h"

void Handler::setTrip(Drone* drone) {
  IEntity* nearestEntity = drone->GetNearestEntity();

  drone->SetAvailability(false);
  nearestEntity->SetAvailability(false);
  drone->SetPickedUp(false);

  // maybe flip dest and pos if we are moving to stuff
  Vector3 dest = nearestEntity->GetPosition();
  drone->SetDestination(dest);
  Vector3 finalDestination = nearestEntity->GetDestination();

  drone->SetToRobot(new BeelineStrategy(drone->GetPosition(), dest));

  std::string strat = nearestEntity->GetStrategyName();
  if (strat == "astar")
    drone->SetToFinalDestination(new JumpDecorator(
        new AstarStrategy(dest, finalDestination, drone->GetGraph())));
  else if (strat == "dfs")
    drone->SetToFinalDestination(new SpinDecorator(new JumpDecorator(
        new DfsStrategy(dest, finalDestination, drone->GetGraph()))));
  else if (strat == "dijkstra")
    drone->SetToFinalDestination(new JumpDecorator(new SpinDecorator(
        new DijkstraStrategy(dest, finalDestination, drone->GetGraph()))));
  else
    drone->SetToFinalDestination(new BeelineStrategy(dest, finalDestination));
}