#ifndef HANDLER_H_
#define HANDKER_H_

#include "Request.h"
#include <string>

/**
 * @brief Handler class interface to allow creation of new handlers.
 * 
 */
class Handler{
    public:

        /**
         * @brief Checks to see if the handler can handle, if not pass request onto next handler
         * 
         * @param request 
         * @return true if the handler can handle it
         * @return false if the handler can't handle it
         */
        virtual bool can_handle_request(Request& request) = 0;

        /**
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        virtual void handle_request(Request& request) = 0;

        /**
         * @brief Get the next handler object
         * 
         * @return Handler* 
         */
       
        virtual Handler* get_next_handler() = 0;
        
        /**
         * @brief Set the next handler object
         * 
         * @param handler 
         */
        virtual void set_next_handler(Handler* handler) = 0;

       
    private:
        Request* request;
        Handler* next_handler;
        
        

};

#endif