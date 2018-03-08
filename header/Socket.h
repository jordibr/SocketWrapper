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

#ifndef _C_SOCKET_
#define _C_SOCKET_

#include <string>

/* 
 * This class is a TCP/IP (v4) socket wrapper for Linux machines.
 */
class Socket
{
	private:
		int sockfd;
		int port;
		struct hostent* host;
		bool isValid;
	
		/* 
		 * Initiate a connection to the port and host specified
		 * in the constructor.
		 * Internally, call the connect system call.
		 */
		void connect();

	public:
		Socket(std::string host, int port);
		Socket(int sockfd);
		~Socket();

		/* 
		 * Close the socket connection.
		 */
		void close();

		/* 
		 * Reads at most n bytes from socket and save it in the buffer.
		 * Return the number of bytes read. In case of error, returns -1.
		 */
		int read(char* buffer, int bytes);

		/* 
		 * Writes at most n bytes in the socket. Bytes are the n first
		 * bytes of the buffer.
		 * Return the number of bytes written. In case of error, returns -1.
		 */
		int write(char* buffer, int bytes);
};

#endif /* _C_SOCKET_ */