#ifndef _ROC_CHANNEL_H_
#define _ROC_CHANNEL_H_

#include "net/poller/IPoller.h"
#include <functional>
#include <chrono>

namespace roc {
namespace net {


enum ChannelEventMaskEnum {
    READ  = 1 << 0,
    WRITE = 1 << 1,
    CLOSE = 1 << 2,
    ERROR = 1 << 3,
};

/// 职责
/// 1、维护文件描述符到其回调函数的映射
class Channel {
public:
    Channel(int fd);
    int fd();
    /// 需要监听的事件
    int events();
    void handleEvent() const;
    void enableRead(bool enable);
    void enableWrite(bool enable);
    void setErrorCallback(std::function<void()> errorCallback);
    void setCloseCallback(std::function<void()> closeCallbacl);
    void setWriteCallback(std::function<void()> writeCallback);
    void setReadCallback(std::function<void(std::chrono::system_clock::time_point)> readCallback);

private:
    std::function<void(std::chrono::system_clock::time_point)> readCallback_;
    std::function<void()> writeCallback_;
    std::function<void()> errorCallback_;
    std::function<void()> closeCallbacl_;

    int fd_; 
    int events_;
    
};


}// namespace net
}// namespace roc

#endif // _ROC_CHANNEL_H_