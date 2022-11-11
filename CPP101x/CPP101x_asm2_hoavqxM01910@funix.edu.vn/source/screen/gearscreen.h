#ifndef GEARSCREEN_H
#define GEARSCREEN_H

#include "screen.h"


class GearScreen : public Screen
{
public:
    GearScreen();
    ~GearScreen();
    void process() override;


private:
    static std::string TEXT_GEAR_P;
    static std::string TEXT_GEAR_R;
    static std::string TEXT_GEAR_N;
    static std::string TEXT_GEAR_D;
    static std::string TEXT_GEAR_POWER_OFF;
    bool isValidInput() override;
    int mChoice;
};

#endif // GEARSCREEN_H
