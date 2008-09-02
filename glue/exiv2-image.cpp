/*
 * exiv2-image.cpp
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#include <glib-object.h>
#include <exiv2/image.hpp>
#include "exiv2-image.h"
#include "exiv2-image-private.h"
#include "exiv2-exifdata.h"
#include "exiv2-exifdata-private.h"

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

gboolean
exiv2_image_get_good (Exiv2Image *self)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (self), false);
	return self->priv->imptr->good ();
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

G_END_DECLS
