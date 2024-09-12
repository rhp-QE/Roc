#ifndef _ROC_CHANNELMANAGER_H_
#define _ROC_CHANNELMANAGER_H_

#include "base/copyable.h"
#include "base/noncopyable.h"
#include "net/Channel.h"
#include <memory>
#include <unordered_map>

namespace roc{
namespace net {

/// 作为激活Channel的入参
/// 值语意
class ActiveEvent : public copyable {
public:
    ActiveEvent(int fd, ChannelEventMaskEnum event):
        fd_(fd),
        event_(event)
    {}

    int fd() const { return fd_; }
    ChannelEventMaskEnum event() const { return event_; }


private:
    int fd_;
    ChannelEventMaskEnum event_;
};


/// 管理Channel。
/// 对象语义。
/// 线程安全： 由EventLoop 持有， 只暴露给EventLoop 所在线程（单线程）。
class ChannelManager : public noncopyable {
public:
    void eraseChannel(int fd);
    void handle(const std::vector<ActiveEvent>& activeEvent);
    void insertChannel(int fd, std::unique_ptr<Channel> channel);

private:
    std::unordered_map<int, std::unique_ptr<Channel>> channelUmap_;
};


}
}


#endif // _ROC_CHANNELMANAGER_H_