/*
 * exiv2-rational.cpp
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
#include "exiv2-rational.h"
#include "exiv2-rational-private.h"
#include "exiv2-databuf-private.h"
#include <exiv2/error.hpp>
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2Rational, exiv2_rational, G_TYPE_OBJECT);

static void
exiv2_rational_init (Exiv2Rational *self)
{
	Exiv2RationalPrivate *priv;
	self->priv = priv = EXIV2_RATIONAL_GET_PRIVATE (self);
}

static void
exiv2_rational_class_init (Exiv2RationalClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2RationalPrivate));
}

Exiv2Rational*
exiv2_rational_new (gint32 numerator, gint32 denominator)
{
	Exiv2Rational *rational;
	rational = EXIV2_RATIONAL (g_object_new (EXIV2_TYPE_RATIONAL, NULL));
	rational->priv->rational = Exiv2::Rational (numerator, denominator);

	return rational;		
}

gint32
exiv2_rational_getNumerator	(Exiv2Rational *self)
{
	g_return_val_if_fail (EXIV2_IS_RATIONAL (self), 0);
	return self->priv->rational.first;
}

void
exiv2_rational_setNumerator (Exiv2Rational *self, gint32 numerator)
{
	g_return_if_fail (EXIV2_IS_RATIONAL (self));
	self->priv->rational.first = numerator;
}

gint32
exiv2_rational_getDenominator (Exiv2Rational *self)
{
	g_return_val_if_fail (EXIV2_IS_RATIONAL (self), 0);
	return self->priv->rational.second;
}

void
exiv2_rational_setDenominator (Exiv2Rational *self, gint32 denominator)
{
	g_return_if_fail (EXIV2_IS_RATIONAL (self));
	self->priv->rational.second = denominator;	
}

G_END_DECLS
