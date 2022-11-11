#ifndef SPEEDCONTROLSCREEN_H
#define SPEEDCONTROLSCREEN_H

#include "screen.h"

class SpeedControlScreen : public Screen
{
public:
    SpeedControlScreen();
    ~SpeedControlScreen();
    void process() override;

private:
    static std::string TEXT_SPEED_UP;
    static std::string TEXT_SPEED_DOWN;
    static std::string TEXT_BREAK;
    static std::string TEXT_BACK_TO_MENU;

    bool isValidInput() override;
    int mChoice;
};

#endif // SPEEDCONTROLSCREEN_H
