#ifndef CARENGINE_H
#define CARENGINE_H

#include "model/channel.h"
#include "model/usercommand.h"

#include "engine/engine.h"

class CarEngine : public Engine, Channel
{
public:

    CarEngine();
    ~CarEngine();

    void start() override;

    void onMessage(std::shared_ptr<Message> msg) override;

private:

    void handleUserCommand(std::shared_ptr<UserCommand> cmd);
    void checkSafety();
    void modePHandler(std::shared_ptr<UserCommand> cmd);
    void modeRHandler(std::shared_ptr<UserCommand> cmd);
    void modeNHandler(std::shared_ptr<UserCommand> cmd);
    void modeDHandler(std::shared_ptr<UserCommand> cmd);
    void speedUpHandler(std::shared_ptr<UserCommand> cmd);
    void speedDownHandler(std::shared_ptr<UserCommand> cmd);
    void breakHandler(std::shared_ptr<UserCommand> cmd);
    void powerOffHandler(std::shared_ptr<UserCommand> cmd);
    void powerOn() ;
    void speedUp(int add) ;
    void speedDown(int minus) ;



};

#endif // CARENGINE_H
