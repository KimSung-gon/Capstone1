#ifndef PACKET_H
#define PACKET_H

#include <cstdlib>
#include <vector>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ifaddrs.h>
#include <netpacket/packet.h>

using namespace std;

class Packet {

private:
	string command;
	string userID;
	string userPasswd;
	string userRootPasswd;
	string userRootTempPasswd;
	string userGlobalIP;
	string userLocalIP;
	string userMAC;
	string dataLength;
	string packetInfo1;
	string packetInfo2;
	int syn;
	int ack;
	int compAck;
	string loginSuccess;	

public:
	void setCommand(string command);
	void setUserID(string userID);
	void setUserPasswd(string userPasswd);
	void setUserRootPasswd(string userRootPasswd);
	void setUserRootTempPasswd(string userRootTempPasswd);
	void setUserGlobalIP(string userGlobalIP);
//	void setUserLocalIP(string userLocalIP);
	void setUserMAC(string userMAC);
	void setPacketInfo1(string packetInfo1);
	void setPacketInfo2(string packetInfo2);
	void setSyn(int syn);
	void setAck(int ack);
	void setLoginSuccess(string loginSuccess);
	void setCompAck(int compAck);

	string getCommand();
	string getUserID();
	string getUserPasswd();
	string getUserRootPasswd();
	string getUserRootTempPasswd();
	string getUserGlobalIP();
	string getUserLocalIP();
	string getUserMAC();
	string getDataLength();
	string getPacketInfo1();
	string getPacketInfo2();
	int getSyn();
	int getAck();
	string getLoginSuccess();
	int getCompAck();
	
	void login();
	void logout();
	void checkNOTI();
	void addString1();
	void addString2();

	void findGlobalIP();
//	void findLocalIP();
	void findMAC();	
	void makeSyn();
	void makeAck();
	void makeCompAck();	
	string checkAck();

	char* convertStringToChar(const string &str);
	string convertDecStringToHexString(const string decString);	
	void itoa(int num, char *str);
	int atoi(char *str);
	string systemCommand(string sysCommand);
};

#endif
