#ifndef USERCONFIGLIMITSPEEDANDSAFEDISTANCE_H
#define USERCONFIGLIMITSPEEDANDSAFEDISTANCE_H
#include <map>

#include "userchoice.h"

class UserConfigLimitSpeedAndSafeDistance : public UserChoice
{
public:

    enum Choice{
      YES = 0,
      NO,
    };

    UserConfigLimitSpeedAndSafeDistance(const UserConfigLimitSpeedAndSafeDistance::Choice& choice);
    ~UserConfigLimitSpeedAndSafeDistance();

    const std::map<int, int> &newConfigSpeedAndSafeDistance() const;
    void setNewConfigSpeedAndSafeDistance(const std::map<int, int> &newNewConfigSpeedAndSafeDistance);

    Choice choice() const;
    void setChoice(Choice newChoice);

private:
    std::map<int, int> mNewConfigSpeedAndSafeDistance;
    Choice mChoice;

};

#endif // USERCONFIGLIMITSPEEDANDSAFEDISTANCE_H
