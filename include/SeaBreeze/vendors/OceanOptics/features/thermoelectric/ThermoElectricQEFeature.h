/***************************************************/ /**
 * @file    ThermoElectricQEFeature.h
 * @date    February 2009
 * @author  Ocean Optics, Inc.
 *
 * This feature provides an interface to the thermo-
 * electric cooler (TEC) on the QE65000 and similar
 * spectrometers (including the NIRQuest).
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
#include <SeaBreeze/common/features/Feature.h>
#include <SeaBreeze/common/protocols/Protocol.h>
#include <SeaBreeze/vendors/OceanOptics/features/thermoelectric/ThermoElectricFeatureBase.h>

namespace seabreeze {

class ThermoElectricQEFeature: public ThermoElectricFeatureBase {
  public:
	ThermoElectricQEFeature();
	virtual ~ThermoElectricQEFeature();

	/* Inherited from ThermoElectricFeatureBase where they are pure virtual */
	double getDefaultSetPointCelsius(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);
	bool getDefaultThermoElectricEnable(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	/* Override from Feature */
	virtual bool initialize(const Protocol &protocol, const Bus &bus) throw(FeatureException);

  private:
	std::vector<uint8_t> *readTECDefaults(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);
};

}// namespace seabreeze

/* THERMOELECTRICQEFEATURE_H */
