/***************************************************/ /**
 * @file    IntrospectionFeatureInterface.h
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

#ifndef INSTROSPECTION_FEATURE_INTERFACE_H
#define INSTROSPECTION_FEATURE_INTERFACE_H

#include "common/buses/Bus.h"
#include "common/exceptions/FeatureException.h"
#include "common/features/Feature.h"
#include "common/protocols/Protocol.h"

namespace seabreeze {

class IntrospectionFeatureInterface {
  public:
	virtual ~IntrospectionFeatureInterface();

	virtual unsigned long getIntrospection_example(
		const Protocol &protocol, const Bus &bus) throw(FeatureException) = 0;
	virtual void setIntrospection_example(
		const Protocol &Protocol, const Bus &bus,
		const unsigned long delayMicros) throw(FeatureException) = 0;
};

/* Default implementation for (otherwise) pure virtual destructor */
inline IntrospectionFeatureInterface::~IntrospectionFeatureInterface() {
}

}// namespace seabreeze

#endif /* INTROSPECTION_FEATURE_INTERFACE_H */