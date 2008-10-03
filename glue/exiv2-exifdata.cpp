/*
 * exiv2-exifdata.cpp
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
#include "exiv2-exifdata.h"
#include "exiv2-exifkey-private.h"
#include "exiv2-exifdata-private.h"
#include "exiv2-exifdatum-private.h"
#include "exiv2-exifdatum-iterator-private.h"
#include "exiv2-exifthumb-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifData, exiv2_exifdata, G_TYPE_OBJECT);

static void exiv2_exifdata_finalize (GObject *gobject);

static void
exiv2_exifdata_init (Exiv2ExifData *self)
{
	Exiv2ExifDataPrivate *priv;
	self->priv = priv = EXIV2_EXIFDATA_GET_PRIVATE (self);
	priv->data = NULL;
}

static void
exiv2_exifdata_class_init (Exiv2ExifDataClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_exifdata_finalize;

	g_type_class_add_private (klass, sizeof	(Exiv2ExifDataPrivate));
}

static void
exiv2_exifdata_finalize (GObject *gobject)
{
	Exiv2ExifData *self = EXIV2_EXIFDATA (gobject);
	if (self->priv->data) {
		delete self->priv->data;
		self->priv->data = NULL;
	}
	G_OBJECT_CLASS (exiv2_exifdata_parent_class)->finalize (gobject);
}

Exiv2ExifData*
exiv2_exifdata_new ()
{
	Exiv2ExifData *exifdata;
	exifdata = EXIV2_EXIFDATA (g_object_new (EXIV2_TYPE_EXIFDATA, NULL));
	exifdata->priv->data = new Exiv2::ExifData ();

	return exifdata;	
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

Exiv2ExifDatumIterator*
exiv2_exifdata_begin (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);

	Exiv2ExifDatumIterator *datum;
	datum = EXIV2_EXIFDATUMITERATOR (g_object_new (EXIV2_TYPE_EXIFDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->begin ();

	return datum;
}

Exiv2ExifDatumIterator*
exiv2_exifdata_end (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);

	Exiv2ExifDatumIterator *datum;
	datum = EXIV2_EXIFDATUMITERATOR (g_object_new (EXIV2_TYPE_EXIFDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->end ();

	return datum;
}

Exiv2ExifDatum*
exiv2_exifdata_get_this	(Exiv2ExifData *self, const char *key)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);
	Exiv2ExifDatum *datum;
	datum = EXIV2_EXIFDATUM (g_object_new (EXIV2_TYPE_EXIFDATUM, NULL));
	Exiv2::ExifData* data = self->priv->data;
	Exiv2::Exifdatum* edatum = &((*data) [key]);
	datum->priv->datum = edatum;

	return datum;
}

Exiv2ExifDatum*
exiv2_exifdata_find_key	(Exiv2ExifData *self, Exiv2ExifKey* key)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);
	Exiv2ExifDatumIterator *iterator;
	iterator = EXIV2_EXIFDATUMITERATOR (g_object_new (EXIV2_TYPE_EXIFDATUMITERATOR, NULL));
	iterator->priv->iterator = self->priv->data->findKey (*(key->priv->key));

	return EXIV2_EXIFDATUM(iterator);
}

void
exiv2_exifdata_erase (Exiv2ExifData *self, Exiv2ExifKey* key)
{
	g_return_if_fail (EXIV2_IS_EXIFDATA (self));
	self->priv->data->erase (self->priv->data->findKey (*(key->priv->key)));
}

Exiv2ExifThumb*
exiv2_exifdata_get_thumb (Exiv2ExifData *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATA (self), NULL);
	Exiv2ExifThumb *thumb;
	thumb = EXIV2_EXIFTHUMB (g_object_new (EXIV2_TYPE_EXIFTHUMB, NULL));
	thumb->priv->thumb = new Exiv2::ExifThumb (*(self->priv->data)); 

	return thumb;
}

G_END_DECLS
