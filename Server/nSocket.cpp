#include "nSocket.h"

void nSocket::setSock(int sock) {
	this->sock = sock;
}

int nSocket::getSock() {
	return this->sock;
}

int nSocket::getSockToSend() {
	return this->sockToSend;
}

sockaddr_in nSocket::getSockAddr() {
	return this->sockAddr;
}

void nSocket::initSock() {
	
	this->sock = socket(PF_INET, SOCK_STREAM, 0);
	if(this->sock==-1)
		errorHandling("socket() error");
}

void nSocket::initSockAddr(string IP, string port) {
	
	memset(&sockAddr, 0, sizeof(this->sockAddr));
	sockAddr.sin_family=AF_INET;
	
	char* pStr = convertStringToChar(IP);
	sockAddr.sin_addr.s_addr=inet_addr(pStr);
	
	char* pStr2 = convertStringToChar(port);
	sockAddr.sin_port=htons(atoi(pStr2));
}

void nSocket::initSockAddrSelf(string port) {
	
	memset(&sockAddr, 0, sizeof(this->sockAddr));
	sockAddr.sin_family=AF_INET;
	sockAddr.sin_addr.s_addr=htonl(INADDR_ANY);

	char* pStr2 = convertStringToChar(port);
	sockAddr.sin_port=htons(atoi(pStr2));
}

void nSocket::connectSock(int sock, sockaddr_in sockAddr) {
	if(connect(sock, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == -1)
		errorHandling("connect() error");
}

void nSocket::acceptSock(int sock, sockaddr_in sockAddr) {
	if(bind(sock, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == -1)
		errorHandling("sock bind() error");
	if(listen(sock, 5) == -1)
		errorHandling("sock listen() error");
	sockToSendAddrSize = sizeof(sockToSendAddr);
	sockToSend=accept(sock, (struct sockaddr*)&sockToSendAddr,(socklen_t*)&sockToSendAddrSize);
}

void nSocket::errorHandling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

char* nSocket::convertStringToChar(const string &str) {

    char *retPtr(new char[str.length() + 1]);

    copy(str.begin(), str.end(), retPtr);
    retPtr[str.length()] = '\0';;
 
    return retPtr;
}

int nSocket::atoi(char *str) {
	int tot=0;
	while(*str) {
		tot = tot*10 + *str - '0';
		str++;
	}
	return tot;
}
