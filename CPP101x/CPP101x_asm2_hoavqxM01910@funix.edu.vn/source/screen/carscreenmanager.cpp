#include "carscreenmanager.h"
#include "configlimitspeedscreen.h"
#include "common.h"
#include "gearscreen.h"
#include "model/usercommand.h"
#include "speedcontrolscreen.h"
#include "signinscreen.h"


CarScreenManager::CarScreenManager()  : Channel(SCREEN_CHANNEL)
{
    mCarInformation = std::make_shared<CarInformation>(POWER_OFF);
}

CarScreenManager::~CarScreenManager()
{

}

void CarScreenManager::start()
{
    mCarInformation->setState(GEAR_P);
    setScreen(std::make_shared<SignInScreen>());
    screen()->process();
    this->clearScreen();
    setScreen(std::make_shared<ConfigLimitSpeedScreen>());
    screen()->process();
    this->clearScreen();
    setScreen(std::make_shared<GearScreen>());
    this->processLoop();

}

void CarScreenManager::processLoop()
{
    //run screen until vehicle is OFF
    while(mCarInformation->state() != POWER_OFF){
        screen()->process();
        this->clearScreen();
        handleUserChoice(screen()->userChoice());
    }
}

void CarScreenManager::handleUserChoice(std::shared_ptr<UserChoice> choice)
{
    switch(choice->screenType()){
    case UserChoice::ControlSpeedScreen:
        handleControlSpeedChoice(std::dynamic_pointer_cast<ControlSpeedScreenUserChoice>(choice));
        break;
    case UserChoice::GearScreen:
        handleGearChoice(std::dynamic_pointer_cast<GearScreenUserChoice>(choice));
        break;
    default:
        break;
    }
}

void CarScreenManager::handleGearChoice(std::shared_ptr<GearScreenUserChoice> choice)
{
    switch (choice->choice()) {
    case GearScreenUserChoice::GEAR_D:
    {
        auto cmd = std::make_shared<UserCommand>(UserCommand::CHANGE_TO_GEAR_D);
        cmd->bindCallback([&](int err, std::shared_ptr<Message> msg){
            (void)msg;
            if(err == Message::RESPONSE_OK){
                setScreen(std::make_shared<SpeedControlScreen>());
            }
        });
        publish(cmd, ENGINE_CHANNEL);
    }
        break;

    case GearScreenUserChoice::GEAR_R:
    {
        auto cmd = std::make_shared<UserCommand>(UserCommand::CHANGE_TO_GEAR_R);
        cmd->bindCallback([&](int err, std::shared_ptr<Message> msg){
            (void)msg;
            if(err == Message::RESPONSE_OK){
                setScreen(std::make_shared<SpeedControlScreen>());
            }
        });
        publish(cmd, ENGINE_CHANNEL);
    }
        break;
    case GearScreenUserChoice::GEAR_N:
        publish(std::make_shared<UserCommand>(UserCommand::CHANGE_TO_GEAR_N), ENGINE_CHANNEL);
        setScreen(std::make_shared<GearScreen>());
        break;
    case GearScreenUserChoice::GEAR_P:
        publish(std::make_shared<UserCommand>(UserCommand::CHANGE_TO_GEAR_P), ENGINE_CHANNEL);
        setScreen(std::make_shared<GearScreen>());
        break;
    case GearScreenUserChoice::POWER_OFF:
    {
        auto cmd = std::make_shared<UserCommand>(UserCommand::POWER_OFF);
        cmd->bindCallback([&](int err, std::shared_ptr<Message> msg){
            (void)msg;
            if(err == Message::RESPONSE_OK){
                //Say goodbye
                printf("================BAN DA TAT MAY. TAM BIET===================\n");
            }
        });
        publish(cmd, ENGINE_CHANNEL);
    }
        break;
    default:
        break;
    }
}

void CarScreenManager::handleControlSpeedChoice(std::shared_ptr<ControlSpeedScreenUserChoice> choice)
{
    switch (choice->choice()) {
    case ControlSpeedScreenUserChoice::SPEED_UP:
        publish(std::make_shared<UserCommand>(UserCommand::SPEED_UP), ENGINE_CHANNEL);
        break;
    case ControlSpeedScreenUserChoice::SPEED_DOWN:
        publish(std::make_shared<UserCommand>(UserCommand::SPEED_DOWN), ENGINE_CHANNEL);
        break;
    case ControlSpeedScreenUserChoice::BREAK:
        publish(std::make_shared<UserCommand>(UserCommand::BREAK), ENGINE_CHANNEL);
        break;
    case ControlSpeedScreenUserChoice::BACK_TO_GEAR_MENU:
        setScreen(std::make_shared<GearScreen>());
        break;
    default:
        break;
    }
}

void CarScreenManager::handleWarningMessage(std::shared_ptr<WarningMessage> warning)
{
    printf("%s\n", warning->warning().c_str());
}


void CarScreenManager::onMessage(std::shared_ptr<Message> msg)
{
    switch (msg->type()) {
    case Message::CAR_INFORMATION_MESSAGE:
        mCarInformation = std::dynamic_pointer_cast<CarInformation>(msg);
        mCarInformation->printCarInformation();
        break;
    case Message::WARNING_MESSAGE:
        handleWarningMessage(std::dynamic_pointer_cast<WarningMessage>(msg));
        break;
    default:
        break;
    }
}
