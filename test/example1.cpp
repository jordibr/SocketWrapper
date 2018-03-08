
#include <iostream>
#include <string.h>
#include <string>

#include "../header/Socket.h"
#include "../header/SocketException.h"

int main(){
	Socket* s;
	try{
		s = new Socket("www.google.es", 80);
	}catch (SocketException sexc){
		std::cout << sexc.getErrorMsg() << std::endl;
		return 1;
	}

	/* Send data */
	char* data = new char[80];
	strcpy(data, "GET / HTTP/1.1\nHost: www.google.es\nUser-Agent: Test\n\n");
	s->write(data, strlen(data));

	/* Receive data */
	int r = s->read(data, 16);
	data[r] = '\0';
	std::cout << data << std::endl;
	
	s->close();
	delete s;
	delete data;
}