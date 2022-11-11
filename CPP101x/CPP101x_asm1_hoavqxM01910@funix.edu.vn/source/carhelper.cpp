#include "carhelper.h"
#include <sstream>
void requestSignIn(){
    std::string id;
    bool isWrongId = false;
    do{
        cout << "NHAP MA SO CA NHAN:";
        cin >> id;
        isWrongId = (MSCN != id);
        if(isWrongId)printf("MA SO CA NHAN %s KHONG DUNG, VUI LONG NHAP LAI\n", id.c_str());
    }while(MSCN != id);
    cout << "XIN CHAO " << id << endl;
}

Gear getUserSelectedGear(){
    cout << "XIN MOI LUA CHON:" << endl;
    cout << TEXT_GEAR_P << endl;
    cout << TEXT_GEAR_R << endl;
    cout << TEXT_GEAR_N << endl;
    cout << TEXT_GEAR_D << endl;
    cout << TEXT_GEAR_POWER_OFF << endl;

    string input;
    cin >> input;
    int choice = validateInput(input);

    switch (choice) {
    case GEAR_P:
    case GEAR_R:
    case GEAR_N:
    case GEAR_D:
    case POWER_OFF:
        return static_cast<Gear>(choice);
    default:
        break;
    }
    return UNKNOWN_GEAR;
}

bool modePHandler(int &speed, Gear selectedGear, Gear curGear)
{
    if(0 == speed){
        printf("[WARNING] CHU Y SU DUNG PHANH TAY ");
        return true;
    }else{
        printf("[WARNING] TOC DO HIEN TAI = %d. GIAM TOC DO VE 0 TRUOC KHI VE P\n", speed);
        return false;
    }
    return false;
}

bool modeRHandler(int &speed, Gear selectedGear, Gear curGear)
{
    if(curGear == Gear::GEAR_D && speed != 0){
        printf("[WARNING] DANG O GEAR D, TOC DO = %d, KHONG THE CHUYEN VE GEAR R\n", speed);
        return false;
    }else if(curGear == Gear::GEAR_N || curGear == Gear::GEAR_P){
        speed = 7;
    }
    return true;
}

bool modeNHandler(int &speed, Gear selectedGear, Gear curGear)
{
    if(0 == speed){
        printf("[WARNING] CHU Y SU DUNG PHANH TAY ");
        return true;
    }else{
        printf("[WARNING] TOC DO HIEN TAI = %d. GIAM TOC DO VE 0 TRUOC KHI VE N\n", speed);
        return false;
    }
    return false;
}

bool modeDHandler(int &speed, Gear selectedGear, Gear curGear)
{
    if(curGear == Gear::GEAR_R && speed != 0){
        printf("[WARNING] DANG O GEAR R, TOC DO = %d, KHONG THE CHUYEN VE GEAR D\n", speed);
        return false;
    }else if(curGear == Gear::GEAR_N || curGear == Gear::GEAR_P){
        speed = 7;
    }
    return true;
}

bool powerOffHandler(int &speed, Gear selectedGear, Gear curGear)
{
    if(curGear == Gear::GEAR_P || curGear == Gear::GEAR_N){
        return true;
    }else{
        printf("[WARNING] VE P HOAC N TRUOC KHI TAT MAY\n");
    }
    return false;
}


void doCarFunction()
{
    int speed = 0;
    Gear curGear = GEAR_P;
    do{
        printStatus(speed, curGear);
        Gear selectedGear = getUserSelectedGear();
        system("cls");
        if(curGear != selectedGear && handleSelectedGear(speed, selectedGear, curGear)){
            curGear = selectedGear;
        }
        if(curGear == GEAR_D || curGear == GEAR_R){
            controlSpeed(speed, curGear);
        }
    }while(curGear != POWER_OFF);
    printf("TAM BIET\n");
}

bool handleSelectedGear(int &speed, Gear selectedGear, Gear curGear)
{
    switch (selectedGear) {
    case Gear::GEAR_P:
        return modePHandler(speed, selectedGear, curGear);
    case Gear::GEAR_R:
        return modeRHandler(speed, selectedGear, curGear);
    case Gear::GEAR_N:
        return modeNHandler(speed, selectedGear, curGear);
    case Gear::GEAR_D:
        return modeDHandler(speed, selectedGear, curGear);
    case Gear::POWER_OFF:
        return powerOffHandler(speed, selectedGear, curGear);
    default:
        break;
    }
    return false;
}

void printStatus(int speed, Gear gear)
{
    string strGear = "";
    switch (gear) {
    case Gear::GEAR_P:
        strGear = "P";
        break;
    case Gear::GEAR_R:
        strGear = "R";
        break;
    case Gear::GEAR_N:
        strGear = "N";
        break;
    case Gear::GEAR_D:
        strGear = "D";
        break;
    case Gear::POWER_OFF:
        strGear = "OFF";
        break;
    default:
        break;
    }
    printf("[TOC DO = %d km/h, GEAR = %s]\n", speed, strGear.c_str());
}



void controlSpeed(int &speed, Gear curGear)
{
    if(curGear == GEAR_P || curGear == GEAR_N){
        return;
    }
    int choice = UNKNOWN_CONTROL;
    do{
        printStatus(speed, curGear);
        checkSafeSpeed(speed, curGear);
        printf("MOI LUA CHON:\n");
        printf("%s\n", TEXT_SPEED_UP.c_str());
        printf("%s\n", TEXT_SPEED_DOWN.c_str());
        printf("%s\n", TEXT_BREAK.c_str());
        printf("%s\n", TEXT_BACK_TO_MENU.c_str());
        string input;
        cin >> input;
        int choice = validateInput(input);
        switch (choice) {
        case SPEED_UP:
            speed += 5;
            break;
        case SPEED_DOWN:
            speed -= 5;
            if(speed < 0)speed = 0;
            break;
        case BREAK:
            speed = 0;
            break;
        case RETURN_TO_MENU:
            system("cls");
            return;
        default:
            break;
        }
        system("cls");
    }while(static_cast<ControlSpeed>(choice) != RETURN_TO_MENU);
}

void checkSafeSpeed(int curSpeed, Gear curGear)
{
    if((curSpeed > 60 && curGear == GEAR_D) || (curSpeed > 25 && curGear == GEAR_R)){
        printf("[WARNING] TOC DO NGUY HIEM, BAN NEN GIAM TOC DO\n");
    }
}

int validateInput(string input){
    std::istringstream iss(input);
    int choice = 0;
    while(iss >> choice || !iss.eof()) {
        if(iss.fail()) {
            iss.clear();
            string dummy;
            iss >> dummy;
            return 0;
        }
    }
    return choice;
}
