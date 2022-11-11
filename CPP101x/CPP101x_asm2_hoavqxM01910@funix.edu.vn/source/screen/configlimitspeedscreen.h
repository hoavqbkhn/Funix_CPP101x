#ifndef CONFIGLIMITSPEEDSCREEN_H
#define CONFIGLIMITSPEEDSCREEN_H
#include <string>

#include "screen.h"

using namespace std;

class ConfigLimitSpeedScreen: public Screen
{
public:
    ConfigLimitSpeedScreen();
    ~ConfigLimitSpeedScreen();

    void process() override;
private:
    bool isValidInput() override;
};

#endif // CONFIGLIMITSPEEDSCREEN_H
