/***************************************************/ /**
 * @file    NativeSocketWindows.c
 * @date    February 2016
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2016, Ocean Optics Inc
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *******************************************************/

/* Includes */
#include <sstream>

#include <SeaBreeze/common/SeaBreeze.h>
#include <SeaBreeze/native/network/SocketTimeoutException.h>
#include <SeaBreeze/native/network/windows/NativeSocketWindows.h>

using namespace seabreeze;
using namespace std;

Socket *Socket::create() {
	return new NativeSocketWindows();
}

NativeSocketWindows::NativeSocketWindows() {
	this->sock = (SOCKET) -1;
	this->bound = false;
	this->closed = true;
}

NativeSocketWindows::~NativeSocketWindows() {
	close();
}

void NativeSocketWindows::connect(Inet4Address &addr, int port) throw(UnknownHostException, BusConnectException) {
	struct in_addr in;
	struct sockaddr_in sockaddr;
	int addrlen;
	SOCKET server;

	in = addr.getAddress();

	memset((void *) &sockaddr, (int) 0, sizeof(struct sockaddr));
	memcpy((char *) &sockaddr.sin_addr.s_addr, &in, sizeof(struct in_addr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = (unsigned short) htons(port);
	server = socket(PF_INET, SOCK_STREAM, 0);

	addrlen = sizeof(sockaddr);
	if(::connect(server, (struct sockaddr *) &sockaddr, addrlen) < 0) {
		this->sock = (SOCKET) -1;
		this->closed = true;
		std::stringstream error;
		error << "Socket connect failed: Error " << WSAGetLastError();
		throw BusConnectException(error.str());
	}

	this->bound = true;
	this->closed = false;
	this->sock = server;
	this->address = addr;
}

void NativeSocketWindows::connect(const string hostname, int port) throw(UnknownHostException, BusConnectException) {

	struct hostent *host_info;
	struct in_addr in;

	host_info = gethostbyname(hostname.c_str());
	if(0 == host_info) {
		string error("Failed to resolve hostname [");
		error += hostname;
		error += "]: ";
		error += (char) WSAGetLastError();
		throw BusConnectException(error);
	}

	memcpy(&in, host_info->h_addr_list[0], host_info->h_length);

	Inet4Address inet4addr(&in);

	connect(inet4addr, port);
}

void NativeSocketWindows::close() throw(BusException) {
	int result;

	if(this->sock >= 0 && false == this->closed) {
		shutdown(this->sock, SD_BOTH);
		result = ::closesocket(this->sock);
		this->sock = (SOCKET) -1;
		this->bound = false;
		this->closed = true;

		if(result != 0) {
			std::stringstream error;
			error << "Got error when trying to close socket:  Error " << WSAGetLastError();
			throw BusException(error.str());
		}
	}
}

bool NativeSocketWindows::isClosed() {
	return this->closed;
}

bool NativeSocketWindows::isBound() {
	return this->bound;
}

int NativeSocketWindows::getSOLinger() throw(SocketException) {
	linger so_linger;
	int length;
	int result;

	if(this->sock < 0) {
		string error("Attempted to get socket options on invalid socket.");
		throw SocketException(error);
	}

	length = sizeof(so_linger);
	result = getsockopt(this->sock, SOL_SOCKET, SO_LINGER, (char *) &so_linger, &length);

	if(result < 0 || length != sizeof(so_linger)) {
		std::stringstream error;
		error << "Failed to get socket options:  Error " << WSAGetLastError();
		throw SocketException(error.str());
	}

	if(0 == so_linger.l_onoff) {
		return 0;
	}

	return so_linger.l_linger;
}

void NativeSocketWindows::setSOLinger(bool enable, int linger) throw(SocketException) {
	struct linger so_linger;
	int result;

	if(this->sock < 0) {
		string error("Attempted to set socket options on invalid socket.");
		throw SocketException(error);
	}

	so_linger.l_onoff = (true == enable ? 1 : 0);
	so_linger.l_linger = (unsigned short) linger;

	result = setsockopt(this->sock, SOL_SOCKET, SO_LINGER, (char *) &so_linger, sizeof(so_linger));

	if(result < 0) {
		std::stringstream error;
		error << "Failed to set socket options: Error " << WSAGetLastError();
		throw SocketException(error.str());
	}
}

unsigned long NativeSocketWindows::getReadTimeoutMillis() throw(SocketException) {
	unsigned long timeoutMillis;
	int result;
	unsigned int length;

	if(this->sock < 0) {
		string error("Attempted to get socket options on invalid socket.");
		throw SocketException(error);
	}

	length = sizeof(timeoutMillis);
	result = getsockopt(this->sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeoutMillis, (int *) &length);

	if(result < 0 || length != sizeof(timeoutMillis)) {
		std::stringstream error;
		error << "Failed to get socket options: Error " << WSAGetLastError();
		throw SocketException(error.str());
	}

	return timeoutMillis;
}

void NativeSocketWindows::setReadTimeoutMillis(unsigned long timeoutMillis) throw(SocketException) {
	int result;

	if(this->sock < 0) {
		string error("Attempted to get socket options on invalid socket.");
		throw SocketException(error);
	}

	result = setsockopt(this->sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeoutMillis, sizeof(timeoutMillis));

	if(result < 0) {
		std::stringstream error;
		error << "Failed to set socket options: Error " << WSAGetLastError();
		throw SocketException(error.str());
	}
}

int NativeSocketWindows::read(unsigned char *buf, unsigned long count) throw(BusTransferException) {
	int result = ::recv(this->sock, (char *) buf, count, 0);

	if(result < 0) {
		int err = WSAGetLastError();
		if(WSAEWOULDBLOCK == err) {
			string error("No data available on non-blocking socket.");
			throw SocketTimeoutException(error);
		} else {
			std::stringstream error;
			error << "Socket error on read: Error " << WSAGetLastError();
			throw SocketException(error.str());
		}
	}

	return result;
}

int NativeSocketWindows::write(const unsigned char *buf, unsigned long count) throw(BusTransferException) {
	int result = ::send(this->sock, (char *) buf, count, 0);

	if(result < 0) {
		std::stringstream error;
		error << "Socket error on write: Error " << WSAGetLastError();
		throw BusTransferException(error.str());
	}

	return result;
}
