#ifndef CHANNELMANAGER_H
#define CHANNELMANAGER_H

#include <memory>
#include <unordered_map>
#include <map>
#include <string>

#include "channel.h"
#include "message.h"

using namespace std;
class ChannelManager
{

public:
    static ChannelManager* getInstance();
    ~ChannelManager();

    /**
     * @brief registerChannel
     * @param Channel
     * @return
     * register Channel to messages bus
     */
    void registerChannel(Channel* channel);

    /**
     * @brief deregisterChannel
     * @param ChannelName
     * @return
     * deregister Channel to messages bus
     */
    void deregisterChannel(std::string channelName);
    /**
     * @brief publishToChannel
     * @param msg
     * @param ChannelName
     * @return
     * send msg to specified Channel
     */
    void sendMessageToChannel(std::shared_ptr<Message> msg, std::string channelName);


private:
    ChannelManager();
    static ChannelManager self;
    std::unordered_map<string, Channel*> mMapChannel;
};

#endif // CHANNELMANAGER_H
