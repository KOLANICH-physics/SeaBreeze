/***************************************************/ /**
 * @file    ProtocolFamily.cpp
 * @date    February 2012
 * @author  Ocean Optics, Inc.
 *
 * This provides a way to describe different kinds
 * features (e.g. spectrometer, TEC) generically.
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

#include <SeaBreeze/common/globals.h>
#include <SeaBreeze/common/protocols/ProtocolFamily.h>

using namespace seabreeze;
using namespace std;

ProtocolFamily::ProtocolFamily(string name, unsigned short id) {
	this->protocolName = name;
	this->type = id;
}

ProtocolFamily::~ProtocolFamily() {
}

string ProtocolFamily::getName() {
	return this->protocolName;
}

bool ProtocolFamily::equals(const ProtocolFamily &that) {
	return this->type == that.type;
}

unsigned short ProtocolFamily::getType() {
	return this->type;
}
