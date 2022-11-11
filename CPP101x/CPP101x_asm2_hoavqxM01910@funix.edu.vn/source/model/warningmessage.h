#ifndef WARNINGMESSAGE_H
#define WARNINGMESSAGE_H
#include <string>

#include "message.h"

class WarningMessage : public Message
{
public:
    WarningMessage(const std::string& warning);
    ~WarningMessage();

    const std::string &warning() const;
    void setWarning(const std::string &newWarning);

private:
    std::string mWarning;
};

#endif // WARNINGMESSAGE_H
