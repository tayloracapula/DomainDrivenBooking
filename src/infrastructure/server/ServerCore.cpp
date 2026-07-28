#include "infrastructure/server/ServerCore.hpp"
#include <cstdio>
#include <drogon/HttpAppFramework.h>

void Server::initialise(){
    drogon::app().loadConfigFile(configPath_);

    drogon::app().registerBeginningAdvice(
    [this]
    {
    auto db = drogon::app().getDbClient(databaseName_);
    });
    //Drogon automatically scans for its controllers and database on setup so there is no need to configure routing manually
}

int Server::start() {
    drogon::app().run();
    return 0;
}
