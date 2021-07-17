#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <functional>
#include <memory>

struct Client
{
    using Proxy = std::unique_ptr<sdbus::IProxy>;
    using Connection = std::unique_ptr<sdbus::IConnection>;
    using RunFunc = std::function<void(sdbus::Signal&)>;

    Client(RunFunc);

    void fetch();

    Proxy m_proxy;
};
