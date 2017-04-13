#ifndef COMMAND_CONTRPLL_H
#define COMMAND_CONTRPLL_H

#include <stdio.h>
#include <direct.h>
#include "packetData.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class commandControl{

private:
	vector<packetData> vPacketData;
public:
	vector<packetData> getVPacketData();
	void addVPacketData(packetData packetInfo);
	packetData removeVPacketData();
	void addSSHTunnel(packetData packetInfo);
	void removeSSHTunnel(packetData packetInfo, string port);
	string findProc(string port);
	void killProc(string pid);
	void saveStatusToFile();
	void readStatusFromFile();
	void operateALLSSHCommand();
	void removeALLSSHCommand();
	char* convertStringToChar(const string &str);
};
#endif
