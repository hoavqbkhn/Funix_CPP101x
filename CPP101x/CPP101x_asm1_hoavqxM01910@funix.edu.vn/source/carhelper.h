#ifndef CARHELPER_H
#define CARHELPER_H
#include <iostream>
using namespace std;

const static string TEXT_GEAR_P = "1. P";
const static string TEXT_GEAR_R = "2. R";
const static string TEXT_GEAR_N = "3. N";
const static string TEXT_GEAR_D = "4. D";
const static string TEXT_GEAR_POWER_OFF = "5. POWER OFF";
const static string MSCN = "12345678";

const static string TEXT_SPEED_UP = "1. TANG TOC";
const static string TEXT_SPEED_DOWN = "2. GIAM TOC";
const static string TEXT_BREAK = "3. PHANH";
const static string TEXT_BACK_TO_MENU = "4. TRO VE MENU";

enum Gear{
    UNKNOWN_GEAR = 0,
    GEAR_P,
    GEAR_R,
    GEAR_N,
    GEAR_D,
    POWER_OFF,
};

enum ControlSpeed{
    UNKNOWN_CONTROL = 0,
    SPEED_UP,
    SPEED_DOWN,
    BREAK,
    RETURN_TO_MENU
};

enum

/**
 * @brief getUserSelectedGear
 * @return selected gear through input screen
 */
Gear getUserSelectedGear();

/**
 * @brief controlSpeed: control the action of car when car in gear D|R
 * @param speed
 * @param curGear
 */
void controlSpeed(int &speed, Gear curGear);

/**
 * @brief checkSafeSpeed: check if the speed is safe & give warning if not safe
 * @param curSpeed
 * @param curGear
 */
void checkSafeSpeed(int curSpeed, Gear curGear);

/**
 * @brief handleSelectedGear: select handler for specific gear
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool handleSelectedGear(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief modePHandler: process logic when user select gear P
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool modePHandler(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief modeRHandler : process logic when user select gear R
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool modeRHandler(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief modeNHandler : process logic when user select gear N
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool modeNHandler(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief modeDHandler : process logic when user select gear D
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool modeDHandler(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief powerOffHandler : process logic when user select power off
 * @param speed
 * @param selectedGear
 * @param curGear
 * @return
 */
bool powerOffHandler(int &speed, Gear selectedGear, Gear curGear);

/**
 * @brief printStatus : print current speed & gear
 * @param speed
 * @param gear
 */
void printStatus(int speed, Gear gear);

/**
 * @brief validateInput : validate input from screen
 * @param input
 * @return
 */
int validateInput(string input);

/**
 * @brief requestSignIn : request user type exact MSCN from screen
 */
void requestSignIn();


/**
 * @brief doCarFunction : work on car functions
 */
void doCarFunction();

#endif // CARHELPER_H
