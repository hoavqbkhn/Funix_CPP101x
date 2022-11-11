#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <map>
#include <vector>
#include <string>

class Configuration
{
public:
    static Configuration &getInstance();
    ~Configuration();


    const std::map<int, int> &speedAndSafeDistance() const;
    void setSpeedAndSafeDistance(int speed, int safeDistance);
    void clearSpeedAndSafeDistanceConfig();

    int numberOfLevelLimitSpeed();
    const std::vector<int> &speedLevel() const;

    int *personalKeyFromFile() const;
    int personalKeyLength() const;

    bool readPersonalKeyFromFile();
    bool readSpeedAndSafeDistanceFromFile();
    void updateNewPersonalKeyToFile(std::string newKey);
    void updateNewSpeedAndSafeDistanceToFile();

private:
    Configuration();
    Configuration(const Configuration&);
    Configuration& operator=(const Configuration&);

    int mNumberOfLevelLimitSpeed{3};
    std::map<int, int> mSpeedAndSafeDistance;
    std::vector<int> mSpeedLevel;
    int* mPersonalKeyFromFile;
    int mPersonalKeyLength{8};

    std::vector<std::string> splitBySperator(std::string s);


};

#endif // CONFIGURATION_H
