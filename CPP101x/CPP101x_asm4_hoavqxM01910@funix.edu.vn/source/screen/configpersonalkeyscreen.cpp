#include "common.h"
#include "configpersonalkeyscreen.h"
#include "configuration.h"

ConfigPersonalKeyScreen::ConfigPersonalKeyScreen()
{

}

ConfigPersonalKeyScreen::~ConfigPersonalKeyScreen()
{

}

void ConfigPersonalKeyScreen::process()
{
    do{
        mInput.clear();
        printf("BAN HAY NHAP MSCN MOI CHI GOM CHU SO:");
        std::cin >> mInput;
    }while(!isValidInput());
}

bool ConfigPersonalKeyScreen::isValidInput()
{
    for(auto c : mInput){
        if(validateNumberLetterInput(c) == ERROR_INVALID_NUMBER_LETTER){
            printf("[WARNING] CHUOI NHAP VAO CO KY TU KHONG PHAI CHU SO\n");
            return false;
        }
    }

    if(Configuration::getInstance().personalKeyLength() == mInput.size()){
        int *currentPersonalKey = Configuration::getInstance().personalKeyFromFile();

        for(int i = 0; i < mInput.size(); i++){
            if(currentPersonalKey[i] != validateNumberLetterInput(mInput[i])){
                setUserChoice(std::make_shared<UserUpdatePersonalKey>(mInput));
                return true;
            }
        }

        printf("[WARNING] MSCN MOI TRUNG VOI MSCN CU. VUI LONG NHAP LAI\n");
        return false;
    }

    setUserChoice(std::make_shared<UserUpdatePersonalKey>(mInput));
    return true;
}
