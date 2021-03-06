/***************************************************/ /**
 * @file    ContinuousStrobeFeature.cpp
 * @date    October 2012
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

#include <SeaBreeze/api/seabreezeapi/FeatureFamilies.h>
#include <SeaBreeze/common/exceptions/FeatureControlException.h>
#include <SeaBreeze/common/exceptions/FeatureProtocolNotFoundException.h>
#include <SeaBreeze/common/globals.h>
#include <SeaBreeze/vendors/OceanOptics/features/continuous_strobe/ContinuousStrobeFeature.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/interfaces/ContinuousStrobeProtocolInterface.h>
#include <math.h>

using namespace seabreeze;
using namespace seabreeze::api;
using namespace std;

ContinuousStrobeFeature::ContinuousStrobeFeature(vector<ProtocolHelper *> helpers) {

	vector<ProtocolHelper *>::iterator iter;
	for(iter = helpers.begin(); iter != helpers.end(); iter++) {
		this->protocols.push_back(*iter);
	}
}

ContinuousStrobeFeature::~ContinuousStrobeFeature() {
}

void ContinuousStrobeFeature::setContinuousStrobePeriodMicroseconds(const Protocol &protocol,
	const Bus &bus, unsigned short strobe_id, unsigned long period_usec) throw(FeatureException) {
	ContinuousStrobeProtocolInterface *contStrobe = NULL;
	ProtocolHelper *proto = NULL;

	try {
		proto = lookupProtocolImpl(protocol);
		contStrobe = static_cast<ContinuousStrobeProtocolInterface *>(proto);
	} catch(FeatureProtocolNotFoundException &e) {
		string error(
			"Could not find matching protocol implementation to control continuous strobe.");
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureProtocolNotFoundException(error);
	}

	try {
		contStrobe->setContinuousStrobePeriodMicroseconds(bus, strobe_id, period_usec);
	} catch(ProtocolException &pe) {
		string error("Caught protocol exception: ");
		error += pe.what();
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureControlException(error);
	}
}

void ContinuousStrobeFeature::setContinuousStrobeEnable(const Protocol &protocol,
	const Bus &bus, unsigned short strobe_id, bool enable) throw(FeatureException) {
	ContinuousStrobeProtocolInterface *contStrobe = NULL;
	ProtocolHelper *proto = NULL;

	try {
		proto = lookupProtocolImpl(protocol);
		contStrobe = static_cast<ContinuousStrobeProtocolInterface *>(proto);
	} catch(FeatureProtocolNotFoundException &e) {
		string error(
			"Could not find matching protocol implementation to control continuous strobe.");
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureProtocolNotFoundException(error);
	}

	try {
		contStrobe->setContinuousStrobeEnable(bus, strobe_id, enable);
	} catch(ProtocolException &pe) {
		string error("Caught protocol exception: ");
		error += pe.what();
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureControlException(error);
	}
}

FeatureFamily ContinuousStrobeFeature::getFeatureFamily() {
	FeatureFamilies families;

	return families.CONTINUOUS_STROBE;
}
