#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <memory>
#include <list>


#include "screen.h"


class ScreenManager
{
public:
    ScreenManager();
    virtual ~ScreenManager();

    const std::shared_ptr<Screen> &screen() const;
    void setScreen(const std::shared_ptr<Screen> &newScreen);

    void clearScreen();

    virtual void start() = 0;
    virtual void processLoop() = 0;


private:
    std::shared_ptr<Screen> mScreen;


};

#endif // SCREENMANAGER_H
