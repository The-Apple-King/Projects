#ifndef HANDLER_H_
#define HANDLER_H_

#include <string>
#include "IEntity.h"
#include "Drone.h"

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Handler{
    public:

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        virtual void handle_request(Drone& drone, std::vector<IEntity*> scheduler) = 0;
        
        /**
         * @brief Set the next handler object
         * 
         * @param handler 
         */
        virtual void set_next_handler(Handler* handler) = 0;

       
    private:
        Handler* next_handler;

};

#endif