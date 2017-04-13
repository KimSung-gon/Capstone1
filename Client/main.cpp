#include "Packet.h"

int main() {
	Packet a;
	a.findIP();
	a.findMAC();
	cout << a.getUserIP() << endl;
	cout << a.getUserMAC() << endl;
	return 0;
}
