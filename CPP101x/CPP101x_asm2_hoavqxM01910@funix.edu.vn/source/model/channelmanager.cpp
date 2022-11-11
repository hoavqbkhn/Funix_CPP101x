#include "channelmanager.h"
ChannelManager ChannelManager::self;
ChannelManager *ChannelManager::getInstance()
{
    return &self;
}

ChannelManager::~ChannelManager()
{

}

void ChannelManager::registerChannel(Channel* channel)
{
    mMapChannel[channel->channelName()] = channel;
}

void ChannelManager::deregisterChannel(std::string channelName)
{
    mMapChannel.erase(channelName);
}

void ChannelManager::sendMessageToChannel(std::shared_ptr<Message> msg, std::string channelName)
{
    mMapChannel[channelName]->onMessage(msg);
}

ChannelManager::ChannelManager()
{

}
