#ifndef _ROC_IPOLLER_H_
#define _ROC_IPOLLER_H_

#include <memory>
#include <vector>

#include "base/noncopyable.h"

namespace roc{
namespace net {

class Channel;

/// Interface
class IPoller : public noncopyable{

public:
    /// 获取激活事件并处理
    virtual std::vector<std::weak_ptr<Channel>> poll(int timeOutMs);

    /// 更新Channel。有则更新，没有则添加
    virtual void updateChannel(std::weak_ptr<Channel> ch);

    virtual void insertChannel(std::weak_ptr<Channel> ch);

    /// 删除Channel
    virtual void eraseChannel(std::weak_ptr<Channel> ch);

    virtual ~IPoller(){}
};

}
}

#endif // _ROC_POLLER_H_