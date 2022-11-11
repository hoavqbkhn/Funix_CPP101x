#ifndef CARSCREENMANAGER_H
#define CARSCREENMANAGER_H
#include "model/carinformation.h"
#include "model/channel.h"
#include "model/controlspeedscreenuserchoice.h"
#include "model/gearscreenuserchoice.h"
#include "model/userupdatepersonalkey.h"
#include "model/userconfiglimitspeedandsafedistance.h"
#include "model/warningmessage.h"
#include "screen/screenmanager.h"



class CarScreenManager : public ScreenManager, Channel
{
public:
    CarScreenManager();
    ~CarScreenManager();
    void start() override;


    void onMessage(std::shared_ptr<Message> msg) override;

private:
    std::shared_ptr<CarInformation> mCarInformation;
    void processLoop() override;
    void handleUserChoice(std::shared_ptr<UserChoice> choice);
    void handleMenuChoice(std::shared_ptr<GearScreenUserChoice> choice);
    void handleControlSpeedChoice(std::shared_ptr<ControlSpeedScreenUserChoice> choice);
    void handleUpdateNewPersonalKey(std::shared_ptr<UserUpdatePersonalKey> choice);
    void handleUpdateNewConfigLimitSpeedAndSafeDistance(std::shared_ptr<UserConfigLimitSpeedAndSafeDistance> choice);
    void handleWarningMessage(std::shared_ptr<WarningMessage> warning);
};

#endif // CARSCREENMANAGER_H
