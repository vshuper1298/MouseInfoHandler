#include "Client.h"
#include <cstdio>


Client::Client(){
	socketAdress = createSocket();
}

const char* Client::hostAdress = "127.0.0.1";
const int Client::portNumber = 13374;

struct sockaddr_in Client::createSocket(){
	// Initializing Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}
	struct sockaddr_in sock;
	sock.sin_family = AF_INET;
	sock.sin_port = htons(portNumber);
	sock.sin_addr.s_addr = inet_addr(hostAdress);
	thisSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (thisSocket < 0){
		printf("Socket Creation FAILED!\n");
	}
	return sock;
}

void Client::makeConnection(){
	if (connect(thisSocket, (struct sockaddr *)&socketAdress, sizeof(socketAdress)) != 0){
		printf("Socket Connection FAILED!\n");
		if (thisSocket)
			closesocket(thisSocket);
	}
	else{
		printf("Connected!\n");
	}
}

void Client::startTimer(){
	const int BUFFERSIZE = 12;
	int start;
	int end = 0;
	while (1){
		start = GetTickCount();
		while (end - start < 500){
			end = GetTickCount();
		}

		POINT p;
                if (GetCursorPos(&p)){
                        mtx.lock();
			int x = p.x;
			int y = p.y;
			buffer[0] = x;
			buffer[1] = y;
			buffer[2] = 0;
			send(thisSocket, (char*)buffer, BUFFERSIZE, 0);
                        mtx.unlock();
		}
		end = 0;
	}
}

void Client::waitForClick()
{
    const int BUFFERSIZE = 12;
    while (1){
	Sleep(200);
        if (GetAsyncKeyState(VK_LBUTTON)){
            mtx.lock();
            buffer[2] = 1;
            send(thisSocket, (char*)buffer, BUFFERSIZE, 0);
            mtx.unlock();
        }

        if (GetAsyncKeyState(VK_RBUTTON)){
            mtx.lock();
            buffer[2] = 2;
            send(thisSocket, (char*)buffer, BUFFERSIZE, 0);
            mtx.unlock();
        }
    }
}

Client::~Client(){
	closesocket(thisSocket);
	WSACleanup();
}
