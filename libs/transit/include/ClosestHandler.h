#ifndef CLOSEST_H_
#define CLOSEST_H_

#include "Handler.h"
/**
 * @brief This class is a handler that will accept if the drone that is closest is available
 * 
 */
class ClosestHandler: public Handler{
    public:
        /**
         * @brief Construct a new Closest Handler object
         * 
         * @param next_handler pointer to next handler in the chain
         */
        ClosestHandler(Handler* next_handler = nullptr) : next_handler(next_handler){}
        /**
         * @brief Function to handle the request
         * 
         * @param request request to process
         */
        void handle_request(Request& request);
    private:
        Handler* next_handler;
};
#endif