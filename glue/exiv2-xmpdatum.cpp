/*
 * exiv2-xmpdatum.cpp
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell, Inc
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
#include "exiv2-xmpdatum.h"
#include "exiv2-xmpdatum-private.h"
#include <exiv2/xmp.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2XmpDatum, exiv2_xmpdatum, G_TYPE_OBJECT);

static void exiv2_xmpdatum_finalize (GObject *gobject);

const char*	exiv2_xmpdatum_real_get_key 		(Exiv2XmpDatum *self);
guint16		exiv2_xmpdatum_real_get_tag		(Exiv2XmpDatum *self);
const char*	exiv2_xmpdatum_real_get_typename	(Exiv2XmpDatum *self);
glong		exiv2_xmpdatum_real_get_count 		(Exiv2XmpDatum *self);
const char*	exiv2_xmpdatum_real_toString 		(Exiv2XmpDatum *self);

//void		exiv2_xmpdatum_real_setValueUShort		(Exiv2XmpDatum *self, const guint16 value);
//void		exiv2_xmpdatum_real_setValueULong		(Exiv2XmpDatum *self, const guint32 value);
//void		exiv2_xmpdatum_real_setValueURational	(Exiv2XmpDatum *self, const guint32 numerator, const guint32 denominator);
//void		exiv2_xmpdatum_real_setValueSShort		(Exiv2XmpDatum *self, const gint16 value);
//void		exiv2_xmpdatum_real_setValueSLong		(Exiv2XmpDatum *self, const gint32 value);
//void		exiv2_xmpdatum_real_setValueRational	(Exiv2XmpDatum *self, const gint32 numerator, const gint32 denominator);
//void		exiv2_xmpdatum_real_setValueString		(Exiv2XmpDatum *self, const char* value);

static void
exiv2_xmpdatum_init (Exiv2XmpDatum *self)
{
	Exiv2XmpDatumPrivate *priv;
	self->priv = priv = EXIV2_XMPDATUM_GET_PRIVATE (self);
}

static void
exiv2_xmpdatum_class_init (Exiv2XmpDatumClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_xmpdatum_finalize;

	klass->get_key = exiv2_xmpdatum_real_get_key;
	klass->get_tag = exiv2_xmpdatum_real_get_tag;
	klass->get_typename = exiv2_xmpdatum_real_get_typename;
	klass->get_count = exiv2_xmpdatum_real_get_count;
	klass->toString = exiv2_xmpdatum_real_toString;
//	klass->set_value_ushort		= exiv2_xmpdatum_real_setValueUShort;
//	klass->set_value_ulong		= exiv2_xmpdatum_real_setValueULong;
//	klass->set_value_urational	= exiv2_xmpdatum_real_setValueURational;
//	klass->set_value_sshort		= exiv2_xmpdatum_real_setValueSShort;
//	klass->set_value_slong		= exiv2_xmpdatum_real_setValueSLong;
//	klass->set_value_rational	= exiv2_xmpdatum_real_setValueRational;
//	klass->set_value_string		= exiv2_xmpdatum_real_setValueString;
//
	g_type_class_add_private (klass, sizeof	(Exiv2XmpDatumPrivate));
}

static void
exiv2_xmpdatum_finalize (GObject *gobject)
{
	Exiv2XmpDatum *self = EXIV2_XMPDATUM (gobject);
	if (self->priv->datum) {
		delete self->priv->datum;
		self->priv->datum = NULL;
	}
	G_OBJECT_CLASS (exiv2_xmpdatum_parent_class)->finalize (gobject);
}

const char*
exiv2_xmpdatum_get_key	(Exiv2XmpDatum *self)
{
	return EXIV2_XMPDATUM_GET_CLASS (self)->get_key (self);
}

guint16
exiv2_xmpdatum_get_tag	(Exiv2XmpDatum *self)
{
	return EXIV2_XMPDATUM_GET_CLASS (self)->get_tag (self);
}

const char*
exiv2_xmpdatum_get_typename (Exiv2XmpDatum *self)
{
	return EXIV2_XMPDATUM_GET_CLASS (self)->get_typename (self);
}

glong
exiv2_xmpdatum_get_count (Exiv2XmpDatum *self)
{
	return EXIV2_XMPDATUM_GET_CLASS (self)->get_count (self);
}

const char*
exiv2_xmpdatum_toString (Exiv2XmpDatum *self)
{
	return EXIV2_XMPDATUM_GET_CLASS (self)->toString (self);
}

//void exiv2_xmpdatum_setValueUShort (Exiv2XmpDatum *self, const guint16 value)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_ushort (self, value);	
//}
//
//void exiv2_xmpdatum_setValueULong (Exiv2XmpDatum *self, const guint32 value)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_ulong (self, value);		
//}
//void exiv2_xmpdatum_setValueURational (Exiv2XmpDatum *self, const guint32 numerator, const guint32 denominator)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_urational (self, numerator, denominator);		
//}
//
//void exiv2_xmpdatum_setValueSShort (Exiv2XmpDatum *self, const gint16 value)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_sshort (self, value);		
//}
//
//void exiv2_xmpdatum_setValueSLong (Exiv2XmpDatum *self, const gint32 value)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_slong (self, value);		
//}
//
//void exiv2_xmpdatum_setValueRational (Exiv2XmpDatum *self, const gint32 numerator, const gint32 denominator)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_rational (self, numerator, denominator);
//}
//
//void exiv2_xmpdatum_setValueString (Exiv2XmpDatum *self, const char* value)
//{
//	return EXIV2_XMPDATUM_GET_CLASS (self)->set_value_string (self, value);		
//}

const char*
exiv2_xmpdatum_real_get_key (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUM (self), NULL);
	return self->priv->datum->key ().c_str ();	
}

guint16
exiv2_xmpdatum_real_get_tag (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUM (self), -1);
	return self->priv->datum->tag ();	
}


const char*
exiv2_xmpdatum_real_get_typename (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUM (self), NULL);
	return self->priv->datum->typeName ();
}

glong
exiv2_xmpdatum_real_get_count (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUM (self), -1);
	return self->priv->datum->count ();	
}

const char*
exiv2_xmpdatum_real_toString (Exiv2XmpDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_XMPDATUM (self), NULL);
	return self->priv->datum->toString ().c_str ();	
}
//
//void exiv2_xmpdatum_real_setValueUShort (Exiv2XmpDatum *self, const uint16_t value)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = value;	
//}
//
//void exiv2_xmpdatum_real_setValueULong (Exiv2XmpDatum *self, const uint32_t value)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = value;	
//}
//
//void exiv2_xmpdatum_real_setValueURational (Exiv2XmpDatum *self, const uint32_t numerator, const uint32_t denominator)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = Exiv2::URational (numerator, denominator);
//}
//
//void exiv2_xmpdatum_real_setValueSShort (Exiv2XmpDatum *self, const int16_t value)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = value;	
//}
//
//void exiv2_xmpdatum_real_setValueSLong (Exiv2XmpDatum *self, const int32_t value)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = value;	
//}
//
//void exiv2_xmpdatum_real_setValueRational (Exiv2XmpDatum *self, const int32_t numerator, const int32_t denominator)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = Exiv2::Rational (numerator, denominator);	
//}
//
//void exiv2_xmpdatum_real_setValueString (Exiv2XmpDatum *self, const char* value)
//{
//	g_return_if_fail (EXIV2_IS_XMPDATUM (self));
//	Exiv2::Exifdatum* datum = self->priv->datum;
//	(*datum) = value;	
//}


G_END_DECLS
