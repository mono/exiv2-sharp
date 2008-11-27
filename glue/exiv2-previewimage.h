/*
 * exiv2-previewimage.h
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
#ifndef __EXIV2_PREVIEWIMAGE_H__
#define __EXIV2_PREVIEWIMAGE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_PREVIEWIMAGE		(exiv2_previewimage_get_type ())
#define EXIV2_PREVIEWIMAGE(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_PREVIEWIMAGE, Exiv2PreviewImage))
#define EXIV2_IS_PREVIEWIMAGE(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_PREVIEWIMAGE))
#define EXIV2_PREVIEWIMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_PREVIEWIMAGE, Exiv2PreviewImageClass))
#define EXIV2_IS_PREVIEWIMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_PREVIEWIMAGE))
#define EXIV2_PREVIEWIMAGE_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_PREVIEWIMAGE, Exiv2PreviewImageClass))
#define EXIV2_PREVIEWIMAGE_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_PREVIEWIMAGE, Exiv2PreviewImagePrivate))

typedef struct _Exiv2PreviewImage		Exiv2PreviewImage;
typedef struct _Exiv2PreviewImageClass	Exiv2PreviewImageClass;
typedef struct _Exiv2PreviewImagePrivate	Exiv2PreviewImagePrivate;

struct _Exiv2PreviewImage
{
	GObject parent_instance;

	/*< private >*/
	Exiv2PreviewImagePrivate *priv;
};

struct _Exiv2PreviewImageClass
{
	GObjectClass parent_class;

};

GType 			exiv2_previewimage_get_type		(void);

const char*		exiv2_previewimage_get_mimeType		(Exiv2PreviewImage *self);
const char*		exiv2_previewimage_get_extension	(Exiv2PreviewImage *self);
guint32			exiv2_previewimage_get_size		(Exiv2PreviewImage *self);

G_END_DECLS

#endif /*  __EXIV2_PREVIEWIMAGE_H__ */
