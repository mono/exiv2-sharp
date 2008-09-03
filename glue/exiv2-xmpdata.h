/*
 * exiv2-xmpdata.h
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell
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

#ifndef __EXIV2_XMPDATA_H__
#define __EXIV2_XMPDATA_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_XMPDATA		(exiv2_xmpdata_get_type ())
#define EXIV2_XMPDATA(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_XMPDATA, Exiv2XmpData))
#define EXIV2_IS_XMPDATA(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_XMPDATA))
#define EXIV2_XMPDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_XMPDATA, Exiv2XmpDataClass))
#define EXIV2_IS_XMPDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_XMPDATA))
#define EXIV2_XMPDATA_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_XMPDATA, Exiv2XmpDataClass))

#define EXIV2_XMPDATA_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_XMPDATA, Exiv2XmpDataPrivate))

typedef struct _Exiv2XmpData		Exiv2XmpData;
typedef struct _Exiv2XmpDataClass	Exiv2XmpDataClass;
typedef struct _Exiv2XmpDataPrivate	Exiv2XmpDataPrivate;

struct _Exiv2XmpData
{
	GObject parent_instance;

	/*< private >*/
	Exiv2XmpDataPrivate *priv;
};

struct _Exiv2XmpDataClass
{
	GObjectClass parent_class;

};

GType			exiv2_xmpdata_get_type 	(void);

Exiv2XmpData*		exiv2_xmpdata_new		();
long			exiv2_xmpdata_get_count 	(Exiv2XmpData *self);
gboolean		exiv2_xmpdata_get_isEmpty	(Exiv2XmpData *self);

//Exiv2ExifDatumIterator*	exiv2_xmpdata_begin		(Exiv2XmpData *self);
//Exiv2ExifDatumIterator*	exiv2_xmpdata_end		(Exiv2XmpData *self);
//
//Exiv2ExifDatum*		exiv2_xmpdata_get_this		(Exiv2XmpData *self, const char* key);
//
//Exiv2ExifDatum*		exiv2_xmpdata_find_key		(Exiv2XmpData *self, Exiv2ExifKey* key);
//void			exiv2_xmpdata_erase		(Exiv2XmpData *self, Exiv2ExifKey* key);

G_END_DECLS

#endif /*  __EXIV2_XMPDATA_H__ */
