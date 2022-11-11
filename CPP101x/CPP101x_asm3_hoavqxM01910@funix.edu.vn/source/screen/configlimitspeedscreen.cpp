#include "common.h"
#include "configlimitspeedscreen.h"
#include "configuration.h"
#include "model/userconfiglimitspeedandsafedistance.h"
ConfigLimitSpeedScreen::ConfigLimitSpeedScreen()
{

}

ConfigLimitSpeedScreen::~ConfigLimitSpeedScreen()
{

}

void ConfigLimitSpeedScreen::process()
{
    string select;
    do{
        printf("BAN CO MUON CAI DAT LAI VAN TOC CANH BAO KHOANG CACH AN TOAN HAY KHONG?\n");
        printf("CAU HINH MAC DINH DANG LA:\n");
        std::map<int, int> m = Configuration::getInstance().speedAndSafeDistance();
        for(auto iter = m.begin(); iter != m.end(); ++iter){
            if(iter == --m.end()){
                printf("CAN GIU KHOANG CACH TOI THIEU %d(m) KHI VUOT QUA MUC TOI DA\n", iter->second);
            }else{
                printf("NEU VAN TOC KHONG QUA %d (km/h) CAN GIU KHOANG CACH TOI THIEU %d (m)\n", iter->first, iter->second);
            }
        }
        printf("1. CO\n");
        printf("2. KHONG\n");

        cin >> select;
    }while(select != "1" && select != "2");

    if(select == "1"){
        Configuration::getInstance().clearSpeedAndSafeDistanceConfig();
        int maxSpeedLevel = 0;
        do{
            printf("CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI %d MUC VAN TOC\n", Configuration::getInstance().numberOfLevelLimitSpeed());
            for(int i = 0; i < Configuration::getInstance().numberOfLevelLimitSpeed();i++){

                printf("CAI DAT MUC [%d]\n", i+1);
                int speed = ERROR_INVALID_INT;
                do{
                    printf("[%i]VAN TOC = ", i+1);
                    std::string inSpeed;
                    cin >> inSpeed;
                    speed = validateIntegerInput(inSpeed);
                }while(speed == ERROR_INVALID_INT || speed < maxSpeedLevel || speed >= 300);

                int distance = ERROR_INVALID_INT;
                do{
                    printf("[%i]KHOANG CACH AN TOAN = ", i+1);
                    std::string inDistance;
                    cin >> inDistance;
                    distance = validateIntegerInput(inDistance);
                }while(distance == ERROR_INVALID_INT);
                maxSpeedLevel = speed;
                Configuration::getInstance().setSpeedAndSafeDistance(speed, distance);

            }


            int distance = ERROR_INVALID_INT;
            do{
                printf("KHOANG CACH AN TOAN KHI VAN TOC > %d km/h:  ", maxSpeedLevel);
                std::string inDistance;
                cin >> inDistance;
                distance = validateIntegerInput(inDistance);
                Configuration::getInstance().setSpeedAndSafeDistance(400, distance);
            }while(distance == ERROR_INVALID_INT);

        }while(!isValidInput());
    }else{
        setUserChoice(std::make_shared<UserConfigLimitSpeedAndSafeDistance>(UserConfigLimitSpeedAndSafeDistance::NO));
    }
}

bool ConfigLimitSpeedScreen::isValidInput()
{
    setUserChoice(std::make_shared<UserConfigLimitSpeedAndSafeDistance>(UserConfigLimitSpeedAndSafeDistance::YES));
    return true;
}
