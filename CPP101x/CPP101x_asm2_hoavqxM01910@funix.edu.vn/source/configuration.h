#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <map>
#include <vector>

class Configuration
{
public:
    static Configuration &getInstance();
    ~Configuration();


    const std::map<int, int> &speedAndSafeDistance() const;
    void setSpeedAndSafeDistance(int speed, int safeDistance);
    void clearSpeedAndSafeDistanceConfig();

    static int numberOfLevelLimitSpeed();

    const std::vector<int> &speedLevel() const;

private:
    Configuration();
    Configuration(const Configuration&);
    Configuration& operator=(const Configuration&);

    const static int mNumberOfLevelLimitSpeed = 4;
    std::map<int, int> mSpeedAndSafeDistance;
    std::vector<int> mSpeedLevel;

};

#endif // CONFIGURATION_H
