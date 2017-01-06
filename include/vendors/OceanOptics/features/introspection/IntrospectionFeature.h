/***************************************************/ /**
 * @file    IntrospectionFeature.h
 * @date    January 2017
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2017, Ocean Optics Inc
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

#ifndef INTROSPECTION_FEATURE_H
#define INSTROSPECTION_FEATURE_H

#include "common/buses/Bus.h"
#include "common/exceptions/FeatureException.h"
#include "common/features/FeatureImpl.h"
#include "common/protocols/Protocol.h"
#include "vendors/OceanOptics/features/introspection/IntrospectionFeatureInterface.h"

namespace seabreeze {

class IntrospectionFeature: public FeatureImpl,
							public IntrospectionFeatureInterface {
  public:
	IntrospectionFeature(std::vector<ProtocolHelper *> helpers);
	virtual ~IntrospectionFeature();

	virtual void setIntrospection_example(
		const Protocol &protocol, const Bus &bus,
		const unsigned long test) throw(FeatureException);

	virtual unsigned long getIntrospection_example(
		const Protocol &protocol, const Bus &bus) throw(FeatureException);

	/* Overriding from Feature */
	virtual FeatureFamily getFeatureFamily();

	/* Methods that remain pure virtual since the protocol interface does
		 * not necessarily provide clean methods for these.  A derived
		 * class will be necessary to specify the limits.
		 */
	virtual unsigned long anotherIntrospectionExample(
		const Protocol &protocol, const Bus &bus) throw(FeatureException) = 0;

  protected:
	unsigned long bogus;
};

} /* end namespace seabreeze */

#endif /* INTROSPECTION_FEATURE_H */