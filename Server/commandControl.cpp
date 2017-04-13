#include "commandControl.h"

vector<packetData> getVPacketData(){ 
	return this->vPacketData;
}

void commandControl::addVPacketData(packetData packetContent){
	vPacketData.push_back(packetContent);
}
	
packetData commandControl::removeVPacketData(){
	vPacketData.pop_back();
}

void commandControl::addSSHTunnel(packetData packetContent) {

	string command = "sshpass -p chakra20 ssh -N -f -L ";
	string temp;
	
	temp = packetContent.getLocalPort();
	command.append(command, temp);
	temp = ":";
	command.append(command, temp);
	temp = packetContent.getForwardIP();
	command.append(command, temp);
	temp = ":";
	command.append(command, temp);
	temp = packetContent.getForwardPort();
	command.append(command, temp);
	temp = " ";
	command.append(command, temp);
	temp = packetContent.getRemoteUserName();
	command.append(command, temp);
	temp = "@";
	command.append(command, temp);
	temp = packetContent.getRemoteIP();

	char *pStr(convertStringToChar(command));

	system(pStr);
}
	
void commandControl::removeSSHTunnel(packetData packetContent, string port){

	string pid = findProc(port);
	killProc(pid);
}

string commandControl::findProc(string port){

	string command = "ps -ef | grep ssh > procList.txt";
	char *pStr(convertStringToChar(command));
	system(pStr);

	ifstream infile("procList.txt");
	string line;
	string pid;

	for each(packetData i in this->vPacketData){
		
		getline(infile, line);

		char *pStr(convertStringToChar(line));
		if(line.find(port) != NULL) {
			strtok(pStr, " ");
			pid = pStr;
			break;
		}
	}
	return pid;
}

void commandControl::killProc(string pid){

	string command = "sudo kill -9 ";
	command.append(command, pid);
	char *pStr(convertStringToChar(command));
	system(pStr);
}

void commandControl::saveStatusToFile(){

	ofstream outFile("packetList.txt");
	if(outFile.fail()) {
		cout << "saveStatusToFile fail" << endl;
		return;
	}	

	string line = "";
	string temp = "\n";
	for each(packetData i in vPacketData){
		line.append(line, i.getPacketContent());
	}

	char *pStr(convertStringToChar(line));
	outFile << line;
}

void commandControl::readStatusFromFile(){

	ifstream infile("packetList.txt");
	if(infile.fail()) {
		cout << "readStatusFromFile fail" << endl;
		return;
	}

	string line;
	while(!infile.eof()){
		getline(infile, line);
		packetData newPacket(line);
		this->vPacketData.push_back(newPacket);
	}
}

void commandControl::operateALLSSHCommand(){
	
	for each(packetData i in this->vPacketData){
		addSSHTunnel(i);
	}
}

void commandControl::removeALLSSHCommand(){

	string command = "sudo killall -9 ssh";
	
	char *pStr(convertStringToChar(command));

	system(pStr);
}

char* commandControl::convertStringToChar(const string &str) {
    char *retPtr(new char[str.length() + 1]);
 
    copy(str.begin(), str.end(), retPtr);
    retPtr[str.length()] = '\0';
   
    return retPtr;
}
