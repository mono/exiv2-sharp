/*
 * exiv2-iptcdata-private.h
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *	Mike Gemuende (mike@gemuende.de)
 *
 * Copyright (c) 2008-2009 Novell, Inc
 *
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef __EXIV2_IPTCDATA_PRIVATE_H__
#define __EXIV2_IPTCDATA_PRIVATE_H__

#include "exiv2-iptcdata.h"
#include <exiv2/iptc.hpp>

G_BEGIN_DECLS

struct _Exiv2IptcDataPrivate
{
	Exiv2::IptcData* data;
};

G_END_DECLS

#endif /* __EXIV2_IPTCDATA_PRIVATE_H__ */

