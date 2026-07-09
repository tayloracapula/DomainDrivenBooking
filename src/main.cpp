#include <exception>
#include <iostream>
#include "infrastructure/server/ServerCore.hpp"
using namespace std;

int main() {
    try {   
	cout << "Starting Server\n";
	Server myServer;
	
	myServer.startServer();

	return 0;
    } catch (const exception& e){
	//add global error handling here
	cout << e.what();
	return 1;
    }
}
