#include "Server.h"

#include <iostream>
#include <string>
#include <thread>

void start_clients(Server& s)
{
    std::string input;
    std::getline(std::cin, input);

    s.emitStart();
}

auto main() -> int
{
    Server server;
    std::thread cmdlineRunner{start_clients, std::ref(server)};

    server.run();

    return 0;
}
