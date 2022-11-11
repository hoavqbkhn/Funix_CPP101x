#ifndef CARINFORMATION_H
#define CARINFORMATION_H
#include <string>

#include "common.h"
#include "message.h"

class CarInformation : public Message
{
public:

    CarInformation(const GearState& state);
    CarInformation(const GearState& state, int speed);
    ~CarInformation();

    GearState state() const;
    void setState(GearState newState);

    int speed() const;
    void setSpeed(int newSpeed);

    void printCarInformation();


private:
    GearState mState{UNKNOWN_GEAR};
    int mSpeed{0};

    std::string getStrGear(GearState gear);
};

#endif // CARINFORMATION_H
