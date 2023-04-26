#ifndef EFFICIENT_H_
#define EFFICIENT_H_

#include "Handler.h"

/**
 * @brief This class is a handler that will accept if the drone that is closest is not available
 * and instead uses the drone that takes less overall time
 * 
 */
class MostEfficientHandler: public Handler{
    public:
        MostEfficientHandler(Handler* next_handler = nullptr) : next_handler(next_handler){}
        void handle_request(Request& request);
    private:
        Handler* next_handler;
};
#endif