#include "pollinglogichandler.h"


PollingLogicHandler::PollingLogicHandler(std::shared_ptr<PollingConfiguration> config)
    : config_(config)
{

}

PollingLogicHandler::PollingLogicHandler()
{

}

PollingLogicHandler::~PollingLogicHandler()
{

}

int PollingLogicHandler::delayTime()
{
    return delayTime_;
}


void PollingLogicHandler::updateEvent(std::shared_ptr<PollingEvent> event)
{
    switch (event->eventType()) {
    case PollingEvent::WORKER_BUSY:
        handleEventWorkerBusy();
        break;

    case PollingEvent::WORKER_FREE:
        handleEventWorkerFree();
        break;

    default:
        break;
    }
}

void PollingLogicHandler::handleEventWorkerFree()
{
    counter_ = 0;
    delayTime_ = 0;
}

void PollingLogicHandler::handleEventWorkerBusy()
{
    if(counter_ > 0 && counter_ <= 10){
        delayTime_ = 1;
    }else if(counter_ > 10 && counter_ <= 20){
        delayTime_ = 3;
    }else{
        delayTime_ = 5;
    }
}
