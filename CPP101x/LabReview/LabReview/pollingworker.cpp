#include "pollingworker.h"


PollingWorker::PollingWorker(const std::shared_ptr<PollingLogicHandler>& logicHandler)
    : pollingLogicHandler_(logicHandler)
{

}

PollingWorker::~PollingWorker()
{

}

int PollingWorker::delayTime()
{
    return pollingLogicHandler_->delayTime();
}

void PollingWorker::raiseEvent(std::shared_ptr<PollingEvent> event)
{

}
