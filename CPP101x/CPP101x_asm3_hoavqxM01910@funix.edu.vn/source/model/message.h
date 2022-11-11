#ifndef MESSAGE_H
#define MESSAGE_H

#include <functional>
#include <memory>

class Message
{
public:
    enum MessageType{
        WARNING_MESSAGE,
        USER_COMMAND_MESSAGE,
        CAR_INFORMATION_MESSAGE,
    };

    enum ResponseCode{
        RESPONSE_OK = 0,
        RESPONSE_FAIL
    };

    Message(const MessageType& type);
    virtual ~Message();

    MessageType type() const;
    void setType(MessageType newType);

    virtual void bindCallback(std::function<void(int, std::shared_ptr<Message>)> fn);
    virtual void executeCallback(int errorCode, std::shared_ptr<Message> responceMessage);

private:
    MessageType mType;
    std::function<void(int, std::shared_ptr<Message>)> mCallbackResponse;
};

#endif // MESSAGE_H
