#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class nSocket {

private:

	int sock;
	int sockToSend;
	struct sockaddr_in sockAddr;
	struct sockaddr_in sockToSendAddr;
	int sockToSendAddrSize;
	
public:

	void setSock(int sock);
	int getSock();
	int getSockToSend();
	sockaddr_in getSockAddr();

	void initSock();
	void initSockAddr(string IP, string port);
	void initSockAddrSelf(string port);
	void connectSock(int sock, sockaddr_in sockAddr);
	void acceptSock(int sock, sockaddr_in sockAddr);

	void errorHandling(char* message);

	char* convertStringToChar(const string &str);
	int atoi(char *str);
};
