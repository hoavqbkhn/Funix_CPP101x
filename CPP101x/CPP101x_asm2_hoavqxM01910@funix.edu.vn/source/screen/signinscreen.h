#ifndef SIGNINSCREEN_H
#define SIGNINSCREEN_H
#include <string>

#include "screen.h"

using namespace std;

class SignInScreen : public Screen
{
public:
    SignInScreen();
    ~SignInScreen();
    void process() override;

private:

    bool isValidInput() override;
    int *mInputID;
    int *mDefaultID;


};

#endif // SIGNINSCREEN_H
