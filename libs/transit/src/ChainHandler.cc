#include "HandlerChain.h"


void HandlerChain::add_handler(Handler* handler) {
    if (head_handler == nullptr) {
        head_handler = handler;
    }
    else {
        Handler* current_handler = head_handler;
        while (current_handler->get_next_handler() != nullptr) {
            current_handler = current_handler->get_next_handler();
        }
        current_handler->set_next_handler(handler);
    }
}

