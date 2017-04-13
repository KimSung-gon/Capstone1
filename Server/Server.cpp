#include "Server.h"

void Server::setSock(void* sock) {
	this->sock = (int)sock;
}

void Server::setCmdControl(commandControl cmdControl) {
	this->cmdControl = cmdControl;
}

void Server::setUserID(string userID) {
	this->userID = userID;
}

void Server::setForwardIPAndPort(string forwardIPAndPort) {
	this->forwardIPAndPort = forwardIPAndPort;
}

void Server::setFile(FILE* infile) {
	this->infile = infile;
}

int Server::getSock() {
	return this->sock;
}

commandControl Server::getCmdControl() {
	return this->cmdControl;
}

string Server::getUserID() {
	return this->userID;
}

string Server::getForwardIPAndPort() {
	return this->forwardIPAndPort;
}

FILE* Server::getFile() {
	return this->infile;
}

FILE* Server::findUserFile(string userID) {
	
}

void Server::interaction() {
	sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family=AF_INET;
	sockAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	sockAddr.sin_port=htons(9999);
	if(bind(sock, (struct sockaddr*) &sockAddr, sizeof(sockAddr)) == -1)
		errorHandling("bind() error");
	if(listen(sockAddr, 5) == -1)
		errorHandling("listen() error");
}

void Server::startThread(void function) {
	this->interaction();
	int clntAddrSize = sizeof(clntAddr);
	while(clntSock == 0){
		clntSock=accept(servSock, (struct sockaddr*)&clntAddr, &clntAddrSize);
	}
	// find userFile by use id, and upload data to vPacketData
	pthread_create(&thread, NULL, function, (void*)clntSock);
}

void* Server::function() {
	int strLen = 0;
	char message[30];

	while( (strLen=read(clntSock, message, sizeof(message))) != 0) {
		write(clntSock, message, strLen);
		packetData pData;
		pData.setPacketInfo(message);
		cmdControl.addPacketData(pData);
		this->cmdControl.addSSHTunnel();
	}
}

void Server::errorHandling(char *message) {
	fputs(message, stderr);
	fputs('\n', stderr);
	exit(1);
}
