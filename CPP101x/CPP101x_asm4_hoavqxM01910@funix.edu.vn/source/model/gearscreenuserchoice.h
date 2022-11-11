#ifndef GEARSCREENUSERCHOICE_H
#define GEARSCREENUSERCHOICE_H

#include "userchoice.h"

class GearScreenUserChoice : public UserChoice
{

public:
    enum Choice{
        UNKNOWN_CHOICE = 0,
        GEAR_P,
        GEAR_R,
        GEAR_N,
        GEAR_D,
        POWER_OFF,
        CONFIG_PERSONAL_KEY,
        CONFIG_SPEED_AND_SAFE_DISTANCE,
    };
    GearScreenUserChoice(const GearScreenUserChoice::Choice& choice);
    ~GearScreenUserChoice();

    Choice choice() const;
    void setChoice(Choice newChoice);

private:
    Choice mChoice;
};
#endif // GEARSCREENUSERCHOICE_H
