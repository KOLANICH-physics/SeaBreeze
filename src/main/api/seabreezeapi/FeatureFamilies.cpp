/***************************************************/ /**
 * @file    FeatureFamilies.cpp
 * @date    February 2015
 * @author  Ocean Optics, Inc., Kirk Clendinning, Heliospectra
 *
 * This provides a way to get references to different kinds
 * of features (e.g. spectrometer, TEC) generically.
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
#include <SeaBreeze/common/globals.h>

/* Constants */
enum FEATURE_FAMILY {
	FEATURE_FAMILY_ID_UNDEFINED = 0,
	FEATURE_FAMILY_ID_SERIAL_NUMBER = 1,
	FEATURE_FAMILY_ID_SPECTROMETER = 2,
	FEATURE_FAMILY_ID_THERMOELECTRIC = 3,
	FEATURE_FAMILY_ID_IRRADCAL = 4,
	FEATURE_FAMILY_ID_EEPROM = 5,
	FEATURE_FAMILY_ID_STROBE_LAMP = 6,
	FEATURE_FAMILY_ID_SHUTTER = 7,
	FEATURE_FAMILY_ID_WAVECAL = 8,
	FEATURE_FAMILY_ID_NONLINEARITYCAL = 9,
	FEATURE_FAMILY_ID_STRAYLIGHTCAL = 10,
	FEATURE_FAMILY_ID_RAW_BUS_ACCESS = 11,
	FEATURE_FAMILY_ID_RAW_USB_BUS_ACCESS = 11,
	FEATURE_FAMILY_ID_CONTINUOUS_STROBE = 12,
	FEATURE_FAMILY_ID_LIGHT_SOURCE = 13,
	FEATURE_FAMILY_ID_TEMPERATURE = 14,
	FEATURE_FAMILY_ID_OPTICAL_BENCH = 15,
	FEATURE_FAMILY_ID_REVISION = 16,
	FEATURE_FAMILY_ID_SPECTRUM_PROCESSING = 17,
	FEATURE_FAMILY_ID_DATA_BUFFER = 18,
	FEATURE_FAMILY_ID_ACQUISITION_DELAY = 19,
	FEATURE_FAMILY_ID_PIXEL_BINNING = 20,// was 18... that appears to have been a bug
	FEATURE_FAMILY_ID_INTROSPECTION = 21,
	FEATURE_FAMILY_ID_FAST_BUFFER = 22,
	FEATURE_FAMILY_ID_AUTO_NULLING_ANALOG = 23,
	FEATURE_FAMILY_ID_AUTO_NULLING_DIGITAL = 24,
	FEATURE_FAMILY_ID_ETHERNET_CONFIGURATION = 25,
	FEATURE_FAMILY_ID_WIFI_CONFIGURATION = 26,
	FEATURE_FAMILY_ID_NETWORK_CONFIGURATION = 27,
	FEATURE_FAMILY_ID_DHCP_SERVER = 28,
	FEATURE_FAMILY_ID_BLUETOOTH_CONFIGURATION = 29,
	FEATURE_FAMILY_ID_TIME_COMMANDS = 30,
	FEATURE_FAMILY_ID_RS232_BUS_COMMANDS = 31,
	FEATURE_FAMILY_ID_IPV4 = 32,
	FEATURE_FAMILY_ID_MULTICAST = 33,
	FEATURE_FAMILY_ID_NETWORK_SERIVICES = 34,
	FEATURE_FAMILY_ID_DEVICE_IDENTIFICATION = 35,
	FEATURE_FAMILY_ID_TEST_COMMANDS = 36,
	FEATURE_FAMILY_ID_GPIO = 37,
	FEATURE_FAMILY_ID_I2C_MASTER = 38,
};

using namespace seabreeze;
using namespace seabreeze::api;
using namespace std;

seabreeze::api::FeatureFamilies::FeatureFamilies() {
}

seabreeze::api::FeatureFamilies::~FeatureFamilies() {
}

seabreeze::api::UndefinedFeatureFamily::UndefinedFeatureFamily()
	: FeatureFamily("Undefined", FEATURE_FAMILY_ID_UNDEFINED) {
}

seabreeze::api::UndefinedFeatureFamily::~UndefinedFeatureFamily() {
}

seabreeze::api::SerialNumberFeatureFamily::SerialNumberFeatureFamily()
	: FeatureFamily("SerialNumber", FEATURE_FAMILY_ID_SERIAL_NUMBER) {
}

seabreeze::api::SerialNumberFeatureFamily::~SerialNumberFeatureFamily() {
}

seabreeze::api::SpectrometerFeatureFamily::SpectrometerFeatureFamily()
	: FeatureFamily("Spectrometer", FEATURE_FAMILY_ID_SPECTROMETER) {
}

seabreeze::api::SpectrometerFeatureFamily::~SpectrometerFeatureFamily() {
}

seabreeze::api::ThermoElectricFeatureFamily::ThermoElectricFeatureFamily()
	: FeatureFamily("ThermoElectric", FEATURE_FAMILY_ID_THERMOELECTRIC) {
}

seabreeze::api::ThermoElectricFeatureFamily::~ThermoElectricFeatureFamily() {
}

seabreeze::api::IrradCalFeatureFamily::IrradCalFeatureFamily()
	: FeatureFamily("IrradianceCalibration", FEATURE_FAMILY_ID_IRRADCAL) {
}

seabreeze::api::IrradCalFeatureFamily::~IrradCalFeatureFamily() {
}

seabreeze::api::EthernetConfigurationFeatureFamily::EthernetConfigurationFeatureFamily()
	: FeatureFamily("EthernetConfiguration", FEATURE_FAMILY_ID_ETHERNET_CONFIGURATION) {
}

seabreeze::api::EthernetConfigurationFeatureFamily::~EthernetConfigurationFeatureFamily() {
}

seabreeze::api::MulticastFeatureFamily::MulticastFeatureFamily()
	: FeatureFamily("Multicast", FEATURE_FAMILY_ID_MULTICAST) {
}

seabreeze::api::MulticastFeatureFamily::~MulticastFeatureFamily() {
}

seabreeze::api::IPv4FeatureFamily::IPv4FeatureFamily()
	: FeatureFamily("IPv4", FEATURE_FAMILY_ID_IPV4) {
}

seabreeze::api::IPv4FeatureFamily::~IPv4FeatureFamily() {
}

seabreeze::api::WifiConfigurationFeatureFamily::WifiConfigurationFeatureFamily()
	: FeatureFamily("WifiConfiguration", FEATURE_FAMILY_ID_WIFI_CONFIGURATION) {
}

seabreeze::api::WifiConfigurationFeatureFamily::~WifiConfigurationFeatureFamily() {
}

seabreeze::api::DHCPServerFeatureFamily::DHCPServerFeatureFamily()
	: FeatureFamily("DHCP_Server", FEATURE_FAMILY_ID_DHCP_SERVER) {
}

seabreeze::api::DHCPServerFeatureFamily::~DHCPServerFeatureFamily() {
}

seabreeze::api::NetworkConfigurationFeatureFamily::NetworkConfigurationFeatureFamily()
	: FeatureFamily("NetworkConfiguration", FEATURE_FAMILY_ID_NETWORK_CONFIGURATION) {
}

seabreeze::api::NetworkConfigurationFeatureFamily::~NetworkConfigurationFeatureFamily() {
}

seabreeze::api::EEPROMFeatureFamily::EEPROMFeatureFamily()
	: FeatureFamily("EEPROM", FEATURE_FAMILY_ID_EEPROM) {
}

seabreeze::api::EEPROMFeatureFamily::~EEPROMFeatureFamily() {
}

seabreeze::api::LightSourceFeatureFamily::LightSourceFeatureFamily()
	: FeatureFamily("LightSource", FEATURE_FAMILY_ID_LIGHT_SOURCE) {
}

seabreeze::api::LightSourceFeatureFamily::~LightSourceFeatureFamily() {
}

seabreeze::api::StrobeLampFeatureFamily::StrobeLampFeatureFamily()
	: FeatureFamily("StrobeLampEnable", FEATURE_FAMILY_ID_STROBE_LAMP) {
}

seabreeze::api::StrobeLampFeatureFamily::~StrobeLampFeatureFamily() {
}

seabreeze::api::ContinuousStrobeFeatureFamily::ContinuousStrobeFeatureFamily()
	: FeatureFamily("ContinuousStrobe", FEATURE_FAMILY_ID_CONTINUOUS_STROBE) {
}

seabreeze::api::ContinuousStrobeFeatureFamily::~ContinuousStrobeFeatureFamily() {
}

seabreeze::api::ShutterFeatureFamily::ShutterFeatureFamily()
	: FeatureFamily("Shutter", FEATURE_FAMILY_ID_SHUTTER) {
}

seabreeze::api::ShutterFeatureFamily::~ShutterFeatureFamily() {
}

seabreeze::api::WaveCalFeatureFamily::WaveCalFeatureFamily()
	: FeatureFamily("WavelengthCalibration", FEATURE_FAMILY_ID_WAVECAL) {
}

seabreeze::api::WaveCalFeatureFamily::~WaveCalFeatureFamily() {
}

seabreeze::api::NonlinearityCoeffsFeatureFamily::NonlinearityCoeffsFeatureFamily()
	: FeatureFamily("NonlinearityCoeffs", FEATURE_FAMILY_ID_NONLINEARITYCAL) {
}

seabreeze::api::NonlinearityCoeffsFeatureFamily::~NonlinearityCoeffsFeatureFamily() {
}

seabreeze::api::StrayLightCoeffsFeatureFamily::StrayLightCoeffsFeatureFamily()
	: FeatureFamily("StrayLightCoeffs", FEATURE_FAMILY_ID_STRAYLIGHTCAL) {
}

seabreeze::api::StrayLightCoeffsFeatureFamily::~StrayLightCoeffsFeatureFamily() {
}

seabreeze::api::RawUSBBusAccessFeatureFamily::RawUSBBusAccessFeatureFamily()
	: FeatureFamily("RawUSBBusAccess", FEATURE_FAMILY_ID_RAW_USB_BUS_ACCESS) {
}

seabreeze::api::RawUSBBusAccessFeatureFamily::~RawUSBBusAccessFeatureFamily() {
}

seabreeze::api::TemperatureFeatureFamily::TemperatureFeatureFamily()
	: FeatureFamily("Temperature", FEATURE_FAMILY_ID_TEMPERATURE) {
}

seabreeze::api::TemperatureFeatureFamily::~TemperatureFeatureFamily() {
}

seabreeze::api::RevisionFeatureFamily::RevisionFeatureFamily()
	: FeatureFamily("Revision", FEATURE_FAMILY_ID_REVISION) {
}

seabreeze::api::RevisionFeatureFamily::~RevisionFeatureFamily() {
}

seabreeze::api::OpticalBenchFeatureFamily::OpticalBenchFeatureFamily()
	: FeatureFamily("OpticalBench", FEATURE_FAMILY_ID_OPTICAL_BENCH) {
}

seabreeze::api::OpticalBenchFeatureFamily::~OpticalBenchFeatureFamily() {
}

seabreeze::api::SpectrumProcessingFeatureFamily::SpectrumProcessingFeatureFamily()
	: FeatureFamily("SpectrumProcessing", FEATURE_FAMILY_ID_SPECTRUM_PROCESSING) {
}

seabreeze::api::SpectrumProcessingFeatureFamily::~SpectrumProcessingFeatureFamily() {
}

seabreeze::api::PixelBinningFeatureFamily::PixelBinningFeatureFamily()
	: FeatureFamily("PixelBinning", FEATURE_FAMILY_ID_PIXEL_BINNING) {
}

seabreeze::api::PixelBinningFeatureFamily::~PixelBinningFeatureFamily() {
}

seabreeze::api::AcquisitionDelayFeatureFamily::AcquisitionDelayFeatureFamily()
	: FeatureFamily("AcquisitionDelay", FEATURE_FAMILY_ID_ACQUISITION_DELAY) {
}

seabreeze::api::AcquisitionDelayFeatureFamily::~AcquisitionDelayFeatureFamily() {
}

seabreeze::api::DataBufferFeatureFamily::DataBufferFeatureFamily()
	: FeatureFamily("DataBuffer", FEATURE_FAMILY_ID_DATA_BUFFER) {
}

seabreeze::api::DataBufferFeatureFamily::~DataBufferFeatureFamily() {
}

seabreeze::api::IntrospectionFeatureFamily::IntrospectionFeatureFamily()
	: FeatureFamily("Introspection", FEATURE_FAMILY_ID_INTROSPECTION) {
}

seabreeze::api::IntrospectionFeatureFamily::~IntrospectionFeatureFamily() {
}

seabreeze::api::FastBufferFeatureFamily::FastBufferFeatureFamily()
	: FeatureFamily("FastBuffer", FEATURE_FAMILY_ID_FAST_BUFFER) {
}

seabreeze::api::FastBufferFeatureFamily::~FastBufferFeatureFamily() {
}

seabreeze::api::GPIOFeatureFamily::GPIOFeatureFamily()
	: FeatureFamily("GPIO", FEATURE_FAMILY_ID_GPIO) {
}

seabreeze::api::GPIOFeatureFamily::~GPIOFeatureFamily() {
}

seabreeze::api::I2CMasterFeatureFamily::I2CMasterFeatureFamily()
	: FeatureFamily("I2CMaster", FEATURE_FAMILY_ID_I2C_MASTER) {
}

seabreeze::api::I2CMasterFeatureFamily::~I2CMasterFeatureFamily() {
}

vector<FeatureFamily *> seabreeze::api::FeatureFamilies::getAllFeatureFamilies() {
	vector<FeatureFamily *> retval;

	/* This creates new instances of these so the class-wide fields do not risk
	 * having their const flags ignored.
	 */
	retval.push_back(new SerialNumberFeatureFamily());
	retval.push_back(new SpectrometerFeatureFamily());
	retval.push_back(new ThermoElectricFeatureFamily());
	retval.push_back(new IrradCalFeatureFamily());
	retval.push_back(new EthernetConfigurationFeatureFamily());
	retval.push_back(new MulticastFeatureFamily());
	retval.push_back(new IPv4FeatureFamily());
	retval.push_back(new WifiConfigurationFeatureFamily());
	retval.push_back(new DHCPServerFeatureFamily());
	retval.push_back(new NetworkConfigurationFeatureFamily());
	retval.push_back(new EEPROMFeatureFamily());
	retval.push_back(new StrobeLampFeatureFamily());
	retval.push_back(new ContinuousStrobeFeatureFamily());
	retval.push_back(new ShutterFeatureFamily());
	retval.push_back(new WaveCalFeatureFamily());
	retval.push_back(new NonlinearityCoeffsFeatureFamily());
	retval.push_back(new StrayLightCoeffsFeatureFamily());
	retval.push_back(new RawUSBBusAccessFeatureFamily());
	retval.push_back(new LightSourceFeatureFamily());
	retval.push_back(new TemperatureFeatureFamily());
	retval.push_back(new OpticalBenchFeatureFamily());
	retval.push_back(new SpectrumProcessingFeatureFamily());
	retval.push_back(new DataBufferFeatureFamily());
	retval.push_back(new AcquisitionDelayFeatureFamily());
	retval.push_back(new IntrospectionFeatureFamily());
	retval.push_back(new GPIOFeatureFamily());
	retval.push_back(new I2CMasterFeatureFamily());

	return retval;
}
