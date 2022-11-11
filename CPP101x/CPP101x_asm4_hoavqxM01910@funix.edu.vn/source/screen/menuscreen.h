#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screen.h"


class MenuScreen : public Screen
{
public:
    MenuScreen();
    ~MenuScreen();
    void process() override;


private:
    static std::string TEXT_GEAR_P;
    static std::string TEXT_GEAR_R;
    static std::string TEXT_GEAR_N;
    static std::string TEXT_GEAR_D;
    static std::string TEXT_GEAR_POWER_OFF;
    static std::string TEXT_CONFIG_PERSONAL_KEY;
    static std::string TEXT_CONFIG_SPEED_AND_SAFE_DISTANCE;
    bool isValidInput() override;
    int mChoice;
};

#endif // MENUSCREEN_H
