/*
 * exiv2-iptcdata.cpp
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *	Mike Gemuende (mike@gemuende.de)
 *
 * Copyright (c) 2008-2009 Novell, Inc
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
#include "exiv2-iptcdata.h"
#include "exiv2-iptcdata-private.h"
#include "exiv2-iptcdatum-private.h"
#include "exiv2-iptcdatum-iterator-private.h"
#include "exiv2-iptckey-private.h"
#include <exiv2/iptc.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2IptcData, exiv2_iptcdata, G_TYPE_OBJECT);

static void exiv2_iptcdata_finalize (GObject *gobject);

static void
exiv2_iptcdata_init (Exiv2IptcData *self)
{
	Exiv2IptcDataPrivate *priv;
	self->priv = priv = EXIV2_IPTCDATA_GET_PRIVATE (self);
}

static void
exiv2_iptcdata_class_init (Exiv2IptcDataClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_iptcdata_finalize;

	g_type_class_add_private (klass, sizeof	(Exiv2IptcDataPrivate));
}

static void
exiv2_iptcdata_finalize (GObject *gobject)
{
	Exiv2IptcData *self = EXIV2_IPTCDATA (gobject);
	if (self->priv->data) {
		delete self->priv->data;
		self->priv->data = NULL;
	}
	G_OBJECT_CLASS (exiv2_iptcdata_parent_class)->finalize (gobject);
}

Exiv2IptcData*
exiv2_iptcdata_new ()
{
	Exiv2IptcData *iptcdata;
	iptcdata = EXIV2_IPTCDATA (g_object_new (EXIV2_TYPE_IPTCDATA, NULL));
	iptcdata->priv->data = new Exiv2::IptcData ();

	return iptcdata;	
}

long
exiv2_iptcdata_get_count (Exiv2IptcData *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), -1);
	return self->priv->data->count ();
}

gboolean
exiv2_iptcdata_get_isEmpty (Exiv2IptcData *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), true);
	return self->priv->data->empty ();
}

Exiv2IptcDatumIterator*
exiv2_iptcdata_begin (Exiv2IptcData *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), NULL);

	Exiv2IptcDatumIterator *datum;
	datum = EXIV2_IPTCDATUMITERATOR (g_object_new (EXIV2_TYPE_IPTCDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->begin ();

	return datum;
}

Exiv2IptcDatumIterator*
exiv2_iptcdata_end (Exiv2IptcData *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), NULL);

	Exiv2IptcDatumIterator *datum;
	datum = EXIV2_IPTCDATUMITERATOR (g_object_new (EXIV2_TYPE_IPTCDATUMITERATOR, NULL));
	datum->priv->iterator = self->priv->data->end ();

	return datum;
}

Exiv2IptcDatum*
exiv2_iptcdata_get_this	(Exiv2IptcData *self, const char *key)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), NULL);
	Exiv2IptcDatum *datum;
	datum = EXIV2_IPTCDATUM (g_object_new (EXIV2_TYPE_IPTCDATUM, NULL));
	Exiv2::IptcData* data = self->priv->data;
	Exiv2::Iptcdatum* edatum = &((*data) [key]);
	datum->priv->datum = edatum;

	return datum;
}

Exiv2IptcDatum*
exiv2_iptcdata_find_key	(Exiv2IptcData *self, Exiv2IptcKey* key)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATA (self), NULL);
	Exiv2IptcDatumIterator *iterator;
	iterator = EXIV2_IPTCDATUMITERATOR (g_object_new (EXIV2_TYPE_IPTCDATUMITERATOR, NULL));
	iterator->priv->iterator = self->priv->data->findKey (*(key->priv->key));

	return EXIV2_IPTCDATUM(iterator);
}

void
exiv2_iptcdata_erase (Exiv2IptcData *self, Exiv2IptcKey* key)
{
	g_return_if_fail (EXIV2_IS_IPTCDATA (self));
	self->priv->data->erase (self->priv->data->findKey (*(key->priv->key)));
}

G_END_DECLS

