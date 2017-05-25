#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <inttypes.h>
#include <fstream>
#include "Packet.h"
#include "nSocket.h"
#define tempServIP 10.30.14.64
#define tempServPort 9000

using namespace std;

class SocketManager {

private:
	
	Packet packet;

	string servIP;
	string servPort;
	vector<nSocket> vNSocket;
	vector<pthread_t> vThread;
	vector<string> vFile;
	void* thread_result;
	string fullSecondPacket;
	string tempSecondPacket;
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
	vector<string> getVFile();
	void setNSocket(nSocket nSock);
	void setThread(pthread_t thread);
	nSocket getNSocket(long unsigned int index);
	pthread_t getThread(long unsigned int index);

	void setFullSecondPacket(string fullSecondPacket);
	string getFullSecondPacket();	

	void setTempSecondPacket(string tempSecondPacket);
	string getTempSecondPacket();

	void* execThread(pthread_t thread, void* function, void* sock);
	void stopThread(pthread_t thread);	

	//void* sendHeaderMessage(void* sock);
	//void* sendBodyMessage(void* sock);
	void* sendLogoutMessage(void* sock);
	void* sendMessage1(void* sock);
	void* sendMessage2(void* sock);
	void* sendMessage3(void* sock);
	//void* recvMessage(void* sock);
	void* sendLoginMessage(void* sock);
	void* sendMessageToUI2(void* sock);
	void* recvMessageLogOut(void* sock);
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
	void addString3();
};
