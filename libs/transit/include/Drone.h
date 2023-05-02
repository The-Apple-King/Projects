#ifndef DRONE_H_
#define DRONE_H_

#include <time.h> /* time */

#include <vector>

#include "Data.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "Robot.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Gets the speed of the drone
   * @return The speed of the drone
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the drone
   * @return The position of the drone
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the drone
   * @return The direction of the drone
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the drone
   * @return The destination of the drone
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the color of the drone
   * @return The color of the drone
   */
  std::string GetColor() const { return color; }

  /**
   * @brief Gets the details information of the drone
   * @return The details information of the drone
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the availability of the drone
   * @return The availability of the drone
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief return name of drone
   *
   * @return std::string name of drone
   */
  std::string GetName() { return name; }

  Data* GetData(){ return trip; }

  /**
   * @brief returns the nearest entity
   * 
   * @return IEntity* 
   */
  IEntity* GetNearestEntity() {return nearestEntity;}

  /**
   * @brief Get the Graph object
   * 
   * @return IGraph* 
   */
  const IGraph* GetGraph(){ return graph;}

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the position of the drone
   * @param pos_ The new position of the drone
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the drone
   * @param dir_ The new direction of the drone
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the drone
   * @param des_ The new destination of the drone
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the color of the drone
   * @param col_ The new color of the drone
   */
  void SetColor(std::string col_) { color = col_; }

  /**
   * @brief Set the Nearest Entity object
   *
   * @param nearest nearest entity object
   */
  void SetNearestEntity(IEntity* nearest) { nearestEntity = nearest; }

  /**
   * @brief Set the value of available
   *
   * @param val the value of available
   */
  void SetAvailability(bool val) { 
    available = val; 
    std::cout << "we updated avail to " << val << std::endl;
    std::cout << "its new val is " << available << std::endl;
    }

  /**
   * @brief Set the value of picked up
   *
   * @param val wether object picked up
   */
  void SetPickedUp(bool val) { pickedUp = val; }

  /**
   * @brief Set the data stored in drone
   * 
   * @param data the data object
   */
  void SetData(Data* data){ trip = data;}

  /**
   * @brief Set the first half of the trip
   *
   * @param strat strategy to move to destination
   */
  void SetToRobot(IStrategy* strat) { toRobot = strat; }

  /**
   * @brief Set the final half of the trip
   *
   * @param strat strategy to move to destination
   */
  void SetToFinalDestination(IStrategy* strat) { toFinalDestination = strat; }

  /**
   * @brief Rotates the drone
   * @param angle The angle by which the drone should be rotated
   */
  void Rotate(double angle);

  /**
   * @brief Makes the drone jump
   * @param height The height at which the drone should jump
   */
  void Jump(double height);

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that drones cannot be copied.
   */
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;
  Data* trip;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None";  // None means default color
  float jumpHeight = 0;
  bool available;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool pickedUp;
  IEntity* nearestEntity = nullptr;
  IStrategy* toRobot = nullptr;
  IStrategy* toFinalDestination = nullptr;
  std::string name;
};

#endif
