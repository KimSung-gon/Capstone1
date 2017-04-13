#ifndef PACKET_H
#define PACKET_H

#include "StringTokenizer.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <ifaddrs.h>
#include <netpacket/packet.h>

using namespace std;

class Packet {

private:
	string command;
	string userID;
	string userPasswd;
	string userIP;
	string userMAC;
	string dataLength;
	string packetInfo;

public:
	void setCommand(string command);
	void setUserID(string userID);
	void setUserPasswd(string userPasswd);
	void setUserIP(string userIP);
	void setUserMAC(string userMAC);
	void setPacketInfo(string packetInfo);

	string getCommand();
	string getUserID();
	string getUserPasswd();
	string getUserIP();
	string getUserMAC();
	string getDataLength();
	string getPacketInfo();
	
	void login();
	void logout();
	void checkNOTI();
	void addString();

	void findIP();
	void findMAC();	

	char* convertStringToChar(const string &str);
	string convertDecStringToHexString(const string decString);	
	void itoa(int num, char *str);
	string systemCommand(string sysCommand);
};

#endif
