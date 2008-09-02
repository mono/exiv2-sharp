/*
 * exiv2-exifdatum.cpp
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#include "exiv2-exifdatum.h"
#include "exiv2-exifdatum-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifDatum, exiv2_exifdatum, G_TYPE_OBJECT);

static void
exiv2_exifdatum_init (Exiv2ExifDatum *self)
{
	Exiv2ExifDatumPrivate *priv;
	self->priv = priv = EXIV2_EXIFDATUM_GET_PRIVATE (self);
}

static void
exiv2_exifdatum_class_init (Exiv2ExifDatumClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2ExifDatumPrivate));
}

void
exiv2_exifdatum_next (Exiv2ExifDatum *self)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));

	self->priv->iterator = self->priv->iterator + 1;
}

const char*
exiv2_exifdatum_get_key	(Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->iterator->key ().c_str ();
}

guint16
exiv2_exifdatum_get_tag	(Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), -1);
	return self->priv->iterator->tag ();	
}

const char*
exiv2_exifdatum_get_typename (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->iterator->typeName ();		
}

glong
exiv2_exifdatum_get_count (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), -1);
	return self->priv->iterator->count ();			
}

const char*
exiv2_exifdatum_toString (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->iterator->toString ().c_str ();				
}

gboolean
exiv2_exifdatum_equals (Exiv2ExifDatum *self, Exiv2ExifDatum *other)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), false);
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (other), false);

	return self->priv->iterator == other->priv->iterator;
	
}

G_END_DECLS
