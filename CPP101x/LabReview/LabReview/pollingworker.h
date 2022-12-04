#ifndef POLLINGWORKER_H
#define POLLINGWORKER_H
#include "pollinglogichandler.h"
#include "pollingevent.h"
#include <memory>


class PollingWorker
{
public:
    PollingWorker(const std::shared_ptr<PollingLogicHandler>& logicHandler);
    virtual ~PollingWorker();

    int delayTime();
    void raiseEvent(std::shared_ptr<PollingEvent> event);

private:
    std::shared_ptr<PollingLogicHandler> pollingLogicHandler_;
};

#endif // POLLINGWORKER_H
