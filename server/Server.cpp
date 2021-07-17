#include "Server.h"

Server::Server()
    : m_connection{sdbus::createSessionBusConnection(bus)}
    , m_object{sdbus::createObject(*m_connection, object)}
    , m_data(m_numElements)
{
    m_object->registerMethod(interface, "fetch", "", "au", [&](auto m){ fetch(std::move(m)); });
    m_object->registerSignal(interface, "start", "");
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
    m_object->emitSignal(m_object->createSignal(interface, "start"));
}
