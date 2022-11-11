#include "channel.h"
#include "channelmanager.h"
Channel::Channel(const std::string &channelName) : mChannelName(channelName)
{
    ChannelManager::getInstance()->registerChannel(this);
}

std::string &Channel::channelName()
{
    return mChannelName;
}

Channel::~Channel()
{

}

void Channel::publish(std::shared_ptr<Message> msg, const std::string &channelName)
{
    ChannelManager::getInstance()->sendMessageToChannel(msg, channelName);
}

