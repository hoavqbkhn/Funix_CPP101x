#ifndef USERUPDATEPERSONALKEY_H
#define USERUPDATEPERSONALKEY_H
#include <string>
#include "userchoice.h"

class UserUpdatePersonalKey : public UserChoice
{
public:
    UserUpdatePersonalKey(std::string newPersonalKey);
    ~UserUpdatePersonalKey();
    const std::string &newPersonalKey() const;

private:
    std::string mNewPersonalKey{""};
};

#endif // USERUPDATEPERSONALKEY_H
