#ifndef VEHICLE_H
#define VEHICLE_H

#include <memory>

#include "../engine/engine.h"
#include "../screen/screenmanager.h"

class Vehicle
{
public:

    Vehicle(std::shared_ptr<Engine> gear, std::shared_ptr<ScreenManager> screenManager);
    virtual ~Vehicle();

    void exec();


private:
    std::shared_ptr<Engine> mEngine;
    std::shared_ptr<ScreenManager> mScreenManager;


};

#endif // VEHICLE_H
