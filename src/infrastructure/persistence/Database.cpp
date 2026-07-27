#include "infrastructure/persistence/Database.hpp"
#include <drogon/HttpAppFramework.h>
#include <drogon/orm/DbClient.h>

drogon::orm::DbClientPtr Database::getClient(const std::string databaseName)
{
    return drogon::app().getDbClient(databaseName);
}
