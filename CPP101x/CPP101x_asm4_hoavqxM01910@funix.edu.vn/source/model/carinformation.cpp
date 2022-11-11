#include "carinformation.h"

CarInformation::CarInformation(const GearState &state)
    : Message(Message::CAR_INFORMATION_MESSAGE),
      mState(state)
{
}

CarInformation::CarInformation(const GearState &state, int speed)
    : Message(Message::CAR_INFORMATION_MESSAGE),
      mState(state),
      mSpeed(speed)
{
}


CarInformation::~CarInformation()
{
}

GearState CarInformation::state() const
{
    return mState;
}

void CarInformation::setState(GearState newState)
{
    mState = newState;
}

int CarInformation::speed() const
{
    return mSpeed;
}

void CarInformation::setSpeed(int newSpeed)
{
    mSpeed = newSpeed;
}

void CarInformation::printCarInformation()
{
    printf("[TRANG THAI XE] GEAR = %s, TOC DO = %d km/h\n", getStrGear(state()).c_str(), speed());
}

std::string CarInformation::getStrGear(GearState gear)
{
    switch (gear) {
    case GEAR_P:
        return "P";
        break;
    case GEAR_R:
        return "R";
        break;
    case GEAR_N:
        return "N";
        break;
    case GEAR_D:
        return "D";
        break;
    case POWER_OFF:
        return "OFF";
        break;
    default:
        break;
    }
    return "";
}

