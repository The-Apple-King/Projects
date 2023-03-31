#ifndef PIRATE_FACTORY_H_
#define PIRATE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Pirate.h"

/**
 *@brief Pirate Factory to produce Pirates class.
 **/
class PirateFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~PirateFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
