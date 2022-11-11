#include "common.h"
#include "menuscreen.h"
#include "model/gearscreenuserchoice.h"


std::string MenuScreen::TEXT_GEAR_P = "1. P";
std::string MenuScreen::TEXT_GEAR_R = "2. R";
std::string MenuScreen::TEXT_GEAR_N = "3. N";
std::string MenuScreen::TEXT_GEAR_D = "4. D";
std::string MenuScreen::TEXT_GEAR_POWER_OFF = "5. POWER OFF";
std::string MenuScreen::TEXT_CONFIG_PERSONAL_KEY = "6. CAI LAI MSCN";
std::string MenuScreen::TEXT_CONFIG_SPEED_AND_SAFE_DISTANCE = "7. CAI LAI VAN TOC VA KHOANG CACH AN TOAN";

MenuScreen::MenuScreen()
{

}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::process()
{
    do{
        printf("XIN MOI LUA CHON:\n");
        printf("%s\n",TEXT_GEAR_P.c_str());
        printf("%s\n",TEXT_GEAR_R.c_str());
        printf("%s\n",TEXT_GEAR_N.c_str());
        printf("%s\n",TEXT_GEAR_D.c_str());
        printf("%s\n",TEXT_GEAR_POWER_OFF.c_str());
        printf("%s\n",TEXT_CONFIG_PERSONAL_KEY.c_str());
        printf("%s\n",TEXT_CONFIG_SPEED_AND_SAFE_DISTANCE.c_str());

        std::string input;
        std::cin >> input;

        mChoice = validateIntegerInput(input);
        if(isValidInput()){
            setUserChoice(std::make_shared<GearScreenUserChoice>(static_cast<GearScreenUserChoice::Choice>(mChoice)));
        }
    }while(!isValidInput());
}

bool MenuScreen::isValidInput()
{
    return (mChoice > static_cast<int>(GearScreenUserChoice::UNKNOWN_CHOICE)
             && mChoice <= static_cast<int>(GearScreenUserChoice::CONFIG_SPEED_AND_SAFE_DISTANCE));
}
