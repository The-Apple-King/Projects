#ifndef PARROT_FACTORY_H_
#define PARROT_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Parrot.h"

/**
 *@brief Parrot Factory to produce Pirates class.
 **/
class ParrotFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~ParrotFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
