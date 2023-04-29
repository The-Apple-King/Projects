#ifndef DRONE1FOOD_H_
#define DRONE1FOOD_H_

#include "Handler.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Drone1Food : public Handler {
    public:

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        void handle_request(Drone& drone, std::vector<IEntity*> scheduler);

    private:
        Handler* next_handler;

};

#endif