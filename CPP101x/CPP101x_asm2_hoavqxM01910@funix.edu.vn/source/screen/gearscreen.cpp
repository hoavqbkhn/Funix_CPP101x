#include "common.h"
#include "gearscreen.h"
#include "model/gearscreenuserchoice.h"
#include "algorithm/bublesortalgorithm.h"

std::string GearScreen::TEXT_GEAR_P = "1. P";
std::string GearScreen::TEXT_GEAR_R = "2. R";
std::string GearScreen::TEXT_GEAR_N = "3. N";
std::string GearScreen::TEXT_GEAR_D = "4. D";
std::string GearScreen::TEXT_GEAR_POWER_OFF = "5. POWER OFF";

GearScreen::GearScreen()
{

}

GearScreen::~GearScreen()
{

}

void GearScreen::process()
{
    do{
        printf("XIN MOI LUA CHON:\n");
        printf("%s\n",TEXT_GEAR_P.c_str());
        printf("%s\n",TEXT_GEAR_R.c_str());
        printf("%s\n",TEXT_GEAR_N.c_str());
        printf("%s\n",TEXT_GEAR_D.c_str());
        printf("%s\n",TEXT_GEAR_POWER_OFF.c_str());

        std::string input;
        std::cin >> input;

        mChoice = validateIntegerInput(input);
        if(isValidInput()){
            setUserChoice(std::make_shared<GearScreenUserChoice>(static_cast<GearScreenUserChoice::Choice>(mChoice)));
        }
    }while(!isValidInput());
}

bool GearScreen::isValidInput()
{
    return (mChoice > static_cast<int>(GearScreenUserChoice::UNKNOWN_CHOICE)
             && mChoice <= static_cast<int>(GearScreenUserChoice::POWER_OFF));
}
