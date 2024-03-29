#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "drone.h"
#include "robot.h"
#include "tree.h"

int main(int argc, char **argv)
{
  // Initialize the number of iterations and simulation dt
  int iterations = 3;
  double dt = 0.1;
  if (argc > 1)
  {
    iterations = std::atoi(argv[1]);
    dt = std::atof(argv[2]);
  }

  // Create two drones (Drone-A and Drone-X) and set their
  // initial velocity and rotation.
  std::unique_ptr<Drone> mainDrone = std::unique_ptr<Drone>(new Drone("Drone-A"));
  std::unique_ptr<Drone> droneX = std::unique_ptr<Drone>(new Drone("Drone-X"));
  std::vector<double> velocity;
  velocity.push_back(1);
  velocity.push_back(0);
  velocity.push_back(1);
  mainDrone->SetVelocity(velocity);
  mainDrone->Rotate(M_PI / 4.0);
  droneX->SetVelocity(velocity);
  velocity.clear();

  // Create a vector that holds entities (simulation entities).
  // This includes anything that inherits from Entity.
  // Add some entities to the vector.
  std::vector<std::unique_ptr<Entity>> entities;
  entities.push_back(std::move(mainDrone));
  entities.push_back(std::unique_ptr<Tree>(new Tree("Oak", 50.0, 50.0)));
  entities.push_back(std::unique_ptr<Robot>(new Robot("Johnny-Five", 1.0)));
  entities.push_back(std::unique_ptr<Tree>(new Tree("Maple", 100.0, 100.0)));
  entities.push_back(std::move(droneX));
  entities.push_back(std::unique_ptr<Robot>(new Robot("Dave", 4)));

  // Iteratively call several simulation steps (iterations)
  for (int iteration = 0; iteration < iterations; iteration++)
  {
    // Output the time step
    std::cout << "Time = " << (iteration * dt) << ":" << std::endl;
    std::cout << "--------------" << std::endl;

    // Loop through the entities
    for (int i = 0; i < entities.size(); i++)
    {
      // Print out the current entity
      Entity &entity = *entities[i];
      std::cout << entity.GetName();
      std::vector<double> pos = entity.GetPosition();
      for (size_t i = 0; i < pos.size(); i++)
      {
        std::cout << ", " << pos[i];
      }
      
      std::cout << std::endl;
      

      // Update all movable entities (entities that have an update function)
      // E.g. Trees do not update, but drones and robots will.
      MovableEntity *movable = dynamic_cast<MovableEntity *>(entities[i].get());
      if (movable != NULL)
      {
        movable->Update(dt);
      }
    }
    std::cout << std::endl;
  }

  std::cout << "Simulation Complete" << std::endl;

  return 0;
}
