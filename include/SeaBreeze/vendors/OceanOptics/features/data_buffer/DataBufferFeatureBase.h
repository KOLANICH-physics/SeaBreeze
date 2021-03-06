/***************************************************/ /**
 * @file    DataBufferFeature.h
 * @date    October 2015
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2015, Ocean Optics Inc
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

#include <vector>

#include <SeaBreeze/common/features/FeatureImpl.h>
#include <SeaBreeze/vendors/OceanOptics/features/data_buffer/DataBufferFeatureInterface.h>

namespace seabreeze {

class DataBufferFeatureBase: public FeatureImpl, public DataBufferFeatureInterface {
  public:
	DataBufferFeatureBase();
	virtual ~DataBufferFeatureBase();

	virtual DataBufferCount_t getNumberOfBuffers();
	virtual void clearBuffer(const Protocol &protocol, const Bus &bus,
		const DataBufferCount_t bufferIndex) throw(FeatureException);
	virtual void removeOldestSpectraFromBuffer(const Protocol &protocol, const Bus &bus,
		const DataBufferIndex_t bufferIndex, const unsigned int numberOfSpectra) throw(FeatureException);
	virtual DataBufferElementCount_t getNumberOfElements(
		const Protocol &protocol, const Bus &bus,
		const DataBufferIndex_t bufferIndex) throw(FeatureException);
	virtual DataBufferElementCount_t getBufferCapacity(
		const Protocol &protocol,
		const Bus &bus, const DataBufferIndex_t bufferIndex) throw(FeatureException);
	virtual DataBufferElementCount_t getBufferCapacityMinimum(
		const Protocol &protocol, const Bus &bus,
		const DataBufferIndex_t bufferIndex) throw(FeatureException);
	virtual DataBufferElementCount_t getBufferCapacityMaximum(
		const Protocol &protocol, const Bus &bus,
		const DataBufferIndex_t bufferIndex) throw(FeatureException);
	virtual void setBufferCapacity(const Protocol &protocol, const Bus &bus,
		const DataBufferIndex_t bufferIndex,
		const DataBufferElementCount_t bufferSize) throw(FeatureException);

	/* Overriding from Feature */
	virtual FeatureFamily getFeatureFamily();

  protected:
	DataBufferIndex_t numberOfBuffers;
};

}// namespace seabreeze

/* DATABUFFERFEATUREBASE_H */
