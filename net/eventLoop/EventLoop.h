#ifndef _ROC_EVENTLOOP_H_
#define _ROC_EVENTLOOP_H_

#include "net/Channel.h"
#include "net/poller/IPoller.h"
#include "base/noncopyable.h"
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace roc {
namespace net {

class EventLoop : public noncopyable {

public:
    EventLoop();
    
    void insertChannel(std::shared_ptr<Channel> channel);
    void eraseChannel(std::shared_ptr<Channel> channel);
    void updateChannel(std::shared_ptr<Channel> channel);

    void runInLoop(std::function<void(void)> task);

    void start();

private:
    /// 保证调用都在本线程内完成
    void safeCall(std::function<void()> task);

    void handleChannelEvent(const std::vector<std::weak_ptr<Channel>>& channels);
    void handleTasks();

    std::thread thread_;
    std::mutex mute_;
    std::unique_ptr<IPoller> poller_;
    std::thread::id threadID;
    std::vector<std::function<void()>> taskQue_;
    bool quite_;
    int pollTimeOutMs_;
};

}

}
#endif // _ROC_EVENTLOOP_H_