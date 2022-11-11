#ifndef USERCHOICE_H
#define USERCHOICE_H


class UserChoice
{
public:
    enum ScreenType{
        SignInScreen = 0,
        GearScreen,
        ControlSpeedScreen,
    };
    UserChoice(const ScreenType& type);
    virtual ~UserChoice();


    ScreenType screenType() const;
    void setScreenType(ScreenType newScreenType);

private:
    ScreenType mScreenType;
};

#endif // USERCHOICE_H
