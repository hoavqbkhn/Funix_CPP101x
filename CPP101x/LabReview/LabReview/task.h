#ifndef TASK_H
#define TASK_H

#include "pollingworker.h"
#include "pollinglogichandler.h"
class Task : public PollingWorker
{

public:
    Task(std::shared_ptr<PollingLogicHandler> hd);
    void invoke();

};

#endif // TASK_H
