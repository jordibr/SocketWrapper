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

#include "../header/ServerSocket.h"
#include "../header/Socket.h"
#include "../header/SocketException.h"

ServerSocket::ServerSocket(int port)
{
	this->port = port;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		throw SocketException(sockfd, "Error creating socket.");

	bind();
	listen();
	isValid = true;
}

ServerSocket::~ServerSocket()
{
	close();
}

Socket*
ServerSocket::accept()
{
	struct sockaddr sockAddr;
	socklen_t sockAddrLng;
	return new Socket(::accept(sockfd, &sockAddr, &sockAddrLng));
}

void
ServerSocket::close()
{
	if (isValid)
	{
		::close(sockfd);
		isValid = false;
	}
}

void
ServerSocket::bind()
{
	struct sockaddr_in sockAddrInfo;
	bzero((char *) &sockAddrInfo, sizeof(sockAddrInfo));
	sockAddrInfo.sin_family = AF_INET;
	sockAddrInfo.sin_port = htons(port);
	sockAddrInfo.sin_addr.s_addr = INADDR_ANY;

	int status = ::bind(sockfd, (struct sockaddr *)&sockAddrInfo, sizeof (sockAddrInfo));
	if (status < 0)
		throw SocketException(status, "Error binding socket.");
}

void
ServerSocket::listen()
{
	if(::listen(sockfd, 1) < 0)
		throw SocketException(sockfd, "Socket error.");
}