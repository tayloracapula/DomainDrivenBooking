#pragma once
#include "infrastructure/server/ServerCore.hpp"

class TestEnvironment{
public:
    static void initialise(){
	static bool initialised = false;

	if (initialised) {
	    return;
	}

	static Server server("config/config.json","test");

	server.initialise();
	initialised = true;
    }
};
