/*
 * exiv2-urational.cpp
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
#include "exiv2-urational.h"
#include "exiv2-urational-private.h"
#include "exiv2-databuf-private.h"
#include <exiv2/error.hpp>
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2URational, exiv2_urational, G_TYPE_OBJECT);

static void
exiv2_urational_init (Exiv2URational *self)
{
	Exiv2URationalPrivate *priv;
	self->priv = priv = EXIV2_URATIONAL_GET_PRIVATE (self);
}

static void
exiv2_urational_class_init (Exiv2URationalClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2URationalPrivate));
}

Exiv2URational*
exiv2_urational_new (guint32 numerator, guint32 denominator)
{
	Exiv2URational *urational;
	urational = EXIV2_URATIONAL (g_object_new (EXIV2_TYPE_URATIONAL, NULL));
	urational->priv->urational = Exiv2::URational (numerator, denominator);

	return urational;		
}

guint32
exiv2_urational_getNumerator	(Exiv2URational *self)
{
	g_return_val_if_fail (EXIV2_IS_URATIONAL (self), 0);
	return self->priv->urational.first;
}

void
exiv2_urational_setNumerator (Exiv2URational *self, guint32 numerator)
{
	g_return_if_fail (EXIV2_IS_URATIONAL (self));
	self->priv->urational.first = numerator;
}

guint32
exiv2_urational_getDenominator (Exiv2URational *self)
{
	g_return_val_if_fail (EXIV2_IS_URATIONAL (self), 0);
	return self->priv->urational.second;
}

void
exiv2_urational_setDenominator (Exiv2URational *self, guint32 denominator)
{
	g_return_if_fail (EXIV2_IS_URATIONAL (self));
	self->priv->urational.second = denominator;	
}



G_END_DECLS
