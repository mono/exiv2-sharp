/*
 * exiv2-exifthumb.h
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

#ifndef __EXIV2_EXIFTHUMB_H__
#define __EXIV2_EXIFTHUMB_H__

#include <glib-object.h>
#include "exiv2-databuf.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFTHUMB		(exiv2_exifthumb_get_type ())
#define EXIV2_EXIFTHUMB(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFTHUMB, Exiv2ExifThumb))
#define EXIV2_IS_EXIFTHUMB(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFTHUMB))
#define EXIV2_EXIFTHUMB_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFTHUMB, Exiv2ExifThumbClass))
#define EXIV2_IS_EXIFTHUMB_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFTHUMB))
#define EXIV2_EXIFTHUMB_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFTHUMB, Exiv2ExifThumbClass))

#define EXIV2_EXIFTHUMB_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_EXIFTHUMB, Exiv2ExifThumbPrivate))

typedef struct _Exiv2ExifThumb		Exiv2ExifThumb;
typedef struct _Exiv2ExifThumbClass	Exiv2ExifThumbClass;
typedef struct _Exiv2ExifThumbPrivate	Exiv2ExifThumbPrivate;

struct _Exiv2ExifThumb
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ExifThumbPrivate *priv;
};

struct _Exiv2ExifThumbClass
{
	GObjectClass parent_class;

};

GType			exiv2_exifthumb_get_type 	(void);

const char*		exiv2_exifthumb_get_mimeType	(Exiv2ExifThumb *self);
const char*		exiv2_exifthumb_get_extension	(Exiv2ExifThumb *self);
glong			exiv2_exifthumb_writeFile	(Exiv2ExifThumb *self, const char* path);
Exiv2DataBuf*		exiv2_exifthumb_copy		(Exiv2ExifThumb *self);
void			exiv2_exifthumb_jpegThumbnailPath (Exiv2ExifThumb *self, const char* path, GError **error);
void			exiv2_exifthumb_jpegThumbnailBuf (Exiv2ExifThumb *self, const guint8 *buf, glong n_buf);
void			exiv2_exifthumb_erase		(Exiv2ExifThumb *self);

G_END_DECLS

#endif /*  __EXIV2_EXIFTHUMB_H__ */
