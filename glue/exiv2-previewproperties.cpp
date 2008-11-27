/*
 * exiv2-previewproperties.cpp
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
#include <exiv2/preview.hpp>
#include "exiv2-previewproperties.h"
#include "exiv2-previewproperties-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2PreviewProperties, exiv2_previewproperties, G_TYPE_OBJECT);

static void
exiv2_previewproperties_init (Exiv2PreviewProperties *self)
{
	Exiv2PreviewPropertiesPrivate *priv;
	self->priv = priv = EXIV2_PREVIEWPROPERTIES_GET_PRIVATE (self);

	/* Initialize members */
}

static void
exiv2_previewproperties_class_init (Exiv2PreviewPropertiesClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2PreviewPropertiesPrivate));
}

const char*
exiv2_previewproperties_get_mimeType (Exiv2PreviewProperties *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWPROPERTIES (self), NULL);

	return self->priv->prop->mimeType_.c_str();
}

const char*
exiv2_previewproperties_get_extension (Exiv2PreviewProperties *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWPROPERTIES (self), NULL);

	return self->priv->prop->extension_.c_str();
	
}

guint32
exiv2_previewproperties_get_size (Exiv2PreviewProperties *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWPROPERTIES (self), 0);

	return self->priv->prop->size_;
}
guint32
exiv2_previewproperties_get_width (Exiv2PreviewProperties *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWPROPERTIES (self), 0);

	return self->priv->prop->width_;
}
guint32
exiv2_previewproperties_get_height (Exiv2PreviewProperties *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWPROPERTIES (self), 0);

	return self->priv->prop->height_;
}

G_END_DECLS
