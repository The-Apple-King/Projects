#ifndef DRONE1UBER_H_
#define DRONE1UBER_H_

#include <string>
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
        void handle_request(Drone* drone, std::vector<IEntity*> scheduler);

    private:
        Handler* next_handler;

};

#endif