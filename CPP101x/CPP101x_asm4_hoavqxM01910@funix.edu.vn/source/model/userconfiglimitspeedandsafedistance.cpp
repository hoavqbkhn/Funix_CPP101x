#include "userconfiglimitspeedandsafedistance.h"

UserConfigLimitSpeedAndSafeDistance::UserConfigLimitSpeedAndSafeDistance(const Choice &choice)
    : UserChoice(ConfigSpeedAndSafeDistanceScreen),
      mChoice(choice)
{

}

UserConfigLimitSpeedAndSafeDistance::~UserConfigLimitSpeedAndSafeDistance()
{

}

const std::map<int, int> &UserConfigLimitSpeedAndSafeDistance::newConfigSpeedAndSafeDistance() const
{
    return mNewConfigSpeedAndSafeDistance;
}

void UserConfigLimitSpeedAndSafeDistance::setNewConfigSpeedAndSafeDistance(const std::map<int, int> &newNewConfigSpeedAndSafeDistance)
{
    mNewConfigSpeedAndSafeDistance = newNewConfigSpeedAndSafeDistance;
}

UserConfigLimitSpeedAndSafeDistance::Choice UserConfigLimitSpeedAndSafeDistance::choice() const
{
    return mChoice;
}

void UserConfigLimitSpeedAndSafeDistance::setChoice(Choice newChoice)
{
    mChoice = newChoice;
}
