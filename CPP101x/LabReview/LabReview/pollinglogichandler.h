#ifndef POLLINGLOGICHANDLER_H
#define POLLINGLOGICHANDLER_H

#include "pollingconfiguration.h"
#include "pollingevent.h"

#include <memory>

class PollingLogicHandler
{
public:
    PollingLogicHandler(std::shared_ptr<PollingConfiguration>);
    PollingLogicHandler();
    virtual ~PollingLogicHandler();

    int delayTime();

protected:

    void updateEvent(std::shared_ptr<PollingEvent> event);

private:
    int counter_;
    int delayTime_;;
    std::shared_ptr<PollingConfiguration> config_;

    void handleEventWorkerFree();
    void handleEventWorkerBusy();
};

#endif // POLLINGLOGICHANDLER_H
