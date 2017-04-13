#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "commandControl.h"

using namespace std;

class Server {

pritvate:

	int servSock;
	int clntSock;
	struct sockaddr_in sockAddr;
	struct sockaddr_in sockAddr;
	commandControl cmdControl;
	vector<user> userList;	
	FILE* infile;

public:

	void setSock(void* sock);
	void setCommandProc(commandProc cmdControl);
	void setUserID(string userID);
	void setFile(FILE* infile);

	int getSock();
	commandProc getCmdControl();
	
	FILE* getFile();

	FILE* findUserFile(string userID);
		
	void interaction();
	void startThread(void function);
	void* function();
	void sendMessage(char* message, int strLen);
	void errorHandling(char* message);
};
#endif	
