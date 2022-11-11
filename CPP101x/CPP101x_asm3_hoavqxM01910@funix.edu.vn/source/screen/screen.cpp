#include "screen.h"

Screen::Screen()
{

}

Screen::~Screen()
{

}

const std::string &Screen::getInput() const
{
    return mInput;
}

const std::shared_ptr<UserChoice> &Screen::userChoice() const
{
    return mUserChoice;
}

void Screen::setInput(const std::string &newInput)
{
    mInput = newInput;
}

void Screen::setUserChoice(const std::shared_ptr<UserChoice> &newUserChoice)
{
    mUserChoice = newUserChoice;
}

