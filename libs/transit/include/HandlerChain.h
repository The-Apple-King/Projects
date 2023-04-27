#ifndef HANDLER_H_
#define HANDKER_H_

#include "Handler.h"
/**
 * @brief This class is used to represent a Linked Chain of handlers. The head handler is
 * the first one to accept or deny the request. The request is passed down until one handler accepts
 * the request or every handler denies it.
 * 
 */

class HandlerChain {
    public:
        /**
         * @brief Construct a new Handler Chain object, head is initialized to null
         * 
         */
        HandlerChain(): head_handler(nullptr){}
        /**
         * @brief Add new handlers to the chain
         * 
         * @param handler Handler object
         */
        void add_handler(Handler* handler);
    private:
        Handler* head_handler;
};


#endif