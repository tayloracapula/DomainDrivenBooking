#include <drogon/orm/DbClient.h>
#include "DatabaseConfiguration.hpp"
class Database{
public:
    static drogon::orm::DbClient create(const DatabaseConfiguration& config);

};
