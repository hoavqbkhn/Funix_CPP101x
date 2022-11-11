#include "usercommand.h"

UserCommand::UserCommand(const Command &cmd)
    : Message(Message::USER_COMMAND_MESSAGE),
      mCommand(cmd)
{

}

UserCommand::~UserCommand()
{

}

UserCommand::Command UserCommand::command() const
{
    return mCommand;
}

void UserCommand::setCommand(Command newCommand)
{
    mCommand = newCommand;
}
