#include "pollingevent.h"



PollingEvent::PollingEvent(EventType evType)
    : eventType_(evType)
{

}

PollingEvent::~PollingEvent()
{

}

PollingEvent::EventType PollingEvent::eventType() const
{
    return eventType_;
}
