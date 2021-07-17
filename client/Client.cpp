#include "Client.h"

#include <common/DBusConfig.h>

#include <iostream>

Client::Client(RunFunc f)
    : m_proxy{sdbus::createProxy(sdbus::createSessionBusConnection(), common::bus, common::object)}
{
    m_proxy->registerSignalHandler(common::interface, "start", std::move(f));
    m_proxy->finishRegistration();
}

void Client::fetch()
{
    m_proxy->callMethod(m_proxy->createMethodCall(common::interface, "fetch"));
}
