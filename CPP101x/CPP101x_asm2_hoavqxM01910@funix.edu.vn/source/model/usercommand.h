#ifndef USERCOMMAND_H
#define USERCOMMAND_H
#include "message.h"

class UserCommand : public Message
{
public:
    enum Command{
        CHANGE_TO_GEAR_P = 0,
        CHANGE_TO_GEAR_R,
        CHANGE_TO_GEAR_N,
        CHANGE_TO_GEAR_D,
        POWER_OFF,
        SPEED_UP,
        SPEED_DOWN,
        BREAK,
    };
    UserCommand(const Command& cmd);
    ~UserCommand();
    Command command() const;
    void setCommand(Command newCommand);

private:
    Command mCommand;


};

#endif // USERCOMMAND_H
