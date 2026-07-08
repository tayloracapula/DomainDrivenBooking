#include <string>
class ServerConfiguration{
public:
    std::string address;
    int port;
    bool reuseAddress;
    std::size_t threadCount;
};
