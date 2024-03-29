#pragma once

#include "IEventLoop.h"
#include <functional>
#include <memory>

namespace LogEventHandling
{

class EventLoop : public IEventLoop
{
public:
    EventLoop();
    ~EventLoop();

    EventLoop(const EventLoop&) = delete;
    EventLoop& operator=(const EventLoop&) = delete;
    EventLoop(EventLoop&&) = delete;
    EventLoop& operator=(EventLoop&&) = delete;

    void post(const std::function<void()>&) final;

    void post(void (*)()) final;

    void start() final;

    void stop() final;

    template<typename T, typename ...A>
    void post(const std::function<T(A...)>& f, A&&... args) {
        post([&]() -> void {f(std::forward<A>(args)...);});
    }

private:
    struct Impl;
    std::unique_ptr<Impl> p;
};

}