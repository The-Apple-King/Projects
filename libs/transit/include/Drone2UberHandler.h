#ifndef DRONE2UBER_H_
#define DRONE2UBER_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Drone2Uber : public Handler{
    public:

        /**
         * @brief Construct a new Drone 2 Uber object
         * 
         */
        Drone2Uber();

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        void handle_request(std::vector<Drone*> drones, std::vector<IEntity*> scheduler);

    private:
        Handler* next_handler;

};

#endif