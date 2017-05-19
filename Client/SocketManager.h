#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include "Packet.h"
#include "nSocket.h"
#define tempServIP 10.30.118.92
#define tempServPort 9000

using namespace std;

class SocketManager {

private:
	
	Packet packet;

	string servIP;
	string servPort;
	vector<nSocket> vNSocket;
	vector<pthread_t> vThread;
	void* thread_result;

public:

	SocketManager();
	SocketManager(Packet packet);

	void setServIP(string servIP);
	void setServPort(string servPort);

	string getServIP();
	string getServPort();

	void setPacket(Packet packet);
	Packet getPacket();

	vector<nSocket> getVNSocket();
	vector<pthread_t> getVThread();

	void setNSocket(nSocket nSock);
	void setThread(pthread_t thread);
	nSocket getNSocket(long unsigned int index);
	pthread_t getThread(long unsigned int index);

	void* execThread(pthread_t thread, void* function, void* sock);
	void stopThread(pthread_t thread);	

	//void* sendHeaderMessage(void* sock);
	//void* sendBodyMessage(void* sock);
	void* sendLogoutMessage(void* sock);
	void* sendMessage1(void* sock);
	void* sendMessage2(void* sock);
	//void* recvMessage(void* sock);
	void* sendLoginMessage(void* sock);
	void* sendMessageToUI2(void* sock);
	void* recvMessageFromUI(void* sock);
	void* recvMessageFromServ(void* sock);
	void errorHandling(char* message);
	char* convertStringToChar(const string &str);
	void itoa(int num, char *str);
	int connSock(nSocket sock, string IP, string port);
	
	void* login();
	void logout();
	void noti(void* sock);
	void* checkNOTI(void *sock);
	
	//void sendUserIDToCommandProc(void* sock);
	void managerStart();
	void divideUIInfo(string UIInfo);
	void divideServInfo(string servInfo);
};
