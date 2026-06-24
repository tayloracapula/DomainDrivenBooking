#include "infrastructure/server/ServerCore.hpp"
#include <drogon/HttpAppFramework.h>
#include <string>

Server::Server(std::string address, int port) : address(address), port(port) {}
int Server::startServer() {
    drogon::app().addListener(address, port);

    drogon::app().run();
    return 0;
}
