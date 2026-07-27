#include <drogon/orm/DbClient.h>

class Database{
public:
    static drogon::orm::DbClientPtr getClient(const std::string databaseName);

};
