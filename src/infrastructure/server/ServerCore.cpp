#include "infrastructure/server/ServerCore.hpp"
#include <drogon/HttpAppFramework.h>
#include <string>

int Server::startServer() {
    drogon::app().loadConfigFile("./config/config.json");

    drogon::app().run();
    return 0;
}
