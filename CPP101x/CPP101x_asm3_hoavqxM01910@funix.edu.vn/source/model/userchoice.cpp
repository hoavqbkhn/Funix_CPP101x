#include "userchoice.h"


UserChoice::UserChoice(const ScreenType &type)
    : mScreenType(type)
{

}

UserChoice::~UserChoice()
{

}

UserChoice::ScreenType UserChoice::screenType() const
{
    return mScreenType;
}

void UserChoice::setScreenType(ScreenType newScreenType)
{
    mScreenType = newScreenType;
}

