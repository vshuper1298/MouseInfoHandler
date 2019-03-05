// Client.cpp : Defines the entry point for the console application.
//

#include "Client.h"
#include <thread>
#include <functional>

int main(int argc, char* argv[]){
	Client client;
	client.makeConnection();
        std::thread catchMouseCoord(client.startTimer, std::ref(client));
        std::thread catchMouseClick(client.waitForClick, std::ref(client));
        catchMouseCoord.join();
        catchMouseClick.join();
	return 0;
}

