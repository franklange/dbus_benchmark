#include "Server.h"

#include <common/DBusConfig.h>

#include <iostream>

Server::Server()
    : m_connection{sdbus::createSessionBusConnection(common::bus)}
    , m_object{sdbus::createObject(*m_connection, common::object)}
    , m_data(m_numElements)
{
    m_object->registerMethod(common::interface, "fetch", "", "au", [&](auto m){ fetch(std::move(m)); });
    m_object->registerSignal(common::interface, "start", "s");
    m_object->finishRegistration();
}

void Server::run()
{
    m_connection->enterEventLoop();
}

void Server::fetch(sdbus::MethodCall c)
{
    auto reply = c.createReply();
    reply << m_data;
    reply.send();
}

void Server::emitStart()
{
    auto s = m_object->createSignal(common::interface, "start");
    s << "start";
    m_object->emitSignal(s);
    std::cout << "signal emitted" << std::endl;
}
