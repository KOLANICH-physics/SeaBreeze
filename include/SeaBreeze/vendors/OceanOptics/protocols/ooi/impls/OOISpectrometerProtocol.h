/***************************************************/ /**
 * @file    OOISpectrometerProtocol.h
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

#pragma once

#include <SeaBreeze/common/SeaBreeze.h>
#include <SeaBreeze/common/buses/Bus.h>
#include <SeaBreeze/common/protocols/Exchange.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/interfaces/SpectrometerProtocolInterface.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/exchanges/IntegrationTimeExchange.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/exchanges/TriggerModeExchange.h>

#include <vector>

namespace seabreeze {
namespace ooiProtocol {
class OOISpectrometerProtocol: public SpectrometerProtocolInterface {
  public:
	OOISpectrometerProtocol(
		IntegrationTimeExchange *integrationTimeExchange,
		Transfer *requestFormattedSpectrumExchange,
		Transfer *readFormattedSpectrum,
		Transfer *requestUnformattedSpectrumExchange,
		Transfer *readUnformattedSpectrumExchange,
		Transfer *requestFastBufferSpectrumExchange,
		Transfer *readFastBufferSpectrumExchange,
		TriggerModeExchange *triggerMode);
	virtual ~OOISpectrometerProtocol();

	/* FIXME: instead of returning primitive vectors, should this return Data* so that
		 * metadata (units, etc.) can also be attached?
		 */
	virtual void requestFormattedSpectrum(const Bus &bus) throw(ProtocolException);
	virtual std::vector<double> *readFormattedSpectrum(const Bus &bus) throw(ProtocolException);
	virtual void requestUnformattedSpectrum(const Bus &bus) throw(ProtocolException);
	virtual std::vector<uint8_t> *readUnformattedSpectrum(const Bus &bus) throw(ProtocolException);
	virtual void requestFastBufferSpectrum(const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(ProtocolException);
	virtual std::vector<uint8_t> *readFastBufferSpectrum(const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(ProtocolException);
	virtual void setIntegrationTimeMicros(const Bus &bus, unsigned long time_usec) throw(ProtocolException);
	virtual void setTriggerMode(const Bus &bus, SpectrometerTriggerMode &mode) throw(ProtocolException);

  private:
	IntegrationTimeExchange *integrationTimeExchange;

	/* These are Transfers instead of Exchanges so that we can call getHints() on them.
		 * if getHints is promoted up to the level of Exchange, then these can revert back.
		 */
	Transfer *requestFormattedSpectrumExchange;
	Transfer *readFormattedSpectrumExchange;
	Transfer *requestUnformattedSpectrumExchange;
	Transfer *readUnformattedSpectrumExchange;
	Transfer *requestFastBufferSpectrumExchange;
	Transfer *readFastBufferSpectrumExchange;
	TriggerModeExchange *triggerModeExchange;
};
}// namespace ooiProtocol
}// namespace seabreeze

/* OOISPECTROMETERPROTOCOL_H */
