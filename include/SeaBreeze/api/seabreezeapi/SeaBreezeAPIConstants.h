/***************************************************/ /**
 * @file    SeaBreezeAPIConstants.h
 * @date    January 2015
 * @author  Ocean Optics, Inc.
 *
 * This file defines constants for use with SeaBreeze API
 * implementations.
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

/* Macros and constants */
#define SET_ERROR_CODE(code)    \
	do {                        \
		if(NULL != errorCode) { \
			*errorCode = code;  \
		}                       \
	} while(0)

#ifdef ERROR_SUCCESS
#undef ERROR_SUCCESS
#endif

/* Constants */
enum SEABREEZE_ERROR {
	ERROR_SUCCESS = 0,
	ERROR_INVALID_ERROR = 1,
	ERROR_NO_DEVICE = 2,
	ERROR_FAILED_TO_CLOSE = 3,
	ERROR_NOT_IMPLEMENTED = 4,
	ERROR_FEATURE_NOT_FOUND = 5,
	ERROR_TRANSFER_ERROR = 6,
	ERROR_BAD_USER_BUFFER = 7,
	ERROR_INPUT_OUT_OF_BOUNDS = 8,
	ERROR_SPECTROMETER_SATURATED = 9,
	ERROR_VALUE_NOT_FOUND = 10,
	ERROR_VALUE_NOT_EXPECTED = 11,
	ERROR_INVALID_TRIGGER_MODE = 12,
};
