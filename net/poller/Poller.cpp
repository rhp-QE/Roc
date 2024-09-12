#include "net/poller/Poller.h"
#include "net/Channel.h"
#include <cassert>
#include <cstring>
#include <memory>
#include <sys/epoll.h>

using namespace::roc;
using namespace::net;

// public method beign ------------------------------
void EPoller::pollAndHandleEvents(int timOutMs) {
    int eventsCount = ::poll(&(*pollfds_.begin()), pollfds_.size(), timOutMs);
    for(auto pollfd = pollfds_.begin(); pollfd != pollfds_.end() && eventsCount > 0; ++ pollfd) {
        if (pollfd->revents > 0) {
            --eventsCount;
            const auto chIter = Channels_.find(pollfd->fd);
            if (chIter == Channels_.end()) {
                return;
            }
            const auto ch = chIter->second;
            assert(ch->fd() == pollfd->fd);
            ch->handleEvent(pollfd->revents);
        }
    }
    return;
}

/// 如果没有则新增， 否则替换
void EPoller::updateChannel(std::shared_ptr<Channel> ch) {
    int fd = ch->fd();
    if(Channels_.find(fd) != Channels_.end()) { // 替换
        Channels_[fd] = ch;
        p_update(EPOLL_CTL_MOD, ch);
    } else { // 新增
        Channels_[fd] = ch;
        p_update(EPOLL_CTL_ADD, ch);
    }
    return;
}


void EPoller::removeChannel(std::shared_ptr<Channel> ch) {
    Channels_.erase(ch->fd());
    p_update(EPOLL_CTL_DEL, ch);
}

// public method end --------------------------------------------

// private method beign -------------------
void EPoller::p_update(int opt, std::shared_ptr<Channel> channel) {
    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = channel->events();

    int fd = channel->fd();
    int result = ::epoll_ctl(epollfd_, opt, fd, &event);
    if (result < 0) {
        // TODO: 错误日志
    }
    return;
}
// private methid end   -------------------

