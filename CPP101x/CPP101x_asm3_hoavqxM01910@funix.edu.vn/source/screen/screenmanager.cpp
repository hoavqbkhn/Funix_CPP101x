#include "screenmanager.h"


ScreenManager::ScreenManager()
{

}

ScreenManager::~ScreenManager()
{

}

const std::shared_ptr<Screen> &ScreenManager::screen() const
{
    return mScreen;
}

void ScreenManager::setScreen(const std::shared_ptr<Screen> &newScreen)
{
    mScreen = newScreen;
}

void ScreenManager::clearScreen()
{
    system("cls");
}



