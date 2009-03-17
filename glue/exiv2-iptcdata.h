/*
 * exiv2-iptcdata.h
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *	Mike Gemuende  (mike@gemuende.de)
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

#ifndef __EXIV2_IPTCDATA_H__
#define __EXIV2_IPTCDATA_H__

#include <glib-object.h>
#include "exiv2-iptcdatum-iterator.h"
#include "exiv2-iptckey.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_IPTCDATA		(exiv2_iptcdata_get_type ())
#define EXIV2_IPTCDATA(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IPTCDATA, Exiv2IptcData))
#define EXIV2_IS_IPTCDATA(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IPTCDATA))
#define EXIV2_IPTCDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IPTCDATA, Exiv2IptcDataClass))
#define EXIV2_IS_IPTCDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IPTCDATA))
#define EXIV2_IPTCDATA_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IPTCDATA, Exiv2IptcDataClass))

#define EXIV2_IPTCDATA_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_IPTCDATA, Exiv2IptcDataPrivate))

typedef struct _Exiv2IptcData		Exiv2IptcData;
typedef struct _Exiv2IptcDataClass	Exiv2IptcDataClass;
typedef struct _Exiv2IptcDataPrivate	Exiv2IptcDataPrivate;

struct _Exiv2IptcData
{
	GObject parent_instance;

	/*< private >*/
	Exiv2IptcDataPrivate *priv;
};

struct _Exiv2IptcDataClass
{
	GObjectClass parent_class;

};

GType			exiv2_iptcdata_get_type 	(void);

Exiv2IptcData*		exiv2_iptcdata_new		();
long			exiv2_iptcdata_get_count 	(Exiv2IptcData *self);
gboolean		exiv2_iptcdata_get_isEmpty	(Exiv2IptcData *self);

Exiv2IptcDatumIterator*	exiv2_iptcdata_begin		(Exiv2IptcData *self);
Exiv2IptcDatumIterator*	exiv2_iptcdata_end		(Exiv2IptcData *self);

Exiv2IptcDatum*		exiv2_iptcdata_get_this		(Exiv2IptcData *self, const char* key);

Exiv2IptcDatum*		exiv2_iptcdata_find_key		(Exiv2IptcData *self, Exiv2IptcKey* key);
void			exiv2_iptcdata_erase		(Exiv2IptcData *self, Exiv2IptcKey* key);

G_END_DECLS

#endif /*  __EXIV2_IPTCDATA_H__ */

