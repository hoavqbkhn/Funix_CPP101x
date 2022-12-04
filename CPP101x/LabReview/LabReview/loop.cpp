#include "loop.h"

Loop::Loop()
{
}

void Loop::mainLoop(Task& t)
{
    for(;;){
        t.invoke();
        _sleep(t.delayTime());
    }
}
