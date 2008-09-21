/*
 * exiv2-databuf.h
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
#ifndef __EXIV2_DATABUF_H__
#define __EXIV2_DATABUF_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_DATABUF		(exiv2_databuf_get_type ())
#define EXIV2_DATABUF(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_DATABUF, Exiv2DataBuf))
#define EXIV2_IS_DATABUF(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_DATABUF))
#define EXIV2_DATABUF_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_DATABUF, Exiv2DataBufClass))
#define EXIV2_IS_DATABUF_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_DATABUF))
#define EXIV2_DATABUF_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_DATABUF, Exiv2DataBufClass))

#define EXIV2_DATABUF_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_DATABUF, Exiv2DataBufPrivate))

typedef struct _Exiv2DataBuf	Exiv2DataBuf;
typedef struct _Exiv2DataBufClass	Exiv2DataBufClass;
typedef struct _Exiv2DataBufPrivate Exiv2DataBufPrivate;

struct _Exiv2DataBuf
{
	GObject parent_instance;

	/*< private >*/
	Exiv2DataBufPrivate *priv;
};

struct _Exiv2DataBufClass
{
	GObjectClass parent_class;

};

GType 		exiv2_databuf_get_type		(void);

guint8*		exiv2_databuf_get_pData		(Exiv2DataBuf* self);
glong		exiv2_databuf_get_size		(Exiv2DataBuf* self);

G_END_DECLS

#endif /*  __EXIV2_DATABUF_H__ */
