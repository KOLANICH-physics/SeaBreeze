/***************************************************/ /**
 * @file    ProgrammableSaturationFeatureImpl.h
 * @date    March 2016
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2016, Ocean Optics Inc
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

#include <SeaBreeze/common/features/FeatureImpl.h>
#include <SeaBreeze/common/protocols/ProtocolHelper.h>
#include <SeaBreeze/vendors/OceanOptics/features/spectrometer/ProgrammableSaturationFeatureBase.h>
#include <vector>

namespace seabreeze {
/* This class is intended for devices that have a clean protocol
	 * interface for reading out the saturation level directly.
	 */
class ProgrammableSaturationFeatureImpl
	: public ProgrammableSaturationFeatureBase,
	  FeatureImpl {
  public:
	ProgrammableSaturationFeatureImpl(std::vector<ProtocolHelper *> helpers);
	virtual ~ProgrammableSaturationFeatureImpl();

	virtual bool initialize(const Protocol &protocol, const Bus &bus) throw(FeatureException);

	virtual FeatureFamily getFeatureFamily();

  protected:
	/* Inherited from ProgrammableSaturationFeatureBase */
	virtual unsigned int getSaturation(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);
};

} /* end namespace seabreeze */
