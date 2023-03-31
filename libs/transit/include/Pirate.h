#ifndef PIRATE_H_
#define PIRATE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a pirate in a physical system.
// Pirates move using euler integration based on a specified
// velocity and direction.
/**
 * @class Pirate
 * @brief Represents a pirate in a physical system. Pirates move using euler
 * integration based on a specified velocity and direction.
 */
class Pirate : public IEntity {
 public:
  /**
   * @brief Pirates are created with a name
   * @param obj JSON object containing the pirate's information
   */
  Pirate(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Pirate();

  /**
   * @brief Gets the speed of the pirate
   * @return The speed of the pirate
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the pirate
   * @return The position of the pirate
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the pirate
   * @return The direction of the pirate
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the pirate
   * @return The destination of the pirate
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the color of the pirate
   * @return The color of the pirate
   */
  std::string GetColor() const { return color; }

  /**
   * @brief Gets the details information of the pirate
   * @return The details information of the pirate
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the availability of the pirate
   * @return The availability of the pirate
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief finds another random destination to move to
   * 
   */
  void findDestination();

 /**
   * @brief Updates the pirate's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the position of the pirate
   * @param pos_ The new position of the pirate
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the pirate
   * @param dir_ The new direction of the pirate
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the pirate
   * @param des_ The new destination of the pirate
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the color of the pirate
   * @param col_ The new color of the pirate
   */
  void SetColor(std::string col_) { color = col_; }

  /**
   * @brief Rotates the pirate
   * @param angle The angle by which the pirate should be rotated
   */
  void Rotate(double angle);

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that pirates cannot be copied.
   */
  Pirate(const Pirate& pirate) = delete;
  Pirate& operator=(const Pirate& pirate) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None";  // None means default color
  Vector3 destination;
  float speed;
  bool available;
  IStrategy* toRandomPosition = nullptr;
  IEntity* parrot = nullptr;
};

#endif
