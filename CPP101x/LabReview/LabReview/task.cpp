#include "task.h"
#include <iostream>
Task::Task(std::shared_ptr<PollingLogicHandler> hd)
    : PollingWorker(hd)
{

}

void Task::invoke()
{
    std::cout << "Task invoke" << std::endl;
}
