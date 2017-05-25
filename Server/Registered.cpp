#include "Registered.h"

void Registered::setID(string ID) {
	this->ID = ID;
}

void Registered::setPasswd(string Passwd) {
	this->Passwd = Passwd;
}

void Registered::setIP(string IP) {
	this->IP = IP;
}

void Registered::setMAC(string MAC) {
	this->MAC = MAC;
}

string Registered::getID() {
	return ID;
}

string Registered::getPasswd() {
	return Passwd;
}
		
string Registered::getIP() {
	return IP;
}

string Registered::getMAC() {
	return MAC;
}
