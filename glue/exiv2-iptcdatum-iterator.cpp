/*
 * exiv2-iptcdatum-iterator.cpp
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
#include "exiv2-iptcdatum-iterator.h"
#include "exiv2-iptcdatum-iterator-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2IptcDatumIterator, exiv2_iptcdatumiterator, EXIV2_TYPE_IPTCDATUM);

const char*	exiv2_iptcdatumiterator_real_get_key 		(Exiv2IptcDatum *self);
guint16		exiv2_iptcdatumiterator_real_get_tag		(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatumiterator_real_get_typename	(Exiv2IptcDatum *self);
glong		exiv2_iptcdatumiterator_real_get_count 		(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatumiterator_real_toString 		(Exiv2IptcDatum *self);


static void
exiv2_iptcdatumiterator_init (Exiv2IptcDatumIterator *self)
{
	Exiv2IptcDatumIteratorPrivate *priv;
	self->priv = priv = EXIV2_IPTCDATUMITERATOR_GET_PRIVATE (self);
}

static void
exiv2_iptcdatumiterator_class_init (Exiv2IptcDatumIteratorClass *klass)
{
	Exiv2IptcDatumClass *iptcdatum_class = EXIV2_IPTCDATUM_CLASS (klass);

	iptcdatum_class->get_key = 		exiv2_iptcdatumiterator_real_get_key;
	iptcdatum_class->get_tag = 		exiv2_iptcdatumiterator_real_get_tag;
	iptcdatum_class->get_typename =		exiv2_iptcdatumiterator_real_get_typename;
	iptcdatum_class->get_count = 		exiv2_iptcdatumiterator_real_get_count;
	iptcdatum_class->toString = 		exiv2_iptcdatumiterator_real_toString;

	g_type_class_add_private (klass, sizeof	(Exiv2IptcDatumIteratorPrivate));
}

void
exiv2_iptcdatumiterator_next (Exiv2IptcDatumIterator *self)
{
	g_return_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self));

	self->priv->iterator = self->priv->iterator + 1;
}

gboolean
exiv2_iptcdatumiterator_equals (Exiv2IptcDatumIterator *self, Exiv2IptcDatumIterator *other)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), false);
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (other), false);

	return self->priv->iterator == other->priv->iterator;
	
}

const char*
exiv2_iptcdatumiterator_real_get_key (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), NULL);
	Exiv2IptcDatumIterator* iterator = EXIV2_IPTCDATUMITERATOR (self);
	return iterator->priv->iterator->key ().c_str ();
}

guint16
exiv2_iptcdatumiterator_real_get_tag	(Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), -1);
	Exiv2IptcDatumIterator* iterator = EXIV2_IPTCDATUMITERATOR (self);
	return iterator->priv->iterator->tag ();	
}

const char*
exiv2_iptcdatumiterator_real_get_typename (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), NULL);
	Exiv2IptcDatumIterator* iterator = EXIV2_IPTCDATUMITERATOR (self);
	return iterator->priv->iterator->typeName ();		
}

glong
exiv2_iptcdatumiterator_real_get_count (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), -1);
	Exiv2IptcDatumIterator* iterator = EXIV2_IPTCDATUMITERATOR (self);
	return iterator->priv->iterator->count ();			
}

const char*
exiv2_iptcdatumiterator_real_toString (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUMITERATOR (self), NULL);
	Exiv2IptcDatumIterator* iterator = EXIV2_IPTCDATUMITERATOR (self);
	return iterator->priv->iterator->toString ().c_str ();				
}

G_END_DECLS
