#pragma once
#include <string>

class Server {
public:
    Server(std::string address, int port);
    
    std::string address;
    int port;
    
    int startServer();
};
