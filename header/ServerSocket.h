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

#ifndef _C_SERVERSOCKET_
#define _C_SERVERSOCKET_

#include "../header/Socket.h"

/* 
 * This class is a TCP/IP (v4) socket server wrapper for Linux machines.
 */
class ServerSocket
{
	private:	
		int sockfd;
		int port;
		bool isValid;

		void bind();
		void listen();
	
	public:
		ServerSocket(int port);
		~ServerSocket();

		/* 
		 * Waits for new connection and returns a Socket object that 
		 * can be used to send and receive data from client.
		 */
		Socket* accept();

		/* 
		 * Close the socket connection.
		 */
		void close();
};

#endif /* _C_SERVERSOCKET_ */