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
        * @brief Checks to see if the handler can handle, if not pass request onto next handler
        * 
        * @param request 
        * @return true if the handler can handle it
        * @return false if the handler can't handle it
        */
        bool can_handle_request(Request& request)
        
        /**
         * @brief Function to handle the request
         * 
         * @param request request to process
         */
        void handle_request(Request& request);

        /**
         * @brief Get the next handler object
         * 
         * @return Handler* 
         */
        Handler* get_next_handler();

        /**
         * @brief Set the next handler object
         * 
         * @param handler 
         */
        void set_next_handler(Handler* handler);
    private:
        Handler* next_handler;
};
#endif