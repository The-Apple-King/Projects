#ifndef PARROT_H
#define PARROT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @class Parrot
 * @brief Represents a parrot in a physical system
 *
 * Parrots move using euler integration based on a specified
 * velocity and direction.
 */
class Parrot : public IEntity {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the parrot's information
   */
  Parrot(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Parrot() override = default;

  /**
   * @brief Gets the parrot's position
   * @return The parrot's position
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the parrot's direction
   * @return The parrot's direction
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the parrot's destination
   * @return The parrot's destination
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the parrot's availability
   * @return The parrot's availability
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the parrot's details
   * @return The parrot's details
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Gets the parrot's speed
   * @return The parrot's speed
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Get the Strategy Name
   *
   * @return Streategy name
   */
  std::string GetStrategyName() const { return strategyName; }

  /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief Sets the parrot's availability
   * @param choice The new availability of the parrot
   */
  void SetAvailability(bool choice) {available = choice;};

  /**
   * @brief Sets the parrot's position
   * @param pos_ The new position of the parrot
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the parrot's direction
   * @param dir_ The new direction of the parrot
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the parrot's destination
   * @param des_ The new destination of the parrot
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates the parrot
   * @param angle The angle by which the parrot should be rotated
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H
