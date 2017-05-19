#include "SocketManager.h"

SocketManager::SocketManager() {}

SocketManager::SocketManager(Packet packet) {
	this->packet = packet;
}

void SocketManager::setServIP(string servIP) {
	this->servIP = servIP;
}

void SocketManager::setServPort(string servPort) {
	this->servPort = servPort;
}

string SocketManager::getServIP() {
	return servIP;
}

string SocketManager::getServPort() {
	return servPort;
}

void SocketManager::setPacket(Packet packet) {
	this->packet = packet;
}

Packet SocketManager::getPacket() {
	return this->packet;
}

vector<nSocket> SocketManager::getVNSocket() {
	return this->vNSocket;
}
 
vector<pthread_t> SocketManager::getVThread() {
	return this->vThread;
}
 
void SocketManager::setNSocket(nSocket nSock) {
	this->vNSocket.push_back(nSock);
}

void SocketManager::setThread(pthread_t thread) {
	this->vThread.push_back(thread);
}

nSocket SocketManager::getNSocket(long unsigned int indexOfMessage) {
	return this->vNSocket.at(indexOfMessage);
}

pthread_t SocketManager::getThread(long unsigned int indexOfMessage) {
	return this->vThread.at(indexOfMessage);
}

void* SocketManager::execThread(pthread_t thread, void* function, void* sock) {
	pthread_create(&thread, NULL, function, sock);
}

void SocketManager::stopThread(pthread_t thread) {
	pthread_join(thread, &thread_result);
}
/*
void* SocketManager::sendHeaderMessage(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[53];
	char messagePiece[10];
	string temp = packet.getHeader().getHeaderInfo();
	char* pStr = convertStringToChar(temp);
	
	char tempPStr[100];
	strcpy(tempPStr, pStr);
	char* delim = "{$}";
	char* token;
	int indexOfMessage = 0;
	token = strtok(tempPStr, delim);
	strcpy(messagePiece, token);
	messagePiece[9] = NULL;

	int numOfNULL = 0;
	for(int i=0; i<10; i++)
		if(messagePiece[i] == NULL)
			numOfNULL++;
	
	for(int i=0; i<numOfNULL; i++) {
		message[indexOfMessage] = 32;
		indexOfMessage++;
	}
	for(int i=0; i<10-numOfNULL; i++) {
		message[indexOfMessage] = messagePiece[i];
		indexOfMessage++;
	}
	
	while( token = strtok(NULL, "{$}") ) {
		memset(messagePiece, NULL, sizeof(messagePiece));
		strcpy(messagePiece, token);
		messagePiece[9] = NULL;
		numOfNULL = 0;
		for(int i=0; i<10; i++)
			if(messagePiece[i] == NULL)
				numOfNULL++;
		for(int i=0; i<numOfNULL; i++) {
			message[indexOfMessage] = 32;
			indexOfMessage++;
		}
		for(int i=0; i<10-numOfNULL; i++) {
			message[indexOfMessage] = messagePiece[i];
			indexOfMessage++;
		}
	}
	message[50] = '{';
	message[51] = '$';
	message[52] = '}';
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendBodyMessage(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[packet.getBodyInfo().length()+1];
	strcpy(message, packet.getBody().getBodyInfo().c_str());
	message[packet.getBodyInfo().length()] = NULL;
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}*/

void* SocketManager::sendLogoutMessage(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[50];
	strcpy(message, getPacket().getLoginSuccess().c_str());
	message[getPacket().getPacketInfo1().length()] = NULL;	
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendMessage1(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[50];
	strcpy(message, getPacket().getPacketInfo1().c_str());
	message[getPacket().getPacketInfo1().length()] = NULL;	
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendMessage2(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[50];
	strcpy(message, getPacket().getPacketInfo2().c_str());
	message[getPacket().getPacketInfo2().length()] = NULL;	
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendLoginMessage(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[50];
	strcpy(message, getPacket().getLoginSuccess().c_str());
	message[getPacket().getLoginSuccess().length()] = NULL;	
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendMessageToUI2(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[50];
	strcpy(message, getPacket().getPacketInfo2().c_str());
	message[getPacket().getPacketInfo2().length()] = NULL;	
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::recvMessageFromUI(void* sock) {
	int sockTemp = (intptr_t)sock;
  	char message[50];
    int str_len;
	str_len = read(sockTemp, message, 50);
 	if(str_len==-1) {
		cout << "read fail" << endl;
		return (void*)1;
	}
    message[str_len]=0;
	divideUIInfo(message);
	
	cout << message << endl;
}

void* SocketManager::recvMessageFromServ(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[500];
	int str_len;
	cout << "before read" << endl;
   	str_len = read(sockTemp, message, 500);
	cout << "after read" << endl;
	if(str_len==-1) {
		cout << "recvMessageFromServ fail" << endl;
		return (void*)1;
   	}
	message[str_len]=0;
	//packet.setPacketInfo(message);
	divideServInfo(message);	
	cout << message << endl;
}

void SocketManager::errorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

char* SocketManager::convertStringToChar(const string &str) {
	
	char *retPtr(new char[str.length() + 1]);
	
	copy(str.begin(), str.end(), retPtr);
	retPtr[str.length()] = '\0';;

	return retPtr;
}

void SocketManager::itoa(int num, char* str) {
	int i = 0;
    int radix = 10;
    int deg = 1;
    int cnt = 0;

    while(1) {
        if( (num/deg) > 0)
            cnt++;
        else
            break;

        deg *= radix;
    }

    deg /= radix;

    for(i=0; i<cnt; i++) {
        *(str+i) = num/deg + '0';
        num -= ((num/deg) * deg);
        deg /= radix;
    }
    *(str+i) = '\0';
}

int SocketManager::connSock(nSocket sock, string IP, string port) {
	sock.initSock();
	sock.initSockAddr(IP, port);
	sock.connectSock(sock.getSock(), sock.getSockAddr());
	return sock.getSock();
}
/*
void connectToCommandProc() {
	nSocket sock;
	sock.setSock(this->connSock(sock, commandProcIP, commandProcPort));
	this->vNSocket.push_back(sock);
}

void commandProcLogin() {
	this->connectToCommandProc();
	//recv
	this.getPacket().getHeader().setUserID();
}
*/
void* commandProcFunction() {

}

void recvUserInfoFromUI() {

}

void* SocketManager::login() {

	nSocket sock;
	sock.setSock(this->connSock(sock, servIP, servPort));
	this->vNSocket.push_back(sock);
	
	cout << "before recv" << endl;
	recvMessageFromServ((void*)sock.getSock());	
	sendMessage((void*)sock.getSock()); //1차
	sendMessage((void*)sock.getSock()); //2차
	cout << "login()" << endl;
	return sock.getSock();	
}

void SocketManager::noti(void* sock) {
	int sockTemp = (intptr_t)sock;
	pthread_t thread;
	pthread_create(sockTemp, NULL, checkNOTI(sock), (void*)sock);
}

void* SocketManager::checkNOTI(void *sock) {
	int sockTemp = (intptr_t)sock;
	char message[300];
	int strLen;
	while(1) {
		strLen = read(sock, message, 300);
		if(strLen==-1) {
			cout << "read NOTI fail" << endl;
			return (void*)1;
		}
	}
}

void SocketManager::managerStart() {
	nSocket sock;
	vNSocket.push_back(sock);
	string port = "9000";
	sock.initSock();
	sock.initSockAddrSelf(port);
	sock.acceptSock(sock.getSock(), sock.getSockAddr());
	recvMessageFromUI((void*)sock.getSockToSend());
	string commandForFirewall = "echo " + getPacket().getUserRootPasswd() + " | sudo -S iptables -I INPUT 1 -p tcp --dport 22 -j ACCEPT";		
	system(commandForFirewall);
	
	srand((unsigned)time(NULL));
	string userRootTempPasswd = itoa(rand());
	getPacket().getUserRootTempPasswd(userRootTempPasswd);
	string changePasswd = "echo \"root:" + getPacket().getUserRootTempPasswd() + "\" | sudo -S chpasswd << " + getPacket().getUserRootPasswd();  		
	system(changePasswd);	
	nSocket servSock;
	sock.setSock(this->connSock(servSock, servIP, servPort));
	
	packet.makeSyn();
	packet.addString1();
	sendMessage1((void*)servSock.getSock());	

	getPacket().makeCompAck();	
	recvMessageFromServ((void*)servSock.getSock());	
	if((getPacket().checkAck() == "true") && (getPacket().getLoginSuccess() == "true")) {}
	else {
		sendLoginMessage((void*)sock.getSock());	
		return;
	}
	packet.makeAck();

	packet.findGlobalIP();
//	packet.findLocalIP();
	packet.findMAC();

	packet.addString2();	
	sendMessage2((void*)servSock.getSock());

	getPacket().makeCompAck();	
	recvMessageFromServ((void*)servSock.getSock());
	if((getPacket().checkAck() == "true") && (getPacket().getLoginSuccess() == "true")) {
		sendMessage2((void*)servSock.getSock());
	}
	else {
		sendLoginMessage((void*)sock.getSock());
		close(sock.getSock());
		close(servSock.getSock());	
		return;
	}
	sendMessageToUI2((void*)sock.getSock());
	
	if(getPacket().getLoginSuccess() == true) {
		sendLoginMessage((void*)sock);
		sendLoginMessage((void*)servSock);
	}
	else {
		close(sock.getSock());
		close(servSock.getSock()); 
		return;
	}

// 9 11 14 make 
	recvMessageFromUI((void*)sock.getSockToSend());
	if(getPacket().getLoginSuccess() == false) {
		sendLogoutMessage((void*)servSock.getSock());
		getPacket().getUserRootTempPasswd(userRootTempPasswd);
		changePasswd = "echo \"root:" + getPacket().getUserRootPasswd() + "\" | sudo -S chpasswd << " + getPacket().getUserRootTempPasswd();  		
		system(changePasswd);
	}
	close(sock.getSock());

}

void SocketManager::divideUIInfo(string UIInfo) {
	char message[50];
	char messagePiece[20];
	string temp = UIInfo;
	char* pStr = convertStringToChar(temp);
	
	char tempPStr[50];
	strcpy(tempPStr, pStr);
	char* delim = "{$}";
	char* token;
	int indexOfMessage = 0;
	token = strtok(tempPStr, delim);
	strcpy(messagePiece, token);
	messagePiece[19] = NULL;
	//packet.setUserID(messagePiece);
	int count = 0;
	while( token = strtok(NULL, "{$}") ) {
		memset(messagePiece, NULL, sizeof(messagePiece));
		strcpy(messagePiece, token);
		messagePiece[19] = NULL;
		
		if(count == 0)
			getPacket().setUserID(messagePiece);
		else if(count == 1)
			getPacket().setUserPasswd(messagePiece);
		else if(count == 2)
			getPacket().setUserRootPasswd(messagePiece);
		else if(count == 3)
			getPacket().setLoginSuccess(messagePiece);
		
		count++;
	}
}

void SocketManager::divideServInfo(string servInfo) {
	char message[50];
	char messagePiece[20];
	string temp = UIInfo;
	char* pStr = convertStringToChar(temp);
	
	char tempPStr[50];
	strcpy(tempPStr, pStr);
	char* delim = "{$}";
	char* token;
	int indexOfMessage = 0;
	token = strtok(tempPStr, delim);
	strcpy(messagePiece, token);
	messagePiece[19] = NULL;
	packet.setUserID(messagePiece);
	int count = 0;
	while( token = strtok(NULL, "{$}") ) {
		memset(messagePiece, NULL, sizeof(messagePiece));
		strcpy(messagePiece, token);
		messagePiece[19] = NULL;
		
		if(count == 0)
			getPacket().setSyn(messagePiece);
		else if(count == 1)
			getPacket().setAck(messagePiece);
		else if(count == 2)
			getPacket().setLoginSuccess(messagePiece);
		
		count++;
	}
}
