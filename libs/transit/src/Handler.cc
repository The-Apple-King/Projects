#include "Handler.h"

void Handler::setTrip(Drone* drone) {
  IEntity* nearestEntity = drone->GetNearestEntity();

  // add trip to vector here
      drone->trip = dynamic_cast<Robot*>(nearestEntity)->getData();
      drone->trip->nameOfDrone(drone->GetDetails()["name"]);
      std::cout << "the name of this drone is" << drone->GetDetails()["name"]
                << std::endl;
  //std::cout << nearestEntity << std::endl;

  drone->SetAvailability(false);
  drone->available = false;
  std::cout << "drone available: " << drone->GetAvailability() << std::endl;
  nearestEntity->SetAvailability(false);
  //std::cout << "nearest entity available: " << nearestEntity->GetAvailability() << std::endl;
  drone->SetPickedUp(false);

  // maybe flip dest and pos if we are moving to stuff
  Vector3 dest = nearestEntity->GetPosition();
  //std::cout << nearestEntity->GetPosition()[0] << ", " << nearestEntity->GetPosition()[1] << ", " << nearestEntity->GetPosition()[2] << ", " << std::endl;
  drone->SetDestination(dest);
  //std::cout << drone->GetDestination()[0] << ", " << drone->GetDestination()[1] << ", " << drone->GetDestination()[2] << ", " << std::endl;
  Vector3 finalDestination = nearestEntity->GetDestination();
  //std::cout << finalDestination[0] << ", " << finalDestination[1] << ", " << finalDestination[2] << ", " << std::endl;

  drone->SetToRobot(new BeelineStrategy(drone->GetPosition(), dest));

  std::string strat = nearestEntity->GetStrategyName();
  if (strat == "astar") {
    //std::cout << "astar" << std::endl;
    drone->SetToFinalDestination(new JumpDecorator(
        new AstarStrategy(dest, finalDestination, drone->GetGraph())));
  } else if (strat == "dfs") {
    //std::cout << "dfs" << std::endl;
    drone->SetToFinalDestination(new SpinDecorator(new JumpDecorator(
        new DfsStrategy(dest, finalDestination, drone->GetGraph()))));
  } else if (strat == "dijkstra") {
    //std::cout << "dijkstra" << std::endl;
    drone->SetToFinalDestination(new JumpDecorator(new SpinDecorator(
        new DijkstraStrategy(dest, finalDestination, drone->GetGraph()))));
  } else {
    //std::cout << "beeline" << std::endl;
    drone->SetToFinalDestination(new BeelineStrategy(dest, finalDestination));
  }
}