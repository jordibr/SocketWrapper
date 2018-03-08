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

#include <string>

#include "../header/SocketException.h"

SocketException::SocketException(int errorno, std::string errormsg)
{
	this->errorno = errorno;
	this->errormsg = errormsg;
}

int
SocketException::getErrorNo()
{
	return errorno;
}

std::string
SocketException::getErrorMsg()
{
	return errormsg;
}