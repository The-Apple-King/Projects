#ifndef DRONE1UBER_H_
#define DRONE1UBER_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Drone1Uber : public Handler{
    public:

        /**
         * @brief Construct a new Drone 1 Uber object
         * 
         */
        Drone1Uber();

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