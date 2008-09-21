/*
 * exiv2-image.h
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
#ifndef __EXIV2_IMAGE_H__
#define __EXIV2_IMAGE_H__

#include <glib-object.h>
#include "exiv2-exifdata.h"
#include "exiv2-xmpdata.h"


G_BEGIN_DECLS

#define EXIV2_TYPE_IMAGE		(exiv2_image_get_type ())
#define EXIV2_IMAGE(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IMAGE, Exiv2Image))
#define EXIV2_IS_IMAGE(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IMAGE))
#define EXIV2_IMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IMAGE, Exiv2ImageClass))
#define EXIV2_IS_IMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IMAGE))
#define EXIV2_IMAGE_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IMAGE, Exiv2ImageClass))

#define EXIV2_IMAGE_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_IMAGE, Exiv2ImagePrivate))

typedef struct _Exiv2Image	Exiv2Image;
typedef struct _Exiv2ImageClass	Exiv2ImageClass;
typedef struct _Exiv2ImagePrivate Exiv2ImagePrivate;

struct _Exiv2Image
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ImagePrivate *priv;
};

struct _Exiv2ImageClass
{
	GObjectClass parent_class;

};

GType 		exiv2_image_get_type		(void);

void		exiv2_image_readMetadata	(Exiv2Image *self, GError **error);
void		exiv2_image_writeMetadata	(Exiv2Image *self, GError **error);
void		exiv2_image_clearMetadata	(Exiv2Image *self);

gboolean	exiv2_image_get_good		(Exiv2Image *self);
const char*	exiv2_image_get_mimeType	(Exiv2Image *self);
int		exiv2_image_get_pixelWidth	(Exiv2Image *self);
int		exiv2_image_get_pixelHeight	(Exiv2Image *self);
const char*	exiv2_image_get_comment		(Exiv2Image *self);
void		exiv2_image_set_comment		(Exiv2Image *self, const char* comment);
void		exiv2_image_clear_comment	(Exiv2Image *self);
int		exiv2_image_get_pixelHeight	(Exiv2Image *self);
Exiv2ExifData*	exiv2_image_get_exifData	(Exiv2Image *self);
void		exiv2_image_set_exifData	(Exiv2Image *self, Exiv2ExifData *data);
Exiv2XmpData*	exiv2_image_get_xmpData		(Exiv2Image *self);

G_END_DECLS

#endif /*  __EXIV2_IMAGE_H__ */
