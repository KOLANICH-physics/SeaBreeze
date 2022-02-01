/***************************************************/ /**
 * @file    OBPThermoElectricProtocol.h
 * @date    March 2013
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
#include <SeaBreeze/vendors/OceanOptics/protocols/interfaces/ThermoElectricProtocolInterface.h>
#include <string>

namespace seabreeze {
namespace oceanBinaryProtocol {
class OBPThermoElectricProtocol: public ThermoElectricProtocolInterface {
  public:
	OBPThermoElectricProtocol();
	virtual ~OBPThermoElectricProtocol();

	virtual double readThermoElectricTemperatureCelsius(const Bus &bus) throw(ProtocolException);

	virtual void writeThermoElectricEnable(const Bus &bus, bool enable) throw(ProtocolException);

	virtual void writeThermoElectricSetPointCelsius(const Bus &bus,
		double degreesC) throw(ProtocolException);
};
}// namespace oceanBinaryProtocol
}// namespace seabreeze

/* OBPTHERMOELECTRICPROTOCOL_H */
