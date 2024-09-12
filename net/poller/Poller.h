#ifndef _ROC_POLLER_H_
#define _ROC_POLLER_H_

#include <memory>
#include <poll.h>
#include <vector>
#include <unordered_map>

#include "net/Channel.h"
#include "net/poller/IPoller.h"

namespace roc{
namespace net {

class EPoller : public IPoller{

public:
    /// 获取激活事件并处理
    void pollAndHandleEvents(int timeOutMs);

    /// 更新Channel。有则更新，没有则添加
    void updateChannel(std::weak_ptr<Channel> ch) override;

    /// 删除Channel。
    void eraseChannel(std::weak_ptr<Channel> ch) override;

    void insertChannel(std::weak_ptr<Channel> ch) override;

private:
    using EPOLL_OPT_TYPE = int;
    void p_update(EPOLL_OPT_TYPE opt, std::shared_ptr<Channel> channel);

    int epollfd_;
    std::unordered_map<int, std::shared_ptr<Channel>> Channels_;
    std::vector<struct pollfd> pollfds_;
};

}
}

#endif // _ROC_POLLER_H_