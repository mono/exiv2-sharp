/*
 * exiv2-xmpdatum-iterator.cpp
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
#include "exiv2-xmpdatum-iterator.h"
#include "exiv2-xmpdatum-iterator-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2XmpDatumIterator, exiv2_xmpdatumiterator, EXIV2_TYPE_XMPDATUM);

//const char*	exiv2_xmpdatumiterator_real_get_key 		(Exiv2XmpDatum *self);
//guint16		exiv2_xmpdatumiterator_real_get_tag		(Exiv2XmpDatum *self);
//const char*	exiv2_xmpdatumiterator_real_get_typename	(Exiv2XmpDatum *self);
//glong		exiv2_xmpdatumiterator_real_get_count 		(Exiv2XmpDatum *self);
const char*	exiv2_xmpdatumiterator_real_toString 		(Exiv2XmpDatum *self);


static void
exiv2_xmpdatumiterator_init (Exiv2XmpDatumIterator *self)
{
	Exiv2XmpDatumIteratorPrivate *priv;
	self->priv = priv = EXIV2_XMPDATUMITERATOR_GET_PRIVATE (self);
}

static void
exiv2_xmpdatumiterator_class_init (Exiv2XmpDatumIteratorClass *klass)
{
	Exiv2XmpDatumClass *xmpdatum_class = EXIV2_XMPDATUM_CLASS (klass);

//	xmpdatum_class->get_key = 		exiv2_xmpdatumiterator_real_get_key;
//	xmpdatum_class->get_tag = 		exiv2_xmpdatumiterator_real_get_tag;
//	xmpdatum_class->get_typename =		exiv2_xmpdatumiterator_real_get_typename;
//	xmpdatum_class->get_count = 		exiv2_xmpdatumiterator_real_get_count;
	xmpdatum_class->toString = 		exiv2_xmpdatumiterator_real_toString;

	g_type_class_add_private (klass, sizeof	(Exiv2XmpDatumIteratorPrivate));
}

void
exiv2_xmpdatumiterator_next (Exiv2XmpDatumIterator *self)
{
	g_return_if_fail (EXIV2_IS_XMPDATUMITERATOR (self));

	self->priv->iterator = self->priv->iterator + 1;
}

gboolean
exiv2_xmpdatumiterator_equals (Exiv2XmpDatumIterator *self, Exiv2XmpDatumIterator *other)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), false);
	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (other), false);

	return self->priv->iterator == other->priv->iterator;
	
}

//const char*
//exiv2_xmpdatumiterator_real_get_key (Exiv2XmpDatum *self)
//{
//	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), NULL);
//	Exiv2XmpDatumIterator* iterator = EXIV2_XMPDATUMITERATOR (self);
//	return iterator->priv->iterator->key ().c_str ();
//}
//
//guint16
//exiv2_xmpdatumiterator_real_get_tag	(Exiv2XmpDatum *self)
//{
//	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), -1);
//	Exiv2XmpDatumIterator* iterator = EXIV2_XMPDATUMITERATOR (self);
//	return iterator->priv->iterator->tag ();	
//}
//
//const char*
//exiv2_xmpdatumiterator_real_get_typename (Exiv2XmpDatum *self)
//{
//	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), NULL);
//	Exiv2XmpDatumIterator* iterator = EXIV2_XMPDATUMITERATOR (self);
//	return iterator->priv->iterator->typeName ();		
//}
//
//glong
//exiv2_xmpdatumiterator_real_get_count (Exiv2XmpDatum *self)
//{
//	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), -1);
//	Exiv2XmpDatumIterator* iterator = EXIV2_XMPDATUMITERATOR (self);
//	return iterator->priv->iterator->count ();			
//}

const char*
exiv2_xmpdatumiterator_real_toString (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUMITERATOR (self), NULL);
	Exiv2XmpDatumIterator* iterator = EXIV2_XMPDATUMITERATOR (self);
	return iterator->priv->iterator->toString ().c_str ();				
}

G_END_DECLS
