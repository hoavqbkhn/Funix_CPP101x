#include "common.h"
#include "model/controlspeedscreenuserchoice.h"
#include "speedcontrolscreen.h"

std::string SpeedControlScreen::TEXT_SPEED_UP = "1. TANG TOC";
std::string SpeedControlScreen::TEXT_SPEED_DOWN = "2. GIAM TOC";
std::string SpeedControlScreen::TEXT_BREAK = "3. PHANH";
std::string SpeedControlScreen::TEXT_BACK_TO_MENU = "4. TRO VE MENU";

SpeedControlScreen::SpeedControlScreen()
{
}

SpeedControlScreen::~SpeedControlScreen()
{
}

void SpeedControlScreen::process()
{
    do{
        printf("MOI LUA CHON:\n");
        printf("%s\n", TEXT_SPEED_UP.c_str());
        printf("%s\n", TEXT_SPEED_DOWN.c_str());
        printf("%s\n", TEXT_BREAK.c_str());
        printf("%s\n", TEXT_BACK_TO_MENU.c_str());
        std::string input;
        std::cin >> input;

        mChoice = validateIntegerInput(input);
        if(isValidInput()){
            setUserChoice(std::make_shared<ControlSpeedScreenUserChoice>(static_cast<ControlSpeedScreenUserChoice::Choice>(mChoice)));
        }

    }while(!isValidInput());

}

bool SpeedControlScreen::isValidInput()
{
    return (mChoice > static_cast<int>(ControlSpeedScreenUserChoice::UNKNOWN_CHOICE)
             && mChoice <= static_cast<int>(ControlSpeedScreenUserChoice::BACK_TO_GEAR_MENU));
}
