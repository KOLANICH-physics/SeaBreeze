/***************************************************/ /**
 * @file    OOIEEPROMProtocol.cpp
 * @date    February 2009
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

#include <SeaBreeze/common/ByteVector.h>
#include <SeaBreeze/common/exceptions/ProtocolBusMismatchException.h>
#include <SeaBreeze/common/globals.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/exchanges/ReadEEPROMSlotExchange.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/exchanges/WriteEEPROMSlotExchange.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/impls/OOIEEPROMProtocol.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/impls/OOIProtocol.h>
#include <string.h>
#include <string>
#include <vector>

using namespace seabreeze;
using namespace seabreeze::ooiProtocol;
using namespace std;

OOIEEPROMProtocol::OOIEEPROMProtocol()
	: EEPROMProtocolInterface(new OOIProtocol()) {
}

OOIEEPROMProtocol::~OOIEEPROMProtocol() {
}

vector<uint8_t> *OOIEEPROMProtocol::readEEPROMSlot(const Bus &bus, int slot) throw(ProtocolException) {

	ByteVector *bv = NULL;
	Data *result = NULL;

	ReadEEPROMSlotExchange xchange(slot);

	TransferHelper *helper = bus.getHelper(xchange.getHints());
	if(NULL == helper) {
		string error("Failed to find a helper to bridge given protocol and bus.");
		throw ProtocolBusMismatchException(error);
	}

	result = xchange.transfer(helper);
	if(NULL == result) {
		string error("Expected Transfer::transfer to produce a non-null result "
					 "containing raw EEPROM data.  Without this data, it is not possible to "
					 "generate a valid EEPROM slot value.");
		throw ProtocolException(error);
	}

	bv = static_cast<ByteVector *>(result);

	// strip off leading two bytes (echoed request)
	vector<uint8_t> raw = bv->getByteVector();
	vector<uint8_t> *retval = new vector<uint8_t>(raw.size() - 2);
	memcpy(&((*retval)[0]), &(raw[2]), retval->size());

	delete result; /* a.k.a. bv */

	return retval;
}

int OOIEEPROMProtocol::writeEEPROMSlot(const Bus &bus, int slot, const vector<uint8_t> &data) throw(ProtocolException) {

	WriteEEPROMSlotExchange xchange(slot, data);

	TransferHelper *helper = bus.getHelper(xchange.getHints());
	if(NULL == helper) {
		string error("Failed to find a helper to bridge given protocol and bus.");
		throw ProtocolBusMismatchException(error);
	}

	xchange.transfer(helper);

	return (int) data.size();
}
