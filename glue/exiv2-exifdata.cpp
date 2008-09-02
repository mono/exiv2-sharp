/*
 * exiv2-exifdata.cpp
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#include "exiv2-exifdata.h"
#include "exiv2-exifdata-private.h"
#include "exiv2-exifdatum-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifData, exiv2_exifdata, G_TYPE_OBJECT);

static void
exiv2_exifdata_init (Exiv2ExifData *self)
{
	Exiv2ExifDataPrivate *priv;
	self->priv = priv = EXIV2_EXIFDATA_GET_PRIVATE (self);
}

static void
exiv2_exifdata_class_init (Exiv2ExifDataClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2ExifDataPrivate));
}

long
exiv2_exifdata_get_count (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), -1);
	return self->priv->data->count ();
}

gboolean
exiv2_exifdata_get_isEmpty (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), true);
	return self->priv->data->empty ();
}

Exiv2ExifDatum*
exiv2_exifdata_begin (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);

	Exiv2ExifDatum *datum;
	datum = EXIV2_EXIFDATUM (g_object_new (EXIV2_TYPE_EXIFDATUM, NULL));
	datum->priv->iterator = self->priv->data->begin ();

	return datum;
}

Exiv2ExifDatum*
exiv2_exifdata_end (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);

	Exiv2ExifDatum *datum;
	datum = EXIV2_EXIFDATUM (g_object_new (EXIV2_TYPE_EXIFDATUM, NULL));
	datum->priv->iterator = self->priv->data->end ();

	return datum;
}

G_END_DECLS
