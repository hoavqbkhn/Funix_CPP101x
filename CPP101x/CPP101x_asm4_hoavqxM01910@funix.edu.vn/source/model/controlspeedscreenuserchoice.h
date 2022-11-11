#ifndef CONTROLSPEEDSCREENUSERCHOICE_H
#define CONTROLSPEEDSCREENUSERCHOICE_H
#include "userchoice.h"

class ControlSpeedScreenUserChoice : public UserChoice
{

public:
    enum Choice{
       UNKNOWN_CHOICE = 0,
       SPEED_UP,
       SPEED_DOWN,
       BREAK,
       BACK_TO_GEAR_MENU
    };
    ControlSpeedScreenUserChoice(const ControlSpeedScreenUserChoice::Choice& choice);
    ~ControlSpeedScreenUserChoice();

    Choice choice() const;
    void setChoice(Choice newChoice);

private:
    Choice mChoice;

};

#endif // CONTROLSPEEDSCREENUSERCHOICE_H
