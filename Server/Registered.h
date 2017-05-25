#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class Registered {

private:

	string ID;
	string Passwd;
	string IP;
	string MAC;
	
public:

	void setID(string ID);
	void setPasswd(string Passwd);
	void setIP(string IP);
	void setMAC(string MAC);
		
	string getID();
	string getPasswd();
	string getIP();
	string getMAC();	

};
