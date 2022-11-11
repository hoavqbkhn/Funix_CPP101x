#include "vehicle/car.h"
#include "engine/carengine.h"
#include "screen/carscreenmanager.h"

int main()
{
    //Driving car
    Vehicle *v = new Car(std::make_shared<CarEngine>(), std::make_shared<CarScreenManager>());
    v->exec();
    system("pause");

    return 0;
}

