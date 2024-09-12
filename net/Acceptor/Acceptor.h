#ifndef _ROC_ACCEPTOR_H_
#define _ROC_ACCEPTOR_H_

#include "base/noncopyable.h"
#include "net/Channel.h"
#include <memory>

namespace roc {
namespace net {

// pre declare -------------
class InetAddress;
class EventLoop;
class Socket;
class Channel;
// -------------------------

class Acceptor : public noncopyable {
public:
    Acceptor(std::shared_ptr<EventLoop> eventLoop, InetAddress listenAddress);
    ~Acceptor();
private:
    std::weak_ptr<EventLoop> eventLoop_;
    std::unique_ptr<Socket> socket_;
    std::shared_ptr<Channel> channel_;

    void readCallback();

    void onNewConnection();
};

}
}

#endif // _ROC_ACCEPTOR_H_