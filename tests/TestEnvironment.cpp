#include "include/TestEnvironment.hpp"
#include "infrastructure/server/ServerCore.hpp"

void TestEnvironment::initialise(){
    static bool initialised = false;

    if (initialised) {
	return;
    }

    Server server("config/config.json","test");

    server.initialise();
    initialised = true;
}
