#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

const std::string bus{"org.dbus.benchmark"};
const std::string object{"/org/dbus/benchmark"};
const std::string interface{"org.dbus.benchmark"};

using Connection = std::unique_ptr<sdbus::IConnection>;
using Object = std::unique_ptr<sdbus::IObject>;
using Data = std::vector<std::uint32_t>;

struct Server
{
    Server();

    void run();

    void fetch(sdbus::MethodCall);
    void emitStart();

    Connection m_connection;
    Object m_object;

    const Data m_data;
    const std::uint32_t m_numElements{64};
};
