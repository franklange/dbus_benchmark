#include "Server.h"

#include <iostream>
#include <string>
#include <thread>

void run_server(Server& s)
{
    s.run();
}

auto main() -> int
{
    Server server;
    std::thread srvRunner{run_server, std::ref(server)};

    std::string input;
    std::getline(std::cin, input);

    server.emitStart();

    srvRunner.join();

    return 0;
}
