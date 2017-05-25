#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <inttypes.h>
#include "Packet.h"
#include "nSocket.h"
#include "Registered.h"

using namespace std;

class SocketManager {

private:
	
	Packet packet;

	string loginID;
	string password;
	string serverIP;
	string serverPort;
	vector<Packet> vPacket;
	vector<nSocket> vNSocket;
	vector<pthread_t> vThread;
	void* thread_result;

	int loginSuccess;

public:

	SocketManager();
	SocketManager(Packet packet);

	void setServerIP(string serverIP);
	void setServerPort(string serverPort);

	string getServerIP();
	string getServerPort();

	void setPacket(Packet packet);
	Packet getPacket();

	vector<Packet> getVPacket();
	vector<nSocket> getVNSocket();
	vector<pthread_t> getVThread();

	void setNSocket(nSocket nSock);
	void setThread(pthread_t thread);
	nSocket getNSocket(long unsigned int index);
	pthread_t getThread(long unsigned int index);

	//void* execThread(pthread_t thread, void* function, void* sock);
	void stopThread(pthread_t thread);	

	//void* sendHeaderMessage(void* sock);
	//void* sendBodyMessage(void* sock);

	void* sendMessage1(void* sock);
	void* sendMessage2(void* sock);
	void* recvMessage(void* sock);
	void* recvMessageFromClient1(void* sock);
	void* recvMessageFromClient2(void* sock);
	void* recvMessageLogOut(void* sock);
	void * recvMessageFromServ(void* sock);
	void errorHandling(char* message);
	char* convertStringToChar(const string &str);
	void itoa(int num, char *str);
	int atoi(char *str);
	int connSock(nSocket sock, string IP, string port);
	
	//void login();
	//void logout();
	//void cachedDataChangedNOTI();
	//void userLiveCheck();
	//void maxDBListChangeNOTI();
	
	void sendUserIDToCommandProc(void* sock);
	void managerStart();
	void divideClientInfo1(string clientInfo);
	void divideClientInfo2(string clientInfo);
};
