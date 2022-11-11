#include "vehicle.h"

Vehicle::Vehicle(std::shared_ptr<Engine> gear, std::shared_ptr<ScreenManager> screenManager)
    : mEngine(gear),
      mScreenManager(screenManager)
{

}

Vehicle::~Vehicle()
{
}

void Vehicle::exec()
{
    mEngine->start();
    mScreenManager->start();
}


