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

#ifndef _C_SOCKETEXCEPTION_
#define _C_SOCKETEXCEPTION_

#include <string>
#include <exception>

/* 
 * This class is throwed when a error ocurred in library
 */
class SocketException : std::exception
{
	private:
		int errorno;
		std::string errormsg;

	public:
		SocketException(int errorno, std::string errormsg);

		int getErrorNo();

		std::string getErrorMsg();
};

#endif /* _C_SOCKETEXCEPTION_ */