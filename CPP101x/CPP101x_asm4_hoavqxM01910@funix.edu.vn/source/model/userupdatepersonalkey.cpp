#include "userupdatepersonalkey.h"

UserUpdatePersonalKey::UserUpdatePersonalKey(std::string newPersonalKey)
    : UserChoice(ConfigPersonalKeyScreen),
      mNewPersonalKey(newPersonalKey)
{

}

UserUpdatePersonalKey::~UserUpdatePersonalKey()
{

}

const std::string &UserUpdatePersonalKey::newPersonalKey() const
{
    return mNewPersonalKey;
}
