#include <exception>
#include <iostream>
#include "infrastructure/server/ServerCore.hpp"
using namespace std;

int main() {
    try {   
	cout << "Starting Server\n";
	Server myServer("0.0.0.0", 8000);
	
	myServer.startServer();

	return 0;
    } catch (const std::exception& e){
	//add global error handling here
	cout << e.what();
	return 1;
    }
}
