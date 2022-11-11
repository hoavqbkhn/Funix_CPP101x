#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
public:
    Engine();
    virtual ~Engine();

    virtual void start() = 0;

    int state() const;
    void setState(int newState);

    int speed() const;
    void setSpeed(int newSpeed);

private:
    int mState;
    int mSpeed;

};

#endif // ENGINE_H
