#ifndef HUMAN_FACTORY_H_
#define HUMAN_FACTORY_H_

#include <vector>

#include "Human.h"
#include "IEntityFactory.h"

/**
 * @brief Human Factory to produce Humans class.
 **/
class HumanFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~HumanFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   *
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a null
   *pointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity) override;
};

#endif  // HUMAN_FACTORY_H_
