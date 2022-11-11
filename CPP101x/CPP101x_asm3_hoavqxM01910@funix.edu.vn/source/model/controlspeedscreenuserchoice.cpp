#include "controlspeedscreenuserchoice.h"


ControlSpeedScreenUserChoice::ControlSpeedScreenUserChoice(const Choice &choice)
    : UserChoice(ControlSpeedScreen),
      mChoice(choice)
{

}

ControlSpeedScreenUserChoice::~ControlSpeedScreenUserChoice()
{

}

ControlSpeedScreenUserChoice::Choice ControlSpeedScreenUserChoice::choice() const
{
    return mChoice;
}

void ControlSpeedScreenUserChoice::setChoice(Choice newChoice)
{
    mChoice = newChoice;
}
