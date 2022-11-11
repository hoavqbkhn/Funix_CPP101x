#include "warningmessage.h"

WarningMessage::WarningMessage(const std::string& warning)
    : Message(Message::WARNING_MESSAGE),
      mWarning(warning)
{
}

WarningMessage::~WarningMessage()
{

}

const std::string &WarningMessage::warning() const
{
    return mWarning;
}

void WarningMessage::setWarning(const std::string &newWarning)
{
    mWarning = newWarning;
}
