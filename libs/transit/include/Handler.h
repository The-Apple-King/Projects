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
         * @brief Function to handle the request that is passed.
         * 
         * @param request Request to process
         */
        virtual void handle_request(Request& request) = 0;
    private:
        Request* request;
};

#endif