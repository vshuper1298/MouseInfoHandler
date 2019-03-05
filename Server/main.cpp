// Server.cpp : Defines the entry point for the console application.
//

#include "Server.h"

int main(int argc, char* argv[]){
        Server server;
        server.waitConnection();
        server.receiveData();
        return 0;
}
