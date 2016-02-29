/***************************************************/ /**
 * @file    Daemon.cpp
 * @date    February 2015
 * @author  Ocean Optics, Inc.
 *
 * Bring together the IO service, configuration and handler and start the service.
 *
 *
 * LICENSE:
 *
 * Dev Kit Copyright (C) 2015, Ocean Optics Inc
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

#include "Daemon.h"
#include "OceanHandler.h"
#include "OceanHandlerConfiguration.h"

using boost::asio::ip::tcp;

/* Start the request handling service.
*/
void Daemon::Run() {
	m_connectionHandler.SetIoService(&m_ioService);
	m_connectionHandler.Start(m_configuration.Port());
}

/* Constructor. bring all of the component parts together.
*/
Daemon::Daemon(boost::asio::io_service &ioService, OceanHandlerConfiguration &configuration, OceanHandler &connectionHandler)
	:

	  m_ioService(ioService),
	  m_configuration(configuration),
	  m_connectionHandler(connectionHandler) {
}

Daemon::~Daemon() {
}