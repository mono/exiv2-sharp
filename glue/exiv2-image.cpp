/*
 * exiv2-image.cpp
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
#include <glib-object.h>
#include <exiv2/image.hpp>
#include <exiv2/preview.hpp>
#include "exiv2-image.h"
#include "exiv2-image-private.h"
#include "exiv2-exifdata-private.h"
#include "exiv2-xmpdata-private.h"
#include "exiv2-iptcdata-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2Image, exiv2_image, G_TYPE_OBJECT);

static void
exiv2_image_init (Exiv2Image *self)
{
	Exiv2ImagePrivate *priv;
	self->priv = priv = EXIV2_IMAGE_GET_PRIVATE (self);

	/* Initialize members */
}

static void
exiv2_image_class_init (Exiv2ImageClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2ImagePrivate));
}

void
exiv2_image_readMetadata (Exiv2Image *self, GError **error)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));
	try {
		self->priv->imptr->readMetadata ();
	} catch (Exiv2::Error e) {
		g_set_error (error, g_quark_from_string ("Exiv2"), e.code (), e.what ());	
	}
}

void
exiv2_image_writeMetadata (Exiv2Image *self, GError **error)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));
	try {
		self->priv->imptr->writeMetadata ();
	} catch (Exiv2::Error e) {
		g_set_error (error, g_quark_from_string ("Exiv2"), e.code (), e.what ());	
	}
}

void
exiv2_image_clearMetadata (Exiv2Image *self)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));
	self->priv->imptr->clearMetadata ();	
}

gboolean
exiv2_image_get_good (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), false);
	return self->priv->imptr->good ();
}

const char*
exiv2_image_get_mimeType (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), NULL);
	return self->priv->imptr->mimeType ().c_str ();	
}

int
exiv2_image_get_pixelWidth (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), -1);
	return self->priv->imptr->pixelWidth ();	
}

int
exiv2_image_get_pixelHeight (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), -1);
	return self->priv->imptr->pixelHeight ();	
}

const char*
exiv2_image_get_comment (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), NULL);
	return self->priv->imptr->comment ().c_str ();	
}

void exiv2_image_set_comment (Exiv2Image *self, const char* comment)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));
	self->priv->imptr->setComment (comment);
}

void exiv2_image_clear_comment (Exiv2Image *self)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));
	self->priv->imptr->clearComment ();	
}

Exiv2ExifData*
exiv2_image_get_exifData (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), NULL);

	Exiv2ExifData *exifdata;
	exifdata = EXIV2_EXIFDATA (g_object_new (EXIV2_TYPE_EXIFDATA, NULL));
	exifdata->priv->data = &(self->priv->imptr->exifData ());

	return exifdata;
}

void
exiv2_image_set_exifData (Exiv2Image *self, Exiv2ExifData *data)
{
	g_return_if_fail (EXIV2_IS_IMAGE (self));

	self->priv->imptr->setExifData (*(data->priv->data));
}

Exiv2XmpData*
exiv2_image_get_xmpData (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), NULL);

	Exiv2XmpData *xmpdata;
	xmpdata = EXIV2_XMPDATA (g_object_new (EXIV2_TYPE_XMPDATA, NULL));
	xmpdata->priv->data = &(self->priv->imptr->xmpData ());

	return xmpdata;
}

Exiv2IptcData*
exiv2_image_get_iptcData		(Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), NULL);

	Exiv2IptcData *iptcdata;
	iptcdata = EXIV2_IPTCDATA (g_object_new (EXIV2_TYPE_IPTCDATA, NULL));
	iptcdata->priv->data = &(self->priv->imptr->iptcData ());

	return iptcdata;
}

G_END_DECLS
