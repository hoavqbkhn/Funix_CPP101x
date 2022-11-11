#include "gearscreenuserchoice.h"

GearScreenUserChoice::GearScreenUserChoice(const Choice &choice)
    : UserChoice(GearScreen),
      mChoice(choice)
{

}

GearScreenUserChoice::~GearScreenUserChoice()
{

}

GearScreenUserChoice::Choice GearScreenUserChoice::choice() const
{
    return mChoice;
}

void GearScreenUserChoice::setChoice(Choice newChoice)
{
    mChoice = newChoice;
}

