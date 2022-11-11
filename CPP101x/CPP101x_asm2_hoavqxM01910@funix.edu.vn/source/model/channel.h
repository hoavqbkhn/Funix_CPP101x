#ifndef CHANNEL_H
#define CHANNEL_H
#include <string>
#include <memory>

#include "message.h"


/**
     * @brief Channel
     * @param ChannelName
     * abstract class for all Channel
     */
class Channel
{
    public:
        Channel(const std::string& ChannelName);
        virtual ~Channel();

        /**
         * @brief send message "msg" to Channel having name "ChannelName"
         * @param msg: msg to publish
         * @param ChannelName: Channel to publish to
         * @return
         */
        void publish(std::shared_ptr<Message> msg, const std::string& channelName);
        virtual void onMessage(std::shared_ptr<Message> msg) = 0;

        std::string &channelName();

private:
        Channel(const Channel&) = delete;
        Channel(Channel&&) = delete;
        Channel& operator=(const Channel&) = delete;
        Channel& operator=(Channel &&) = delete;

    private:
        std::string mChannelName;
};

#endif // CHANNEL_H
