#include "infrastructure/server/ServerCore.hpp"
#include "infrastructure/server/RepositoryRegistry.hpp"
#include "infrastructure/server/ApplicationServices.hpp"
#include "infrastructure/persistence/DrogonLeaveRepository.hpp"
#include "infrastructure/persistence/DrogonLeaveAllowanceRepository.hpp"
#include "infrastructure/persistence/DrogonStaffRepository.hpp"

#include <cstdio>
#include <drogon/HttpAppFramework.h>
#include <memory>

void Server::initialise(){
    drogon::app().loadConfigFile(configPath_);

    drogon::app().registerBeginningAdvice(
    [this]
    {
	auto db = drogon::app().getDbClient(databaseName_);
	
	RepositoryRegistry::instance().setLeaveRepository(std::make_shared<DrogonLeaveRepository>(db));

	RepositoryRegistry::instance().setLeaveAllowanceRepository(std::make_shared<DrogonLeaveAllowanceRepository>(db));

	RepositoryRegistry::instance().setStaffRepository(std::make_shared<DrogonStaffRepository>(db));

	ApplicationServices::instance().initialise();
    });
    //Drogon automatically scans for its controllers and database on setup so there is no need to configure routing manually
}

int Server::start() {
    drogon::app().run();
    return 0;
}
