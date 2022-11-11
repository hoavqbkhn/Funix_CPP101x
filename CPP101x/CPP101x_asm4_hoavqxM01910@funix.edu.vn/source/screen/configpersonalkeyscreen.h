#ifndef CONFIGPERSONALKEYSCREEN_H
#define CONFIGPERSONALKEYSCREEN_H
#include "model/userupdatepersonalkey.h"
#include "screen.h"

class ConfigPersonalKeyScreen: public Screen
{
public:
    ConfigPersonalKeyScreen();
    ~ConfigPersonalKeyScreen();

    void process() override;

private:

    bool isValidInput() override;
    std::string mInput;

};

#endif // CONFIGPERSONALKEYSCREEN_H
