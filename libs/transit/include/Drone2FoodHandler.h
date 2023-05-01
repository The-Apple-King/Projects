#ifndef DRONE2FOOD_H_
#define DRONE2FOOD_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Drone2Food : public Handler{
    public:

        /**
         * @brief Construct a new Drone 2 Food object
         * 
         */
        Drone2Food();

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        IEntity* handle_request(std::string name, Vector3 pos, std::vector<IEntity*> scheduler);

    private:
        Handler* next_handler;

};

#endif