#pragma once

#include <string>

class Server {
public:
    explicit Server(
	std::string configPath,
	std::string databaseName)
	: 
	configPath_(std::move(configPath)),
	databaseName_(std::move(databaseName)
	)
{}
    void initialise();

    int start();

private:
    std::string configPath_;
    std::string databaseName_;
};
