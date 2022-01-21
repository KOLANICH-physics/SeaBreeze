/***************************************************/ /**
 * @file    EEPROMSlotFeature.h
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

#include "vendors/OceanOptics/features/eeprom_slots/EEPROMSlotFeatureBase.h"
#include "vendors/OceanOptics/features/eeprom_slots/EEPROMSlotFeatureInterface.h"
#include <vector>

namespace seabreeze {

class EEPROMSlotFeature: public EEPROMSlotFeatureBase, public EEPROMSlotFeatureInterface {
  public:
	EEPROMSlotFeature(unsigned int numberOfSlots);
	virtual ~EEPROMSlotFeature();
	virtual std::vector<std::vector<uint8_t> *> *readAllEEPROMSlots(const Protocol &protocol,
		const Bus &bus) throw(FeatureException);

	/* Overriding this to change its visibility */
	virtual std::vector<uint8_t> *readEEPROMSlot(const Protocol &protocol,
		const Bus &bus, unsigned int slot) throw(FeatureException, IllegalArgumentException);
	virtual int writeEEPROMSlot(const Protocol &protocol,
		const Bus &bus, unsigned int slot, const std::vector<uint8_t> &data) throw(FeatureException, IllegalArgumentException);

	/* Overriding from Feature */
	virtual FeatureFamily getFeatureFamily();

  private:
	unsigned int numberOfSlots;
};

}// namespace seabreeze

/* EEPROMSLOTFEATURE_H */
