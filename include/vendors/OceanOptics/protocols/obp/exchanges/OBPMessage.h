/***************************************************/ /**
 * @file    OBPMessage.h
 * @date    January 2011
 * @author  Ocean Optics, Inc.
 *
 * All messages in the Ocean Binary Protocol begin with
 * a standard 64-byte header.  It is always safe to read
 * 64 bytes for the start of a new transfer from a device
 * that supports this protocol, which works nicely with
 * the USB minimum packet size.
 *
 * This class simplifies the task of getting data into
 * and out of the header.
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

#include "common/SeaBreeze.h"
#include "common/exceptions/IllegalArgumentException.h"
#include <vector>

namespace seabreeze {
namespace oceanBinaryProtocol {
class OBPMessage {
  public:
	OBPMessage();
	~OBPMessage();

	static OBPMessage *parseHeaderFromByteStream(std::vector<uint8_t> *stream) throw(IllegalArgumentException);
	static OBPMessage *parseByteStream(std::vector<uint8_t> *stream) throw(IllegalArgumentException);

	std::vector<uint8_t> *toByteStream();
	std::vector<uint8_t> *getData();
	unsigned int getBytesRemaining();
	uint8_t getChecksumType();
	unsigned short getErrno();
	unsigned short getFlags();
	std::vector<uint8_t> *getImmediateData();
	uint8_t getImmediateDataLength();
	unsigned int getMessageType();
	std::vector<uint8_t> *getPayload();
	unsigned short getProtocolVersion();
	unsigned int getRegarding();

	bool isAckFlagSet();
	bool isNackFlagSet();

	void setAckRequestedFlag();
	void setBytesRemaining(unsigned int bytesRemaining);
	void setChecksumType(uint8_t checksumType);
	void setData(std::vector<uint8_t> *data);
	void setErrorNumber(unsigned short errorNumber);
	void setFlags(unsigned short flags);
	void setImmediateData(std::vector<uint8_t> *immediateData);
	void setImmediateDataLength(uint8_t immediateDataLength);
	void setMessageType(unsigned int messageType);
	void setPayload(std::vector<uint8_t> *payload);
	void setProtocolVersion(unsigned short protocolVersion);
	void setRegarding(unsigned int regarding);

  protected:
	void setupMessage();
	std::vector<uint8_t> *header;
	unsigned short protocolVersion;
	unsigned short flags;
	unsigned short errorNumber;
	unsigned int messageType;
	unsigned int regarding;
	uint8_t checksumType;
	uint8_t immediateDataLength;
	std::vector<uint8_t> *immediateData;
	unsigned int bytesRemaining;
	std::vector<uint8_t> *payload;
	std::vector<uint8_t> *checksum;
	std::vector<uint8_t> *footer;
};

}// namespace oceanBinaryProtocol
}// namespace seabreeze

/* OBPMESSAGE_H */
