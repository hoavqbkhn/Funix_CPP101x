#ifndef SCREEN_H
#define SCREEN_H
#include <memory>

#include <iostream>
#include <string>
#include <sstream>

#include <model/userchoice.h>

class Screen
{
public:
    Screen();
    virtual ~Screen();

    virtual void process() = 0;
    const std::string &getInput() const;
    const std::shared_ptr<UserChoice> &userChoice() const;

protected:
    virtual bool isValidInput() = 0;
    void setInput(const std::string &newInput);
    void setUserChoice(const std::shared_ptr<UserChoice> &newUserChoice);

private:
    std::string mInput{""};
    std::shared_ptr<UserChoice> mUserChoice;
};

#endif // SCREEN_H
