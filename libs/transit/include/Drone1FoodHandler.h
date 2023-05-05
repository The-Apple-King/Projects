#ifndef DRONE1FOOD_H_
#define DRONE1FOOD_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 *
 */
class Drone1Food : public Handler {
 public:
  /**
   * @brief Construct a new Drone 1 Food object
   */
  Drone1Food();

  /**
   * @brief Function to handle the request that is passed.
   *
   * @param drones The drone requesting the delivery
   * @param scheduler The list of available robots to assign to the delivery
   */
  void handle_request(std::vector<Drone*> drones,
                      std::vector<IEntity*> scheduler);

 private:
  Handler* next_handler;
};

#endif  // DRONE1FOOD_H_
