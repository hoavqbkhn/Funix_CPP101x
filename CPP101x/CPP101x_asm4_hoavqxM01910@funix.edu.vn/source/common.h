#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <sstream>

const static std::string ENGINE_CHANNEL = "ENGINE_CHANNEL";
const static std::string SCREEN_CHANNEL = "SCREEN_CHANNEL";
const static int ERROR_INVALID_INT = -1;
const static int ERROR_INVALID_NUMBER_LETTER = -1;
const static int OVER_SPEED = 301;
const static std::string FILE_PERSONAL_KEY_PATH = "config/personal_key.txt";
const static std::string FILE_SPEED_AND_SAFE_DISTANCE_PATH = "config/speed_and_safe_distance.txt";

enum GearState{
    UNKNOWN_GEAR = 0,
    GEAR_P,
    GEAR_R,
    GEAR_N,
    GEAR_D,
    POWER_OFF,
};


inline static int validateIntegerInput(std::string input){
    std::istringstream iss(input);
    int choice = 0;
    while(iss >> choice || !iss.eof()) {
        if(iss.fail()) {
            iss.clear();
            std::string dummy;
            iss >> dummy;
            return ERROR_INVALID_INT;
        }
    }
    return choice;
}

inline static int validateNumberLetterInput(std::string input){

    static int NUMBER_0_ASCII = 48;
    static int NUMBER_9_ASCII = 57;

    if(input.length() > 1){
        return ERROR_INVALID_NUMBER_LETTER;
    }

    if(input[0] >= NUMBER_0_ASCII && input[0] <= NUMBER_9_ASCII){
        return input[0] - NUMBER_0_ASCII;
    }

    return ERROR_INVALID_NUMBER_LETTER;
}

inline static int validateNumberLetterInput(char c){

    static int NUMBER_0_ASCII = 48;
    static int NUMBER_9_ASCII = 57;

    std::string input;
    input += c;

    if(input.length() > 1){
        return ERROR_INVALID_NUMBER_LETTER;
    }

    if(input[0] >= NUMBER_0_ASCII && input[0] <= NUMBER_9_ASCII){
        return input[0] - NUMBER_0_ASCII;
    }

    return ERROR_INVALID_NUMBER_LETTER;
}

inline static void printArray(int *arr, int len){
    for(auto i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}


#endif // COMMON_H
