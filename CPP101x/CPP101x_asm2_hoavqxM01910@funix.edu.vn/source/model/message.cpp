#include "message.h"

Message::Message(const MessageType &type) : mType(type)
{

}

Message::~Message()
{

}

Message::MessageType Message::type() const
{
    return mType;
}

void Message::setType(MessageType newType)
{
    mType = newType;
}

void Message::bindCallback(std::function<void (int, std::shared_ptr<Message>)> fn)
{
    mCallbackResponse = std::bind(fn, std::placeholders::_1, std::placeholders::_2);
}

void Message::executeCallback(int errorCode, std::shared_ptr<Message> responceMessage)
{
    if (mCallbackResponse)
    {
        mCallbackResponse(errorCode, responceMessage);
    }
}
