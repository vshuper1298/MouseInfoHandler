#ifndef SERVER_H
#define SERVER_H

#include "MouseInfo.h"
#include <Windows.h>
#include <winsock.h>

class Server{
public:
	Server();
	~Server();
	struct sockaddr_in createSocket();
	void bindSocket();
	void waitConnection();
        void receiveData();
private:
	static const int portNumber;
	static const char *hostAdress;
	int thisSocket;
	struct sockaddr_in socketAdress;
	MouseInfo mouseInfo;
};

#endif // SERVER_H