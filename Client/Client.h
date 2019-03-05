#ifndef CLIENT_H
#define CLIENT_H

#include <Windows.h>
#include <winsock.h>
#include <mutex>

class Client{
public:
	Client();
	~Client();
	struct sockaddr_in createSocket();
	void makeConnection();
	void startTimer();
        void waitForClick();
private:
	static const int portNumber;
	static const char *hostAdress;
	int thisSocket;
	struct sockaddr_in socketAdress;
	int buffer[3];
        mutable std::mutex mtx;
};

#endif // CLIENT_H
