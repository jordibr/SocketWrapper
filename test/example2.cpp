
#include <iostream>
#include <string.h>
#include <string>

#include "../header/ServerSocket.h"
#include "../header/Socket.h"
#include "../header/SocketException.h"

int main(){
	ServerSocket* ss;
	Socket* s;
	char* data;

	try{
		ss = new ServerSocket(12345);	
		s = ss->accept();

	}catch (SocketException sexc){
		std::cout << sexc.getErrorNo() << " ";
		std::cout << sexc.getErrorMsg() << std::endl;
		return 1;
	}

	data = new char[80];
	int r = s->read(data, 79);
	data[r] = '\0';
	std::cout << data << std::endl;
		
	s->close();
	ss->close();
	delete s;
	delete ss;
	delete data;
}