/***************************************************/ /**
 * @file    WaveCalCoeffsEEPromFeature.cpp
 * @date    February 2011
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

#include "api/seabreezeapi/FeatureFamilies.h"
#include "common/exceptions/FeatureControlException.h"
#include "common/exceptions/FeatureProtocolNotFoundException.h"
#include "common/globals.h"
#include "vendors/OceanOptics/features/wavecalcoeffseeprom/WaveCalCoeffsEEPromFeature.h"
#include "vendors/OceanOptics/protocols/interfaces/WaveCalCoeffsEEPromProtocolInterface.h"
#include "vendors/OceanOptics/protocols/obp/impls/OBPWaveCalCoeffsEEPromProtocol.h"
#include "vendors/OceanOptics/utils/Polynomial.h"

using namespace seabreeze;
using namespace seabreeze::oceanBinaryProtocol;
using namespace seabreeze::api;
using namespace std;

#ifdef _WINDOWS
#pragma warning(disable : 4101)// unreferenced local variable
#endif

WaveCalCoeffsEEPromFeature::WaveCalCoeffsEEPromFeature(vector<ProtocolHelper *> helpers, unsigned int numberOfPix) {

	this->numberOfPixels = numberOfPix;

	vector<ProtocolHelper *>::iterator iter;
	for(iter = helpers.begin(); iter != helpers.end(); iter++) {
		this->protocols.push_back(*iter);
	}
}

WaveCalCoeffsEEPromFeature::~WaveCalCoeffsEEPromFeature() {
}

vector<double> *WaveCalCoeffsEEPromFeature::readWavelengths(const Protocol &protocol,
	const Bus &bus) throw(FeatureException) {

	WaveCalCoeffsEEPromProtocolInterface *wavecal = NULL;
	vector<double> *coeffs = NULL;
	ProtocolHelper *proto = NULL;
	Polynomial<double> *calibration = NULL;
	vector<double> *retval = NULL;

	try {
		proto = lookupProtocolImpl(protocol);
		wavecal = static_cast<WaveCalCoeffsEEPromProtocolInterface *>(proto);
	} catch(FeatureProtocolNotFoundException &e) {
		string error(
			"Could not find matching protocol implementation to get wavelength calibration.");
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureProtocolNotFoundException(error);
	}

	try {
		coeffs = wavecal->readWavelengthCoeffs(bus);
		calibration = new Polynomial<double>(coeffs);
		retval = new vector<double>(this->numberOfPixels);
		for(unsigned int i = 0; i < retval->size(); i++) {
			(*retval)[i] = calibration->evaluate(i);
		}
		delete calibration;
		delete coeffs;
	} catch(ProtocolException &pe) {
		string error("Caught protocol exception: ");
		error += pe.what();
		/* FIXME: previous exception should probably be bundled up into the new exception */
		throw FeatureControlException(error);
	}

	return retval;
}

FeatureFamily WaveCalCoeffsEEPromFeature::getFeatureFamily() {
	FeatureFamilies families;

	return families.WAVELENGTH_CAL;
}
