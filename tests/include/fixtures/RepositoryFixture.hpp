#include <drogon/HttpAppFramework.h>
#include <drogon/orm/DbClient.h>
#include "../TestEnvironment.hpp"
struct RepositoryFixture
{
    drogon::orm::DbClientPtr db;

    RepositoryFixture()
    {
	TestEnvironment::initialise();

	db = drogon::app().getDbClient("test");

	clearDatabase();
    }
private:
    void clearDatabase();
};
