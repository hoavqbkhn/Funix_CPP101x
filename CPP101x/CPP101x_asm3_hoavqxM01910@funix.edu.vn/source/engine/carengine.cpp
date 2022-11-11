#include "common.h"
#include "configuration.h"
#include "carengine.h"
#include "model/carinformation.h"
#include "model/warningmessage.h"

CarEngine::CarEngine(): Channel(ENGINE_CHANNEL)
{

}

CarEngine::~CarEngine()
{

}

const static int MAX_SPEED = 300;

void CarEngine::start()
{
    powerOn();
}

void CarEngine::powerOn()
{
    setState(static_cast<int> (GEAR_P));
    setSpeed(0);
}

void CarEngine::speedUp(int add)
{
    setSpeed(speed() + add);
    if(speed() >= MAX_SPEED){
        setSpeed(MAX_SPEED);
    }
}

void CarEngine::speedDown(int minus)
{
    if(speed() - minus > 0){
        setSpeed(speed() - minus);
    }else{
        setSpeed(0);
    }
}


void CarEngine::onMessage(std::shared_ptr<Message> msg)
{
    switch (msg->type()) {
    case Message::USER_COMMAND_MESSAGE:
        handleUserCommand(std::dynamic_pointer_cast<UserCommand>(msg));
        break;
    default:
        break;
    }
    checkSafety();
}

void CarEngine::handleUserCommand(std::shared_ptr<UserCommand> cmd)
{
    switch (cmd->command()) {
    case UserCommand::CHANGE_TO_GEAR_D:
        modeDHandler(cmd);
        break;
    case UserCommand::CHANGE_TO_GEAR_R:
        modeRHandler(cmd);
        break;
    case UserCommand::CHANGE_TO_GEAR_N:
        modeNHandler(cmd);
        break;
    case UserCommand::CHANGE_TO_GEAR_P:
        modePHandler(cmd);
        break;
    case UserCommand::SPEED_DOWN:
        speedDownHandler(cmd);
        break;
    case UserCommand::SPEED_UP:
        speedUpHandler(cmd);
        break;
    case UserCommand::BREAK:
        breakHandler(cmd);
        break;
    case UserCommand::POWER_OFF:
        powerOffHandler(cmd);
        break;

    default:
        break;
    }
}

void CarEngine::checkSafety()
{
    //check high speed
    if((speed() > 60 && state() == GEAR_D) || (speed() > 25 && state() == GEAR_R)){
        publish(std::make_shared<WarningMessage>("[WARNING] TOC DO NGUY HIEM, BAN NEN GIAM TOC DO"), SCREEN_CHANNEL);
    }

    //check speed and safe distance to front vehicle
    std::map<int, int> m = Configuration::getInstance().speedAndSafeDistance();
    std::vector<int> speedLevel = Configuration::getInstance().speedLevel();
    int max = 0;
    for(int i = 0; i < speedLevel.size(); i++){
        max = speedLevel[i];
        if(speed() < speedLevel[i]){
            break;
        }
    }
    std::ostringstream ss;
    ss << "[WARNING] BAN CHU Y GIU KHOANG CACH TOI THIEU LA " << m[max] << "m";
    publish(std::make_shared<WarningMessage>(ss.str()), SCREEN_CHANNEL);



}


void CarEngine::modePHandler(std::shared_ptr<UserCommand> cmd)
{
    if(0 == speed()){
        setState(GEAR_P);
        publish(std::make_shared<WarningMessage>("[WARNING] CHU Y SU DUNG PHANH TAY"),SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }else{
        publish(std::make_shared<WarningMessage>("[WARNING] GIAM TOC DO VE 0 TRUOC KHI VE P"), SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_FAIL, cmd);
    }
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::modeRHandler(std::shared_ptr<UserCommand> cmd)
{
    if(state() == GEAR_R){
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }else if(state() == GEAR_D && speed() != 0){
        publish(std::make_shared<WarningMessage>("[WARNING] GIAM TOC DO VE 0 TRUOC KHI VE R"), SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_FAIL, cmd);
    }else if(state() == GEAR_N || state() == GEAR_P){
        setState(GEAR_R);
        setSpeed(7);
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::modeNHandler(std::shared_ptr<UserCommand> cmd)
{
    if(0 == speed()){
        setState(GEAR_N);
        publish(std::make_shared<WarningMessage>("[WARNING] CHU Y SU DUNG PHANH TAY"),SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }else{
        publish(std::make_shared<WarningMessage>("[WARNING] GIAM TOC DO VE 0 TRUOC KHI VE N"), SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_FAIL, cmd);
    }

    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::modeDHandler(std::shared_ptr<UserCommand> cmd)
{
    if(state() == GEAR_D){
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }else if(state() == GEAR_R && speed() != 0){
        publish(std::make_shared<WarningMessage>("[WARNING] GIAM TOC DO VE 0 TRUOC KHI VE D"), SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_FAIL, cmd);
    }else if(state() == GEAR_N || state() == GEAR_P){
        setState(GEAR_D);
        setSpeed(7);
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::speedUpHandler(std::shared_ptr<UserCommand> cmd)
{
    (void)cmd;
    speedUp(5);
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::speedDownHandler(std::shared_ptr<UserCommand> cmd)
{
    (void)cmd;
    speedDown(5);
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::breakHandler(std::shared_ptr<UserCommand> cmd)
{
    (void)cmd;
    setSpeed(0);
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}

void CarEngine::powerOffHandler(std::shared_ptr<UserCommand> cmd)
{
    if(state() == GEAR_P || state() == GEAR_N){
        setState(POWER_OFF);
        cmd->executeCallback(Message::RESPONSE_OK, cmd);
    }else{
        publish(std::make_shared<WarningMessage>("[WARNING] VE P HOAC N TRUOC KHI TAT MAY"), SCREEN_CHANNEL);
        cmd->executeCallback(Message::RESPONSE_FAIL, cmd);
    }
    publish(std::make_shared<CarInformation>(static_cast<GearState>(state()), speed()), SCREEN_CHANNEL);
}



