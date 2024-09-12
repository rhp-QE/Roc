#include "net/Channel.h"
#include "base/maroc.h"
#include <chrono>
#include <functional>

using namespace roc;
using namespace roc::net;


Channel::Channel(int fd)
    : fd_(fd)
{}

void Channel::handleEvent(int events) const
{
    if (events & ChannelEventMaskEnum::READ) {
        roc::safe_invoke(readCallback_, std::chrono::system_clock::now());
    }
    if (events & ChannelEventMaskEnum::WRITE) {
        roc::safe_invoke(writeCallback_);
    }
    if (events & ChannelEventMaskEnum::CLOSE) {
        roc::safe_invoke(closeCallbacl_);
    }
    if (events & ChannelEventMaskEnum::ERROR) {
        roc::safe_invoke(errorCallback_);
    }
}

void Channel::setErrorCallback(std::function<void()> errorCallback)
{
    errorCallback_ = std::move(errorCallback);
}

void Channel::setCloseCallback(std::function<void()> closeCallbacl)
{
    closeCallbacl_ = std::move(closeCallbacl);
}

void Channel::setWriteCallback(std::function<void()> writeCallback)
{
    writeCallback_ = std::move(writeCallback);
}

void Channel::setReadCallback(std::function<void(std::chrono::system_clock::time_point)> readCallback)
{
    readCallback_ = std::move(readCallback);
}

int Channel::fd() {
    return fd_;
}

void enableRead(bool enable) {
    
}

void enableWrite(bool enable) {

}

