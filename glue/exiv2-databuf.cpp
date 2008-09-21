/*
 * exiv2-databuf.cpp
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
#include <glib-object.h>
#include "exiv2-databuf.h"
#include "exiv2-databuf-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2DataBuf, exiv2_databuf, G_TYPE_OBJECT);

static void
exiv2_databuf_init (Exiv2DataBuf *self)
{
	Exiv2DataBufPrivate *priv;
	self->priv = priv = EXIV2_DATABUF_GET_PRIVATE (self);

	/* Initialize members */
}

static void
exiv2_databuf_class_init (Exiv2DataBufClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2DataBufPrivate));
}

guint8*
exiv2_databuf_get_pData	(Exiv2DataBuf* self)
{
	g_return_val_if_fail (EXIV2_IS_DATABUF (self), NULL);
	return self->priv->buf.pData_;
}

glong
exiv2_databuf_get_size (Exiv2DataBuf* self)
{
	g_return_val_if_fail (EXIV2_IS_DATABUF (self), -1);
	return self->priv->buf.size_;	
}

G_END_DECLS