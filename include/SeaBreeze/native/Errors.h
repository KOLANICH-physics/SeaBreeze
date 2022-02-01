#pragma once

/***************************************************/ /**
 * @file    Errors.h
 * @date    April 21, 2011
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
 ******************************************************/

enum OpenError {
	OPEN_OK = 0,
	NO_DEVICE_FOUND = -1,
	NO_DEVICE_MATCH = -2,
	CLAIM_INTERFACE_FAILED = -3,
};
enum CloseError {
	CLOSE_OK = 0,
	CLOSE_ERROR = -1,
};
enum WriteError {
	WRITE_FAILED = -1,
};
enum ReadError {
	READ_FAILED = -1,
};
enum AbortError {
	ABORT_OK = 0,
	ABORT_FAILED = -1,
};
enum ResetError {
	RESET_OK = 0,
	RESET_FAILED = -1,
};
