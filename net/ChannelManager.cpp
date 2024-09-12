#include "net/ChannelManager.h"
#include "net/Channel.h"
#include <utility>

using namespace roc;
using namespace roc::net;

void ChannelManager::insertChannel(int fd, std::unique_ptr<Channel> channel)
{
    if (channelUmap_.find(fd) == channelUmap_.end()) {
        channelUmap_.insert({fd, std::move(channel)});
    }
}


void ChannelManager::eraseChannel(int fd)
{
    channelUmap_.erase(fd);
}

void ChannelManager::handle(const std::vector<ActiveEvent>& activeEvent)
{
    for (const auto &event : activeEvent) {
        if (channelUmap_.find(event.fd()) != channelUmap_.end()) {
            const auto& channel = *channelUmap_.find(event.fd())->second;
            channel.handleEvent(event.event());
        }
    }
}