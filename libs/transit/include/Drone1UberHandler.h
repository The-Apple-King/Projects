#ifndef DRONE1UBER_H_
#define DRONE1UBER_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 *
 */
class Drone1Uber : public Handler {
 public:
  /**
   * @brief Construct a new Drone 1 Uber object
   */
  Drone1Uber();

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

#endif  // DRONE1UBER_H_
