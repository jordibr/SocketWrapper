/* 
 * This file is part of SocketWrapper.
 * 
 * SocketWrapper is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * SocketWrapper is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Foobar. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>
#include <string.h>
#include <exception>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

#include "../header/Socket.h"
#include "../header/SocketException.h"

Socket::Socket(std::string host, int port)
{
	this->host = gethostbyname(host.c_str());
	this->port = port;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		throw SocketException(sockfd, "Error creating socket.");

	connect();
	isValid = true;
}

Socket::Socket(int sockfd)
{
	this->sockfd = sockfd;
	isValid = true;
}

Socket::~Socket()
{
	close();
}

void
Socket::close()
{
	if (isValid)
	{
		::close(sockfd);
		isValid = false;
	}
}

int
Socket::read(char* buffer, int bytes)
{
	if (!isValid)
		throw SocketException(-1, "Invalid socket status.");
	
	return ::read(sockfd, buffer, bytes);
}

int
Socket::write(char* buffer, int bytes)
{
	if (!isValid)
		throw SocketException(-1, "Invalid socket status.");

	return ::write(sockfd, buffer, bytes);
}

void
Socket::connect()
{
	struct sockaddr_in sockAddrInfo;
	bzero((char *) &sockAddrInfo, sizeof(sockAddrInfo));
	sockAddrInfo.sin_family = AF_INET;
	sockAddrInfo.sin_port = htons(port);
	bcopy((char *)host->h_addr,
		  (char *)&sockAddrInfo.sin_addr.s_addr,
		  host->h_length);

	int status = ::connect(sockfd, (struct sockaddr *)&sockAddrInfo, sizeof(sockAddrInfo));
	if (status < 0)
		throw SocketException(status, "Error connecting.");
}