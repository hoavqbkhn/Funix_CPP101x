#include "configuration.h"


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
    mSpeedAndSafeDistance[60] = 20;
    mSpeedAndSafeDistance[80] = 55;
    mSpeedAndSafeDistance[100] = 70;
    mSpeedAndSafeDistance[1000] = 100;
    for(auto iter = mSpeedAndSafeDistance.begin(); iter != mSpeedAndSafeDistance.end(); iter++){
        mSpeedLevel.push_back(iter->first);
    }
}

Configuration::Configuration(const Configuration &)
{

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
    if(mSpeedAndSafeDistance.size() == mNumberOfLevelLimitSpeed){
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

