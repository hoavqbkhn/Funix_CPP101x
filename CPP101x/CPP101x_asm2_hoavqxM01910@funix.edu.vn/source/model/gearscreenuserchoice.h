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
        POWER_OFF
    };
    GearScreenUserChoice(const GearScreenUserChoice::Choice& choice);
    ~GearScreenUserChoice();

    Choice choice() const;
    void setChoice(Choice newChoice);

private:
    Choice mChoice;
};
#endif // GEARSCREENUSERCHOICE_H
