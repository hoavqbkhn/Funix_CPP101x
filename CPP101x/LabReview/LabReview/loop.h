#ifndef LOOP_H
#define LOOP_H
#include "pollinglogichandler.h"
#include "task.h"

class Loop
{
public:

    Loop();
    void mainLoop(Task& t);

};

#endif // LOOP_H
