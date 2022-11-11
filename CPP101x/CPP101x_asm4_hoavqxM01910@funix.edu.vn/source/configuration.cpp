#include <fstream>
#include <sstream>

#include "common.h"
#include "configuration.h"

using namespace std;

Configuration &Configuration::getInstance()
{
    static Configuration self;
    return self;
}

Configuration::~Configuration()
{

}

Configuration::Configuration()
{
    //init default speed and safe distance
    if(!readSpeedAndSafeDistanceFromFile()){
        mSpeedAndSafeDistance[60] = 20;
        mSpeedAndSafeDistance[80] = 55;
        mSpeedAndSafeDistance[100] = 70;
        mSpeedAndSafeDistance[OVER_SPEED] = 100;

        for(auto iter = mSpeedAndSafeDistance.begin(); iter != mSpeedAndSafeDistance.end(); iter++){
            mSpeedLevel.push_back(iter->first);
        }
    }
}

Configuration::Configuration(const Configuration &)
{

}

std::vector<std::string> Configuration::splitBySperator(std::string s)
{
    std::vector<std::string> o;
    std::string tmp;
    std::stringstream ss(s);
    while(getline(ss,tmp,'=')) {
        o.push_back(tmp);
    }
    return o;
}

int Configuration::personalKeyLength() const
{
    return mPersonalKeyLength;
}

int *Configuration::personalKeyFromFile() const
{
    return mPersonalKeyFromFile;
}

bool Configuration::readPersonalKeyFromFile()
{
    std::ifstream inputFile(FILE_PERSONAL_KEY_PATH.c_str());
    std::vector<std::string> lines;

    if (!inputFile.is_open()) {
        printf("[WARNING] KHONG CO FILE PERSONAL KEY\n");
        inputFile.close();
        return false;
    }else{
        std::string line;
        while (getline(inputFile, line)){
            lines.push_back(line);
        }

        if(lines.size() != 2){
            printf("[WARNING] FILE PERSONAL KEY CHI DUOC PHEP CHUA 2 DONG\n");
            inputFile.close();
            return false;
        }

        std::string line1 = lines[0];
        int numberOfLetter = validateNumberLetterInput(line1);
        if(numberOfLetter == ERROR_INVALID_NUMBER_LETTER){
            printf("[WARNING] DONG DAU TIEN CHI DUOC PHEP CHUA 01 CHU SO BIEU THI SO CHU SO TRONG MSCN\n");
            inputFile.close();
            return false;
        }else{
            mPersonalKeyLength = numberOfLetter;
        }

        std::string line2 = lines[1];
        if(line2.size() != mPersonalKeyLength){
            printf("[WARNING] SO KY TU TRONG MSCN KHONG KHOP VOI CAU HINH\n");
            inputFile.close();
            return false;
        }else{

            if(validateIntegerInput(line2) == ERROR_INVALID_INT){
                printf("[WARNING] MSCN CHI DUOC GOM CAC CHU SO\n");
                inputFile.close();
                return false;
            }

            mPersonalKeyFromFile = new int[mPersonalKeyLength];

            for(int i = 0; i < mPersonalKeyLength; i++){
                std::string s = "";
                s += line2[i];
                int num = validateIntegerInput(s);
                mPersonalKeyFromFile[i] = num;
            }
        }

    }

    inputFile.close();
    return true;

}

bool Configuration::readSpeedAndSafeDistanceFromFile()
{
    std::ifstream inputFile(FILE_SPEED_AND_SAFE_DISTANCE_PATH.c_str());
    std::vector<std::string> lines;

    if (!inputFile.is_open()) {
        printf("[WARNING] KHONG CO FILE PERSONAL KEY\n");
        inputFile.close();
        return false;
    }else{
        std::string line;
        while (getline(inputFile, line)){
            lines.push_back(line);
        }

        mNumberOfLevelLimitSpeed = validateNumberLetterInput(lines[0]);
        if(mNumberOfLevelLimitSpeed == ERROR_INVALID_NUMBER_LETTER){
            printf("[WARNING] DONG DAU TIEN CHI DUOC PHEP CHUA 01 CHU SO BIEU THI SO MUC VAN TOC\n");
            inputFile.close();
            return false;
        }

        if(lines.size() != mNumberOfLevelLimitSpeed + 2){
            printf("[WARNING] DINH DANG CAU HINH SAI\n");
            inputFile.close();
            return false;
        }
        mSpeedAndSafeDistance.clear();
        for(int i = 0; i < mNumberOfLevelLimitSpeed+1; i++){
            std::vector<std::string> v = splitBySperator(lines[i+1]);
            if(validateIntegerInput(v[0]) != ERROR_INVALID_INT
                    && validateIntegerInput(v[1]) != ERROR_INVALID_INT){
                setSpeedAndSafeDistance(validateIntegerInput(v[0]),validateIntegerInput(v[1]));
            }
        }
    }
    inputFile.close();
    return true;

}

void Configuration::updateNewPersonalKeyToFile(std::string newKey)
{
    std::ofstream outputFile(FILE_PERSONAL_KEY_PATH.c_str(), ios::out|ios::binary);
    outputFile << newKey.length() << endl;
    outputFile << newKey;
    outputFile.close();
}

void Configuration::updateNewSpeedAndSafeDistanceToFile()
{
    std::ofstream outputFile(FILE_SPEED_AND_SAFE_DISTANCE_PATH.c_str(), ios::out|ios::binary);
    outputFile << mNumberOfLevelLimitSpeed << endl;
    for(auto iter = mSpeedAndSafeDistance.begin(); iter != mSpeedAndSafeDistance.end(); iter++){
        outputFile << iter->first << "=" << iter->second << endl;
    }
    outputFile.close();

}


const std::vector<int> &Configuration::speedLevel() const
{
    return mSpeedLevel;
}

int Configuration::numberOfLevelLimitSpeed()
{
    return mNumberOfLevelLimitSpeed;
}

const std::map<int, int> &Configuration::speedAndSafeDistance() const
{
    return mSpeedAndSafeDistance;
}

void Configuration::setSpeedAndSafeDistance(int speed, int safeDistance)
{
    mSpeedAndSafeDistance[speed] = safeDistance;
    if(mSpeedAndSafeDistance.size() > mNumberOfLevelLimitSpeed){
        mSpeedLevel.clear();
        for(auto iter = mSpeedAndSafeDistance.begin(); iter != mSpeedAndSafeDistance.end(); iter++){
            mSpeedLevel.push_back(iter->first);
        }
    }
}

void Configuration::clearSpeedAndSafeDistanceConfig()
{
    mSpeedAndSafeDistance.clear();
}

