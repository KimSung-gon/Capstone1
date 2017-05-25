#include "SocketManager.h"

SocketManager::SocketManager() {}

SocketManager::SocketManager(Packet packet) {
	this->packet = packet;
}

void SocketManager::setServerIP(string serverIP) {
	this->serverIP = serverIP;
}

void SocketManager::setServerPort(string serverPort) {
	this->serverPort = serverPort;
}

string SocketManager::getServerIP() {
	return serverIP;
}

string SocketManager::getServerPort() {
	return serverPort;
}

void SocketManager::setPacket(Packet packet) {
	this->packet = packet;
}

Packet SocketManager::getPacket() {
	return this->packet;
}

vector<Packet> SocketManager::getVPacket() {
	return this->vPacket;
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

//void* SocketManager::execThread(pthread_t thread, void* function, void* sock) {
//	pthread_create(&thread, NULL, function, sock);
//}

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
}*/
/*
void* SocketManager::sendBodyMessage(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[packet.getBodyInfo().length()+1];
	strcpy(message, packet.getBody().getBodyInfo().c_str());
	message[packet.getBodyInfo().length()] = NULL;
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}*/

void* SocketManager::sendMessage1(void* sock) {
	int sockTemp = (intptr_t)sock;
	string delim = "{$}";
	string temp1 = delim + packet.getLoginSuccess();
	char message[temp1.length()+1];
	//strcpy(message, getVPacket.back().c_str());
	//message[packet.getPacketInfo1().length()] = NULL;
	strcpy(message, temp1.c_str());
	message[temp1.length()] = NULL;
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}

void* SocketManager::sendMessage2(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[getPacket().getPacketInfo2().length()+1];
	//strcpy(message, getVPacket.back().c_str());
	//message[packet.getPacketInfo2().length()] = NULL;
	strcpy(message, getPacket().getPacketInfo2().c_str());
	message[getPacket().getPacketInfo2().length()] = NULL;
	cout << message << endl;
	write(sockTemp, message, strlen(message)+1);
}
/*
void* SocketManager::recvMessageFromUI(void* sock) {
	int sockTemp = (intptr_t)sock;
  	char message[120];
    int str_len;
	str_len = read(sockTemp, message, 120);
 	if(str_len==-1) {
		cout << "read fail" << endl;
		return (void*)1;
	}
    message[str_len]=0;
	divideUIInfo(message);
}
*/
void* SocketManager::recvMessageFromClient1(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[500];
	int str_len;
   	str_len = read(sockTemp, message, 500);
	if(str_len==-1) {
		cout << "recvMessageFromServ fail" << endl;
		return (void*)1;
   	}
	message[str_len]=0;
	divideClientInfo1(message);
	cout << message << endl;
}

void* SocketManager::recvMessageFromClient2(void* sock) {
	int sockTemp = (intptr_t)sock;
	char message[500];
	int str_len;
   	str_len = read(sockTemp, message, 500);
	if(str_len==-1) {
		cout << "recvMessageFromServ fail" << endl;
		return (void*)1;
   	}
	message[str_len]=0;
	divideClientInfo2(message);
	cout << message << endl;
}

void* SocketManager::recvMessageLogOut(void* sock) {
	/*
	int sockTemp = (intptr_t)sock;
	char message[20];
	int str_len;
   	str_len = read(sockTemp, message, 500);
	if(str_len==-1) {
		cout << "recvMessageFromServ fail" << endl;
		return (void*)1;
   	}
	message[str_len]=0;
	*/
	getPacket().setLoginSuccess("false");
}

void SocketManager::errorHandling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

char* SocketManager::convertStringToChar(const string &str) {
	
	char *retPtr(new char[str.length() + 1]);
	
	copy(str.begin(), str.end(), retPtr);
	retPtr[str.length()] = '\0';

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

int SocketManager::atoi(char *str) {
	int tot=0;
	while(*str) {
		tot = tot*10 + *str - '0';
		str++;
	}
	return tot;
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
/*
void* SocketManager::login() {

	nSocket sock;
	sock.setSock(this->connSock(sock, serverIP, serverPort));
	packet.login();
	packet.getBody().getVDataField().at(3).setData(loginID);
	packet.getBody().getVDataField().at(4).setData(password);
	this->vNSocket.push_back(sock);
	
	sendHeaderMessage((void*)sock.getSock());
	sendBodyMessage((void*)sock.getSock());
	cout << "before recv" << endl;
	recvMessageFromServ((void*)sock.getSock());	
	cout << "login()" << endl;
	return sock.getSock();	
}

void SocketManager::cachedDataChangedNOTI() {
	
}

void SocketManager::userLiveCheck() {

}

void SocketManager::maxDBListChangeNOTI(void* sock) {
	int sockTemp = (intptr_t)sock;
	pthread_t thread;
	pthread_create(sockTemp, NULL, checkNOTI, (void*)sock);
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

void SocketManager::sendUserIDToCommandProc(void* sock) {
	string userLoginID = this->packet.getBody().getLoginID();	
	// id send to command proc
}
*/
void SocketManager::managerStart() {

	string open9000 = "echo 12342323 | sudo -S iptables -I INPUT 1 -p tcp --dport 9000 -j ACCEPT";
	char *pStr = convertStringToChar(open9000);
	system(pStr);
	string open22 = "echo 12342323 | sudo -S iptables -I INPUT 1 -p tcp --dport 22 -j ACCEPT";
	pStr = convertStringToChar(open22);
	system(pStr);
	
	// read ip, mac list to client list
	nSocket sock;
	vNSocket.push_back(sock);
	string port = "9000";
	sock.initSock();
	sock.initSockAddrSelf(port);
	sock.acceptSock(sock.getSock(), sock.getSockAddr());
// multi client
	recvMessageFromClient1((void*)sock.getSockToSend());
	vector<Registered> vUserList;
	ifstream infile("checkUserInfo.txt");
	if(infile.fail()) 
		getPacket().setLoginSuccess("false");
	else
		getPacket().setLoginSuccess("true");
	char inputString[100];
	while(infile.eof()) {
		Registered temp;
		infile.getline(inputString, 100);
		temp.setID(inputString);
		infile.getline(inputString, 100);
		temp.setPasswd(inputString);
		infile.getline(inputString, 100);
		temp.setIP(inputString);
		infile.getline(inputString, 100);
		temp.setMAC(inputString);
		vUserList.push_back(temp);
	}
	infile.close();
	cout << "3" << endl;	
	//for ID Passwd check
	packet.setLoginSuccess("true");
	packet.makeAck();
	packet.makeSyn();
	packet.makeCompAck();
	cout << "3.5" << endl;
	packet.addString1();
	int temp = 0;
	//for(int i=0; i<vUserList.size(); i++) { IP MAC check
	// check IP MAC ETC
	// file encryption()
	//for(vector<Packet>::iterator IterPos = getVPacket().begin(); IterPos != getVPacket().end(); ++IterPos) {
		// check if packet is in client list
	//}
	// execute command and delete history(atomic) 
		
	//getVPacket().back().makeSyn();
	// 1. check ID, Password
	cout << "4" << endl;
	sendMessage1((void*)sock.getSockToSend());	
//	if((getVPacket.pop_back().checkAck() == "true") && (getVPacket.pop_back().getLoginSuccess() == "true")) {
//		getVPacket().back().setLoginSuccess("true");		
//	}
//	else {
//		getVPacket().back().setLoginSuccess("false");
//	}
	//recvMessageFromClient2((void*)sock.getSockToSend());
// check IP MAC
	//sendMessage2((void*)sock.getSock());
	cout << "7" << endl;
	string decrypt = "sshpass -p " + getPacket().getUserRootPasswd() + " ssh root@" + getPacket().getUserLocalIP() + " sh < decrypt.sh";
	pStr = convertStringToChar(decrypt);	
	system(pStr);
//  control file move copy disable
	recvMessageLogOut((void*)sock.getSock());
	string encrypt = "sshpass -p " + getPacket().getUserRootPasswd() + " ssh root@" + getPacket().getUserLocalIP() + " sh < encrypt.sh";
//	control file move copy enable
	pStr = convertStringToChar(encrypt);
	system(pStr);

	close(sock.getSock());	
//	nSocket sockClient;
//	sock1.setSock((intptr_t)login());
}

void SocketManager::divideClientInfo1(string clientInfo) {
	Packet packet;
	char message[120];
	char messagePiece[50];
	string temp = clientInfo;
	char* pStr = convertStringToChar(temp);
	
	char tempPStr[120];
	strcpy(tempPStr, pStr);
	char* delim = "{$}";
	char* token;
	int indexOfMessage = 0;
	token = strtok(tempPStr, delim);
	strcpy(messagePiece, token);
	messagePiece[49] = NULL;
	getPacket().setUserID(messagePiece);
	int count = 0;
	while( token = strtok(NULL, "{$}") ) {
		memset(messagePiece, NULL, sizeof(messagePiece));
		strcpy(messagePiece, token);
		messagePiece[49] = NULL;
		
		if(count == 0)
			this->packet.setUserPasswd(messagePiece);
		else if(count == 1)
			this->packet.setUserRootPasswd(messagePiece);
		else if(count == 2)
			this->packet.setUserLocalIP(messagePiece);
		else if(count == 3)
			this->packet.setUserMAC(messagePiece);
		else if(count == 4) 
			this->packet.setSyn(atoi(messagePiece));
		else if(count == 5) 
			this->packet.setAck(atoi(messagePiece));
		count++;
	}
	
	getVPacket().push_back(packet);
}

void SocketManager::divideClientInfo2(string clientInfo) {
	char message[120];
	char messagePiece[50];
	string temp = clientInfo;
	char* pStr = convertStringToChar(temp);
	
	char tempPStr[120];
	strcpy(tempPStr, pStr);
	char* delim = "{$}";
	char* token;
	int indexOfMessage = 0;
	token = strtok(tempPStr, delim);
	strcpy(messagePiece, token);
	messagePiece[49] = NULL;
	setServerIP(messagePiece);
	int count = 0;
	while( token = strtok(NULL, "{$}") ) {
		memset(messagePiece, NULL, sizeof(messagePiece));
		strcpy(messagePiece, token);
		messagePiece[49] = NULL;
	
		if(count == 0)
			getPacket().setUserGlobalIP(messagePiece);
		else if(count == 1)
			getPacket().setUserLocalIP(messagePiece);
		else if(count == 2)
			getPacket().setUserMAC(messagePiece);
		else if(count == 3) 
			getPacket().setSyn(atoi(messagePiece));
		else if(count == 4) 
			getPacket().setAck(atoi(messagePiece));
		
		count++;
	}
}
