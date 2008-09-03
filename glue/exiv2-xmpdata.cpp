/*
 * exiv2-xmpdata.cpp
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
#include "exiv2-xmpdata.h"
#include "exiv2-xmpdata-private.h"
#include "exiv2-xmpdatum-private.h"
#include "exiv2-xmpdatum-iterator-private.h"
#include "exiv2-xmpkey-private.h"
#include <exiv2/xmp.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2XmpData, exiv2_xmpdata, G_TYPE_OBJECT);

static void
exiv2_xmpdata_init (Exiv2XmpData *self)
{
	Exiv2XmpDataPrivate *priv;
	self->priv = priv = EXIV2_XMPDATA_GET_PRIVATE (self);
}

static void
exiv2_xmpdata_class_init (Exiv2XmpDataClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2XmpDataPrivate));
}

Exiv2XmpData*
exiv2_xmpdata_new ()
{
	Exiv2XmpData *xmpdata;
	xmpdata = EXIV2_XMPDATA (g_object_new (EXIV2_TYPE_XMPDATA, NULL));
	xmpdata->priv->data = new Exiv2::XmpData ();

	return xmpdata;	
}

long
exiv2_xmpdata_get_count (Exiv2XmpData *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), -1);
	return self->priv->data->count ();
}

gboolean
exiv2_xmpdata_get_isEmpty (Exiv2XmpData *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), true);
	return self->priv->data->empty ();
}

Exiv2XmpDatumIterator*
exiv2_xmpdata_begin (Exiv2XmpData *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), NULL);

	Exiv2XmpDatumIterator *datum;
	datum = EXIV2_XMPDATUMITERATOR (g_object_new (EXIV2_TYPE_XMPDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->begin ();

	return datum;
}

Exiv2XmpDatumIterator*
exiv2_xmpdata_end (Exiv2XmpData *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), NULL);

	Exiv2XmpDatumIterator *datum;
	datum = EXIV2_XMPDATUMITERATOR (g_object_new (EXIV2_TYPE_XMPDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->end ();

	return datum;
}

Exiv2XmpDatum*
exiv2_xmpdata_get_this	(Exiv2XmpData *self, const char *key)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), NULL);
	Exiv2XmpDatum *datum;
	datum = EXIV2_XMPDATUM (g_object_new (EXIV2_TYPE_XMPDATUM, NULL));
	Exiv2::XmpData* data = self->priv->data;
	Exiv2::Xmpdatum* edatum = &((*data) [key]);
	datum->priv->datum = edatum;

	return datum;
}

Exiv2XmpDatum*
exiv2_xmpdata_find_key	(Exiv2XmpData *self, Exiv2XmpKey* key)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATA (self), NULL);
	Exiv2XmpDatumIterator *iterator;
	iterator = EXIV2_XMPDATUMITERATOR (g_object_new (EXIV2_TYPE_XMPDATUMITERATOR, NULL));
	iterator->priv->iterator = self->priv->data->findKey (*(key->priv->key));

	return EXIV2_XMPDATUM(iterator);
}

void
exiv2_xmpdata_erase (Exiv2XmpData *self, Exiv2XmpKey* key)
{
	g_return_if_fail (EXIV2_IS_XMPDATA (self));
	self->priv->data->erase (self->priv->data->findKey (*(key->priv->key)));
}

G_END_DECLS
