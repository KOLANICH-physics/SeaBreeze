/***************************************************/ /**
 * @file    OOIRS232Interface.h
 * @date    April 2011
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2014, Ocean Optics Inc
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

#pragma once

#include "common/buses/TransferHelper.h"
#include "common/buses/rs232/RS232Interface.h"
#include "common/protocols/ProtocolHint.h"

namespace seabreeze {

class OOIRS232Interface: public RS232Interface {
  public:
	OOIRS232Interface();
	virtual ~OOIRS232Interface();

	/* Inherited from Bus */
	virtual TransferHelper *getHelper(const std::vector<ProtocolHint *> &hints) const;
	virtual void setLocation(const DeviceLocatorInterface &location) throw(IllegalArgumentException);
	virtual bool open();
	virtual void close();

  protected:
	TransferHelper *rs232Helper;

	int baudRate;
};

}// namespace seabreeze

/* OOIRS232INTERFACE_H */
