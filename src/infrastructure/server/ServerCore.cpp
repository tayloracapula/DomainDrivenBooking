#include "infrastructure/server/ServerCore.hpp"
#include <drogon/HttpAppFramework.h>
#include <string>

int Server::startServer() {
    drogon::app().loadConfigFile("./config/config.json");

    //Drogon automatically scans for its controllers on setup so there is no need to configure routing manually
    drogon::app().run();
    return 0;
}
