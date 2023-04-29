#include "Handler.h"

class ConcreteHandler : public Handler {
    public:
        void handle_request(Drone& drone, std::vector<IEntity*> scheduler) override {
            if (drone.GetAvailability())
            {
                drone.GetNearestEntity(scheduler);
            }
            else{
                next_handler->handle_request(drone, scheduler);
            }
        }

    private:
        Handler* next_handler = nullptr;
};
