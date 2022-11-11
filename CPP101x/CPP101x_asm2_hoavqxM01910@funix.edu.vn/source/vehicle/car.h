#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include "../engine/carengine.h"
#include "../screen/carscreenmanager.h"
class Car : public Vehicle
{
public:
    Car(std::shared_ptr<CarEngine> gear, std::shared_ptr<CarScreenManager> screenManager);
    ~Car();

private:


};

#endif // CAR_H
