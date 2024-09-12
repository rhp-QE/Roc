#include "net/Acceptor/Acceptor.h"

#include "net/Channel.h"
#include "net/Socket/InetAddress.h"
#include "net/Socket/Socket.h"
#include "net/eventLoop/EventLoop.h"
#include <memory>

using namespace roc;
using namespace roc::net;


Acceptor::Acceptor(std::shared_ptr<EventLoop> eventLoop, InetAddress listenAddress) :
    eventLoop_(eventLoop),
    socket_(std::make_unique<Socket>(listenAddress)),
    channel_(std::make_shared<Channel>())
{
    

    channel_->setReadCallback([this](std::chrono::system_clock::time_point) {
        this->readCallback();
    });
}
