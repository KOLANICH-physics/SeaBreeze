/***************************************************/ /**
 * @file    OOISpectrometerFeature.h
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

#include <SeaBreeze/common/buses/Bus.h>
#include <SeaBreeze/common/exceptions/FeatureException.h>
#include <SeaBreeze/common/exceptions/IllegalArgumentException.h>
#include <SeaBreeze/common/features/FeatureImpl.h>
#include <SeaBreeze/common/protocols/Protocol.h>
#include <SeaBreeze/vendors/OceanOptics/features/fast_buffer/FlameXFastBufferFeature.h>
#include <SeaBreeze/vendors/OceanOptics/features/introspection/IntrospectionFeature.h>
#include <SeaBreeze/vendors/OceanOptics/features/spectrometer/OOISpectrometerFeatureInterface.h>
#include <SeaBreeze/vendors/OceanOptics/features/spectrometer/SpectrometerTriggerMode.h>
#include <vector>

namespace seabreeze {

class OOISpectrometerFeature: public FeatureImpl,
							  public OOISpectrometerFeatureInterface {
  public:
	OOISpectrometerFeature();
	virtual ~OOISpectrometerFeature();
	/* Request and read out a spectrum formatted into intensity (A/D counts) */
	virtual std::vector<double> *getFormattedSpectrum(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	/* Request and read out the raw spectrum data stream */
	virtual std::vector<uint8_t> *getUnformattedSpectrum(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	virtual std::vector<uint8_t> *getFastBufferSpectrum(const Protocol &protocol,
		const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(FeatureException);

	virtual void fastBufferSpectrumRequest(const Protocol &protocol,
		const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(FeatureException);

	virtual std::vector<uint8_t> *fastBufferSpectrumResponse(const Protocol &protocol,
		const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(FeatureException);

	/* Request and read out the wavelengths in nanometers as a vector of doubles */
	virtual std::vector<double> *getWavelengths(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	/* Read the raw spectrum data stream.  No request is made first. */
	virtual std::vector<uint8_t> *readUnformattedSpectrum(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	virtual std::vector<uint8_t> *readFastBufferSpectrum(const Protocol &protocol,
		const Bus &bus, unsigned int numberOfSamplesToReceive) throw(FeatureException);

	/* Set the integration time of the spectrometer */
	virtual void setIntegrationTimeMicros(const Protocol &protocol,
		const Bus &bus, unsigned long time_usec) throw(FeatureException, IllegalArgumentException);

	/* Request that the spectrometer make a spectrum available for
		 * reading (e.g. with readUnformattedSpectrum())
		 */
	virtual void writeRequestFormattedSpectrum(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	virtual void writeRequestUnformattedSpectrum(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	virtual void writeRequestFastBufferSpectrum(const Protocol &protocol,
		const Bus &bus, unsigned int numberOfSamplesToRetrieve) throw(FeatureException);

	/* Setting the external trigger mode for the spectrometer */
	virtual void setTriggerMode(const Protocol &protocol,
		const Bus &bus, SpectrometerTriggerMode &mode) throw(FeatureException);

	virtual std::vector<SpectrometerTriggerMode *> getTriggerModes() const;

	virtual std::vector<unsigned int> getActivePixelIndices() const;
	virtual std::vector<unsigned int> getElectricDarkPixelIndices() const;
	virtual std::vector<unsigned int> getOpticalDarkPixelIndices() const;

	virtual long getIntegrationTimeMinimum() const;
	virtual long getIntegrationTimeMaximum() const;
	virtual long getIntegrationTimeIncrement() const;

	virtual unsigned short getNumberOfPixels() const;
	virtual int getMaximumIntensity() const;

	/* Overriding from Feature */
	virtual FeatureFamily getFeatureFamily();

  protected:
	/* introspection feature */
	IntrospectionFeature *myIntrospection;
	FlameXFastBufferFeature *myFastBuffer;

	/* Detector details */
	unsigned short numberOfPixels;
	unsigned short numberOfBytesPerPixel;
	unsigned int maxIntensity;

	/* Integration time parameters (measured in microseconds) */
	long integrationTimeMinimum;
	long integrationTimeMaximum;
	long integrationTimeBase;
	long integrationTimeIncrement;

	std::vector<SpectrometerTriggerMode *> triggerModes;
	std::vector<unsigned int> electricDarkPixelIndices;
	std::vector<unsigned int> opticalDarkPixelIndices;
	std::vector<unsigned int> activePixelIndices;
};

}// namespace seabreeze

/* OOISPECTROMETERFEATURE_H */
