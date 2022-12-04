#ifndef POLLINGEVENT_H
#define POLLINGEVENT_H


class PollingEvent
{
public:
    enum EventType{
        WORKER_FREE = 0,
        WORKER_BUSY
    };

    PollingEvent(EventType);
    virtual ~PollingEvent();

    EventType eventType() const;

private:
    EventType eventType_;
};

#endif // POLLINGEVENT_H
