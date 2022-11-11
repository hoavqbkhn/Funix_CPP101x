#include "car.h"


Car::Car(std::shared_ptr<CarEngine> gear, std::shared_ptr<CarScreenManager> screenManager)
    : Vehicle(gear, screenManager)
{

}

Car::~Car()
{

}

