/*
 * exiv2-exifdatum-iterator.cpp
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
#include "exiv2-exifdatum-iterator.h"
#include "exiv2-exifdatum-iterator-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifDatumIterator, exiv2_exifdatumiterator, EXIV2_TYPE_EXIFDATUM);

const char*	exiv2_exifdatumiterator_real_get_key 		(Exiv2ExifDatum *self);
guint16		exiv2_exifdatumiterator_real_get_tag		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatumiterator_real_get_typename	(Exiv2ExifDatum *self);
glong		exiv2_exifdatumiterator_real_get_count 		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatumiterator_real_toString 		(Exiv2ExifDatum *self);


static void
exiv2_exifdatumiterator_init (Exiv2ExifDatumIterator *self)
{
	Exiv2ExifDatumIteratorPrivate *priv;
	self->priv = priv = EXIV2_EXIFDATUMITERATOR_GET_PRIVATE (self);
}

static void
exiv2_exifdatumiterator_class_init (Exiv2ExifDatumIteratorClass *klass)
{
	Exiv2ExifDatumClass *exifdatum_class = EXIV2_EXIFDATUM_CLASS (klass);

	exifdatum_class->get_key = 		exiv2_exifdatumiterator_real_get_key;
	exifdatum_class->get_tag = 		exiv2_exifdatumiterator_real_get_tag;
	exifdatum_class->get_typename =		exiv2_exifdatumiterator_real_get_typename;
	exifdatum_class->get_count = 		exiv2_exifdatumiterator_real_get_count;
	exifdatum_class->toString = 		exiv2_exifdatumiterator_real_toString;

	g_type_class_add_private (klass, sizeof	(Exiv2ExifDatumIteratorPrivate));
}

void
exiv2_exifdatumiterator_next (Exiv2ExifDatumIterator *self)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self));

	self->priv->iterator = self->priv->iterator + 1;
}

gboolean
exiv2_exifdatumiterator_equals (Exiv2ExifDatumIterator *self, Exiv2ExifDatumIterator *other)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), false);
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (other), false);

	return self->priv->iterator == other->priv->iterator;
	
}

const char*
exiv2_exifdatumiterator_real_get_key (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), NULL);
	Exiv2ExifDatumIterator* iterator = EXIV2_EXIFDATUMITERATOR (self);
	return iterator->priv->iterator->key ().c_str ();
}

guint16
exiv2_exifdatumiterator_real_get_tag	(Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), -1);
	Exiv2ExifDatumIterator* iterator = EXIV2_EXIFDATUMITERATOR (self);
	return iterator->priv->iterator->tag ();	
}

const char*
exiv2_exifdatumiterator_real_get_typename (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), NULL);
	Exiv2ExifDatumIterator* iterator = EXIV2_EXIFDATUMITERATOR (self);
	return iterator->priv->iterator->typeName ();		
}

glong
exiv2_exifdatumiterator_real_get_count (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), -1);
	Exiv2ExifDatumIterator* iterator = EXIV2_EXIFDATUMITERATOR (self);
	return iterator->priv->iterator->count ();			
}

const char*
exiv2_exifdatumiterator_real_toString (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUMITERATOR (self), NULL);
	Exiv2ExifDatumIterator* iterator = EXIV2_EXIFDATUMITERATOR (self);
	return iterator->priv->iterator->toString ().c_str ();				
}

G_END_DECLS
