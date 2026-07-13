#include <string>
struct DatabaseConfiguration{
    std::string name;
    std::string rdbms;
    std::string host;
    int port;
    std::string dbname;
    std::string user;
    std::string passwd;
    bool is_fast;
    int connection_number;
};
