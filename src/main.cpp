#include <exception>
#include <iostream>
#include "infrastructure/server/ServerCore.hpp"
using namespace std;

int main() {
    try {   
	cout << "Starting Server\n";
	Server Server("config/config.json","default");
	
	Server.initialise();
	Server.start();

	return 0;
    } catch (const exception& e){
	//add global error handling here
	cout << e.what();
	return 1;
    }
}
