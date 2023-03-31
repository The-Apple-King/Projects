#ifndef HUMAN_H_
#define HUMAN_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a human in a physical system.
// Humans move using euler integration based on a specified
// velocity and direction.
/**
 * @class Human
 * @brief Represents a human in a physical system. Humans move using euler
 * integration based on a specified velocity and direction.
 */
class Human : public IEntity {
 public:
  /**
   * @brief Humans are created with a name
   * @param obj JSON object containing the human's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Human();

  /**
   * @brief Gets the speed of the human
   * @return The speed of the human
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the human
   * @return The position of the human
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the human
   * @return The direction of the human
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the human
   * @return The destination of the human
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the color of the human
   * @return The color of the human
   */
  std::string GetColor() const { return color; }

  /**
   * @brief Gets the details information of the human
   * @return The details information of the human
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the availability of the human
   * @return The availability of the human
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief finds another random destination to move to
   * 
   */
  void findDestination();

 /**
   * @brief Updates the human's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the position of the human
   * @param pos_ The new position of the human
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the human
   * @param dir_ The new direction of the human
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the human
   * @param des_ The new destination of the human
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the color of the human
   * @param col_ The new color of the human
   */
  void SetColor(std::string col_) { color = col_; }

  /**
   * @brief Rotates the human
   * @param angle The angle by which the human should be rotated
   */
  void Rotate(double angle);

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that humans cannot be copied.
   */
  Human(const Human& human) = delete;
  Human& operator=(const Human& human) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None";  // None means default color
  Vector3 destination;
  float speed;
  bool available;
  IStrategy* toRandomPosition = nullptr;
};

#endif
