#include "net/eventLoop/EventLoop.h"
#include <functional>
#include <memory>
#include <mutex>
#include <vector>
#include "base/macro.h"
#include "net/Channel.h"

using namespace roc;
using namespace net;

EventLoop::EventLoop() {

}
void EventLoop::insertChannel(std::shared_ptr<Channel> channel) {
    safeCall([this, channel](){
        this->poller_->insertChannel(channel);
    });
}
void EventLoop::eraseChannel(std::shared_ptr<Channel> channel) {
    safeCall([this, channel]() {
        this->poller_->eraseChannel(channel);
    });
}
void EventLoop::updateChannel(std::shared_ptr<Channel> channel) {
    safeCall([this, channel]() {
        this->poller_->updateChannel(channel);
    });
}

void EventLoop::runInLoop(std::function<void(void)> task) {
    safeCall(task);
}

void EventLoop::start() {
    while(!quite_) {
        std::vector<std::weak_ptr<Channel>> channels = poller_->poll(pollTimeOutMs_);
        handleChannelEvent(channels);
        handleTasks();
    }
}


/// -- private method begin --------------
void EventLoop::handleChannelEvent(const std::vector<std::weak_ptr<Channel>>& channels) {
    for (const auto &channel : channels) {
        auto ch = channel.lock();
        if (ch) {
            ch->handleEvent();
        }
    }
}


void EventLoop::handleTasks() {
    std::vector<std::function<void()>> tasks;
    {
        std::lock_guard<std::mutex> lock(mute_);
        tasks.swap(taskQue_);
    }
    for (const auto &task : tasks) {
        task();
    }
}

void EventLoop::safeCall(std::function<void(void)> task) {
    if (threadID == std::this_thread::get_id()) {
        task();
    } else {
        {
            std::lock_guard<std::mutex> lock(mute_);
            taskQue_.emplace_back(task);
        }
    }
}

/// -- private method end --------------