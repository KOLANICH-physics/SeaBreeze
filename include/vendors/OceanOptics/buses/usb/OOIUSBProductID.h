/***************************************************/ /**
 * @file    OOIUSBProductID.h
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

#ifndef OOIUSBPRODUCTID_H
#define OOIUSBPRODUCTID_H

enum OOIUSBPRODUCTID {
	USB2000_USB_PID = 0x1002,
	HR2000_USB_PID = 0x100a,
	HR4000_USB_PID = 0x1012,
	HR2000PLUS_USB_PID = 0x1016,
	QE65000_USB_PID = 0x1018,
	USB2000PLUS_USB_PID = 0x101E,
	USB4000_USB_PID = 0x1022,
	NIRQUEST512_USB_PID = 0x1026,
	NIRQUEST256_USB_PID = 0x1028,
	MAYA2000PRO_USB_PID = 0x102a,
	MAYA2000_USB_PID = 0x102c,
	MAYALSL_USB_PID = 0x1046,
	TORUS_USB_PID = 0x1040,
	APEX_USB_PID = 0x1044,
	FLAMENIR_USB_PID = 0x104b,
	JAZ_USB_PID = 0x2000,
	FLAMEX_USB_PID = 0x2001,
	STS_USB_PID = 0x4000,
	QEPRO_USB_PID = 0x4004,
	SPARK_USB_PID = 0x4200,
	VENTANA_USB_PID = 0x5000,
	GENERIC_SMARTPHONE_MODULE_PID = 0x7002,
};

#endif /* OOIUSBPRODUCTID_H */
