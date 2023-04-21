#ifndef RESTAURANT_FACTORY_H_
#define RESTAURANT_FACTORY_H_

#include "Restaurant.h"
#include "IEntityFactory.h"

class RestaurantFactory : public IEntityFactory {
 public:

  virtual ~RestaurantFactory() {}

  IEntity* CreateEntity(JsonObject& entity);
} ;

#endif