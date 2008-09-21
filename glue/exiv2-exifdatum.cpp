/*
 * exiv2-exifdatum.cpp
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
#include "exiv2-exifdatum.h"
#include "exiv2-exifdatum-private.h"
#include "exiv2-rational-private.h"
#include "exiv2-urational-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifDatum, exiv2_exifdatum, G_TYPE_OBJECT);

const char*	exiv2_exifdatum_real_get_key 		(Exiv2ExifDatum *self);
guint16		exiv2_exifdatum_real_get_tag		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_real_get_typename	(Exiv2ExifDatum *self);
glong		exiv2_exifdatum_real_get_count 		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_real_toString 		(Exiv2ExifDatum *self);

void		exiv2_exifdatum_real_setValueUShort		(Exiv2ExifDatum *self, const guint16 value);
void		exiv2_exifdatum_real_setValueULong		(Exiv2ExifDatum *self, const guint32 value);
void		exiv2_exifdatum_real_setValueURational	(Exiv2ExifDatum *self, Exiv2URational *urational);
void		exiv2_exifdatum_real_setValueSShort		(Exiv2ExifDatum *self, const gint16 value);
void		exiv2_exifdatum_real_setValueSLong		(Exiv2ExifDatum *self, const gint32 value);
void		exiv2_exifdatum_real_setValueRational	(Exiv2ExifDatum *self, Exiv2Rational *rational);
void		exiv2_exifdatum_real_setValueString		(Exiv2ExifDatum *self, const char* value);

static void
exiv2_exifdatum_init (Exiv2ExifDatum *self)
{
	Exiv2ExifDatumPrivate *priv;
	self->priv = priv = EXIV2_EXIFDATUM_GET_PRIVATE (self);
}

static void
exiv2_exifdatum_class_init (Exiv2ExifDatumClass *klass)
{
	klass->get_key = exiv2_exifdatum_real_get_key;
	klass->get_tag = exiv2_exifdatum_real_get_tag;
	klass->get_typename = exiv2_exifdatum_real_get_typename;
	klass->get_count = exiv2_exifdatum_real_get_count;
	klass->toString = exiv2_exifdatum_real_toString;
	klass->set_value_ushort		= exiv2_exifdatum_real_setValueUShort;
	klass->set_value_ulong		= exiv2_exifdatum_real_setValueULong;
	klass->set_value_urational	= exiv2_exifdatum_real_setValueURational;
	klass->set_value_sshort		= exiv2_exifdatum_real_setValueSShort;
	klass->set_value_slong		= exiv2_exifdatum_real_setValueSLong;
	klass->set_value_rational	= exiv2_exifdatum_real_setValueRational;
	klass->set_value_string		= exiv2_exifdatum_real_setValueString;



	g_type_class_add_private (klass, sizeof	(Exiv2ExifDatumPrivate));
}

const char*
exiv2_exifdatum_get_key	(Exiv2ExifDatum *self)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->get_key (self);
}

guint16
exiv2_exifdatum_get_tag	(Exiv2ExifDatum *self)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->get_tag (self);
}

const char*
exiv2_exifdatum_get_typename (Exiv2ExifDatum *self)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->get_typename (self);
}

glong
exiv2_exifdatum_get_count (Exiv2ExifDatum *self)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->get_count (self);
}

const char*
exiv2_exifdatum_toString (Exiv2ExifDatum *self)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->toString (self);
}

void exiv2_exifdatum_setValueUShort (Exiv2ExifDatum *self, const guint16 value)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_ushort (self, value);	
}

void exiv2_exifdatum_setValueULong (Exiv2ExifDatum *self, const guint32 value)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_ulong (self, value);		
}
void exiv2_exifdatum_setValueURational (Exiv2ExifDatum *self, Exiv2URational *urational)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_urational (self, urational);
}

void exiv2_exifdatum_setValueSShort (Exiv2ExifDatum *self, const gint16 value)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_sshort (self, value);		
}

void exiv2_exifdatum_setValueSLong (Exiv2ExifDatum *self, const gint32 value)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_slong (self, value);		
}

void exiv2_exifdatum_setValueRational (Exiv2ExifDatum *self, Exiv2Rational *rational)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_rational (self, rational);
}

void exiv2_exifdatum_setValueString (Exiv2ExifDatum *self, const char* value)
{
	return EXIV2_EXIFDATUM_GET_CLASS (self)->set_value_string (self, value);		
}

const char*
exiv2_exifdatum_real_get_key (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->datum->key ().c_str ();	
}

guint16
exiv2_exifdatum_real_get_tag (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), -1);
	return self->priv->datum->tag ();	
}


const char*
exiv2_exifdatum_real_get_typename (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->datum->typeName ();
}

glong
exiv2_exifdatum_real_get_count (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), -1);
	return self->priv->datum->count ();	
}

const char*
exiv2_exifdatum_real_toString (Exiv2ExifDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFDATUM (self), NULL);
	return self->priv->datum->toString ().c_str ();	
}

void exiv2_exifdatum_real_setValueUShort (Exiv2ExifDatum *self, const uint16_t value)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = value;	
}

void exiv2_exifdatum_real_setValueULong (Exiv2ExifDatum *self, const uint32_t value)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = value;	
}

void exiv2_exifdatum_real_setValueURational (Exiv2ExifDatum *self, Exiv2URational *urational)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	g_return_if_fail (EXIV2_IS_URATIONAL (urational));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = urational->priv->urational;
}

void exiv2_exifdatum_real_setValueSShort (Exiv2ExifDatum *self, const int16_t value)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = value;	
}

void exiv2_exifdatum_real_setValueSLong (Exiv2ExifDatum *self, const int32_t value)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = value;	
}

void exiv2_exifdatum_real_setValueRational (Exiv2ExifDatum *self, Exiv2Rational *rational)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	g_return_if_fail (EXIV2_IS_RATIONAL (rational));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = rational->priv->rational;
}

void exiv2_exifdatum_real_setValueString (Exiv2ExifDatum *self, const char* value)
{
	g_return_if_fail (EXIV2_IS_EXIFDATUM (self));
	Exiv2::Exifdatum* datum = self->priv->datum;
	(*datum) = value;	
}


G_END_DECLS
