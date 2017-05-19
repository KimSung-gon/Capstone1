include "Packet.h"

void Packet::setCommand(string command) {
    this->command = command;
}

void Packet::setUserID(string userID) {
    this->userID = userID;
}

void Packet::setUserPasswd(string userPasswd) {
    this->userPasswd = userPasswd;
}

void Packet::setUserRootPasswd(string userRootPasswd) {
	this->userRootPasswd = userRootPasswd;
}
 
void Packet::setUserRootTempPasswd(string userRootTempPasswd) {
	this->userRootPasswd = userRootTempPasswd;
}

void Packet::setUserGlobalIP(string userGlobalIP) {
    this->userGlobalIP = userGlobalIP;
}
/*
void Packet::setUserLocalIP(string userLocalIP) {
	this->userLocalIP = userLocalIP;
}
*/
void Packet::setUserMAC(string userMAC) {
    this->userMAC = userMAC;
}

void Packet::setSyn(int syn) {
	this->syn = syn;
}

void Packet::setAck(int ack) {
	this->ack = ack;
}

string Packet::setLoginSuccess(string loginSuccess) {
	this->loginSuccess = loginSuccess;
}

string Packet::getCommand() {
    return command;
}

string Packet::getUserID() {
    return userID;
}

string Packet::getUserPasswd() {
    return userPasswd;
}

string Packet::getUserRootPasswd() {
    return userRootPasswd;
}

string Packet::getUserRootTempPasswd() {
    return userRootTempPasswd;
}

string Packet::getUserGlobalIP() {
    return userGlobalIP;
}
/*
string Packet::getUserLocalIP() {
	return userLocalIP;
}
*/
string Packet::getUserMAC() {
    return userMAC;
}

string Packet::getDataLength() {
    return dataLength;
}

string Packet::getPacketInfo1() {
    return packetInfo1;
}

string Packet::getPacketInfo2() {
    return packetInfo2;
}

int Packet::getSyn() {
	return syn;
}

int Packet::getAck() {
	return ack;
}

string Packet::getLoginSuccess() {
	return loginSuccess;
}

void Packet::addString1() {

    packetInfo1 = "";
    packetInfo1 = packetInfo1.append(this->getCommand() 
		+ "{$}" + this->getUserID() 
		+ "{$}" + this->getUserPasswd() 
		+ "{$}" + this->getUserRootTempPasswd() 
		+ "{$}" + this->getSyn()
		+ "{$}" + this->getAck()
		);
}

void Packet::addString2() {

    packetInfo2 = "";
    packetInfo2 = packetInfo2.append(this->getCommand() 
		+ "{$}" + this->getUserGlobalIP()
//		+ "{$}" + this->getUserLocalIP()
		+ "{$}" + this->getUserMAC() 
		+ "{$}" + this->getSyn()
		+ "{$}" + this->getAck()
		);
}

void Packet::findGlobalIP() {
    string command = "curl bot.whatismyipaddress.com";
	string tempUserGlobalIP = systemCommand(command);
	//char *pStr = convertStringToChar(command);	
	//system(pStr);
	char *pStr = convertStringToChar(tempUserGlobalIP);
	pStr = strtok(pStr, " ");
	tempUserGlobalIP = pStr;
	this->setUserGlobalIP(tempUserGlobalIP);
}
/*
void Packet::findLocalIP() {
	string command = "ifconfig";
	string tempUserLocalIP = systemCommand(command);
	char *pStr = convertStringToChar(tempUserLocalIP);
	pStr = strstr(pStr, "wlp");
	pStr = strstr(pStr, "inet addr");
	pStr = strtok(pStr, "inet addr:");
	tempUserLocalIP = pStr;
	this->setUserLocalIP(tempUserLocalIP);
}
*/
void Packet::findMAC() {

    struct ifaddrs *ifaddr=NULL;
    struct ifaddrs *ifa = NULL;
    int i = 0;
	string mac = "";

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
    }
    else {
        for ( ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
            if ( (ifa->ifa_addr) && (ifa->ifa_addr->sa_family == AF_PACKET) ) {
                struct sockaddr_ll *s = (struct sockaddr_ll*)ifa->ifa_addr;
				char *pStr = convertStringToChar(ifa->ifa_name);
                if(strstr(pStr, "wlp") != NULL) { // network name should be start with wlp
					//printf("%-8s ", ifa->ifa_name);
					string temp, temp1;
                	for (i=0; i <s->sll_halen; i++) {
						temp = to_string(s->sll_addr[i]);
						temp1 = convertDecStringToHexString(temp);
						if(i==(s->sll_halen-1))
							mac += temp1;
						else
							mac = mac + temp1 + ":";
					}
				}
             }
        }
    freeifaddrs(ifaddr);
    }
	this->setUserMAC(mac);
}

void makeSyn() {
	srand((unsigned)time(NULL));
	setSyn(rand());
}

void makeAck(){
	setAck(getSyn() + 1);
}

void makeCompAck() {
	setCompAck(getSyn() + 1);
}

string checkAck() {
	if(getCompAck() == getAck())
		return "true";
	else
		return "false";
}

char* Packet::convertStringToChar(const string &str){
    
    char *retPtr(new char[str.length() + 1]);
    
    copy(str.begin(), str.end(), retPtr);
    retPtr[str.length()] = '\0';;
    
    return retPtr;
}

string Packet::convertDecStringToHexString(const string decString) {
	long val;
	stringstream strstr1(decString);
	strstr1 >> val;
	stringstream strstr2;
	strstr2 << hex << val;
	return strstr2.str();
}

void Packet::itoa(int num, char *str) {
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

string Packet::systemCommand(string sysCommand) {

	char *pStr(convertStringToChar(sysCommand));
	FILE *stream = popen(pStr, "r");
    ostringstream output;
	while(!feof(stream) && !ferror(stream)) {
		char buf[128];
        int bytesRead = fread(buf, 1, 128 ,stream);
		output.write(buf, bytesRead);
    }
	pclose(stream);
    return output.str();
}
