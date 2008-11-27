/*
 * exiv2-exifdata.h
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell, Inc
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

#ifndef __EXIV2_EXIFDATA_H__
#define __EXIV2_EXIFDATA_H__

#include <glib-object.h>
#include "exiv2-exifkey.h"
#include "exiv2-exifdatum.h"
#include "exiv2-exifdatum-iterator.h"
#include "exiv2-exifthumb.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFDATA		(exiv2_exifdata_get_type ())
#define EXIV2_EXIFDATA(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifData))
#define EXIV2_IS_EXIFDATA(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFDATA))
#define EXIV2_EXIFDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataClass))
#define EXIV2_IS_EXIFDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFDATA))
#define EXIV2_EXIFDATA_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataClass))

#define EXIV2_EXIFDATA_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataPrivate))

typedef struct _Exiv2ExifData		Exiv2ExifData;
typedef struct _Exiv2ExifDataClass	Exiv2ExifDataClass;
typedef struct _Exiv2ExifDataPrivate	Exiv2ExifDataPrivate;

struct _Exiv2ExifData
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ExifDataPrivate *priv;
};

struct _Exiv2ExifDataClass
{
	GObjectClass parent_class;

};

GType			exiv2_exifdata_get_type 	(void);

Exiv2ExifData*		exiv2_exifdata_new		();
long			exiv2_exifdata_get_count 	(Exiv2ExifData *self);
gboolean		exiv2_exifdata_get_isEmpty	(Exiv2ExifData *self);

Exiv2ExifDatumIterator*	exiv2_exifdata_begin		(Exiv2ExifData *self);
Exiv2ExifDatumIterator*	exiv2_exifdata_end		(Exiv2ExifData *self);

Exiv2ExifDatum*		exiv2_exifdata_get_this		(Exiv2ExifData *self, const char* key);

Exiv2ExifDatum*		exiv2_exifdata_find_key		(Exiv2ExifData *self, Exiv2ExifKey* key);
void			exiv2_exifdata_erase		(Exiv2ExifData *self, Exiv2ExifKey* key);

Exiv2ExifThumb*		exiv2_exifdata_get_thumb	(Exiv2ExifData *self);

G_END_DECLS

#endif /*  __EXIV2_EXIFDATA_H__ */
