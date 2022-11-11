#include "engine.h"
Engine::Engine()
{

}

Engine::~Engine()
{

}



int Engine::state() const
{
    return mState;
}

void Engine::setState(int newState)
{
    mState = newState;
}


int Engine::speed() const
{
    return mSpeed;
}

void Engine::setSpeed(int newSpeed)
{
    mSpeed = newSpeed;
}
