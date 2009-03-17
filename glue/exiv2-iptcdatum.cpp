/*
 * exiv2-iptcdatum.cpp
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 * 	Mike Gemuende (mike@gemuende.de)
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
#include "exiv2-iptcdatum.h"
#include "exiv2-iptcdatum-private.h"
#include "exiv2-rational-private.h"
#include "exiv2-urational-private.h"
#include <exiv2/iptc.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2IptcDatum, exiv2_iptcdatum, G_TYPE_OBJECT);

static void exiv2_iptcdatum_finalize (GObject *gobject);

const char*	exiv2_iptcdatum_real_get_key 		(Exiv2IptcDatum *self);
guint16		exiv2_iptcdatum_real_get_tag		(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatum_real_get_typename	(Exiv2IptcDatum *self);
glong		exiv2_iptcdatum_real_get_count 		(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatum_real_toString 		(Exiv2IptcDatum *self);

void		exiv2_iptcdatum_real_setValueUShort		(Exiv2IptcDatum *self, const guint16 value);
//void		exiv2_iptcdatum_real_setValueULong		(Exiv2IptcDatum *self, const guint32 value);
//void		exiv2_iptcdatum_real_setValueURational	(Exiv2IptcDatum *self, Exiv2URational *urational);
//void		exiv2_iptcdatum_real_setValueSShort		(Exiv2IptcDatum *self, const gint16 value);
//void		exiv2_iptcdatum_real_setValueSLong		(Exiv2IptcDatum *self, const gint32 value);
//void		exiv2_iptcdatum_real_setValueRational	(Exiv2IptcDatum *self, Exiv2Rational *rational);
void		exiv2_iptcdatum_real_setValueString		(Exiv2IptcDatum *self, const char* value);

static void
exiv2_iptcdatum_init (Exiv2IptcDatum *self)
{
	Exiv2IptcDatumPrivate *priv;
	self->priv = priv = EXIV2_IPTCDATUM_GET_PRIVATE (self);
}

static void
exiv2_iptcdatum_class_init (Exiv2IptcDatumClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_iptcdatum_finalize;

	klass->get_key = exiv2_iptcdatum_real_get_key;
	klass->get_tag = exiv2_iptcdatum_real_get_tag;
	klass->get_typename = exiv2_iptcdatum_real_get_typename;
	klass->get_count = exiv2_iptcdatum_real_get_count;
	klass->toString = exiv2_iptcdatum_real_toString;
	klass->set_value_ushort		= exiv2_iptcdatum_real_setValueUShort;
//	klass->set_value_ulong		= exiv2_iptcdatum_real_setValueULong;
//	klass->set_value_urational	= exiv2_iptcdatum_real_setValueURational;
//	klass->set_value_sshort		= exiv2_iptcdatum_real_setValueSShort;
//	klass->set_value_slong		= exiv2_iptcdatum_real_setValueSLong;
//	klass->set_value_rational	= exiv2_iptcdatum_real_setValueRational;
	klass->set_value_string		= exiv2_iptcdatum_real_setValueString;
	
	
	
	g_type_class_add_private (klass, sizeof	(Exiv2IptcDatumPrivate));
}

static void
exiv2_iptcdatum_finalize (GObject *gobject)
{
	Exiv2IptcDatum *self = EXIV2_IPTCDATUM (gobject);
	if (self->priv->datum) {
		delete self->priv->datum;
		self->priv->datum = NULL;
	}
	G_OBJECT_CLASS (exiv2_iptcdatum_parent_class)->finalize (gobject);
}

const char*
exiv2_iptcdatum_get_key	(Exiv2IptcDatum *self)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->get_key (self);
}

guint16
exiv2_iptcdatum_get_tag	(Exiv2IptcDatum *self)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->get_tag (self);
}

const char*
exiv2_iptcdatum_get_typename (Exiv2IptcDatum *self)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->get_typename (self);
}

glong
exiv2_iptcdatum_get_count (Exiv2IptcDatum *self)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->get_count (self);
}

const char*
exiv2_iptcdatum_toString (Exiv2IptcDatum *self)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->toString (self);
}

void exiv2_iptcdatum_setValueUShort (Exiv2IptcDatum *self, const guint16 value)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_ushort (self, value);	
}

//void exiv2_iptcdatum_setValueULong (Exiv2IptcDatum *self, const guint32 value)
//{
//	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_ulong (self, value);		
//}

//void exiv2_iptcdatum_setValueURational (Exiv2IptcDatum *self, Exiv2URational *urational)
//{
//	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_urational (self, urational);
//}

//void exiv2_iptcdatum_setValueSShort (Exiv2IptcDatum *self, const gint16 value)
//{
//	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_sshort (self, value);		
//}

//void exiv2_iptcdatum_setValueSLong (Exiv2IptcDatum *self, const gint32 value)
//{
//	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_slong (self, value);		
//}

//void exiv2_iptcdatum_setValueRational (Exiv2IptcDatum *self, Exiv2Rational *rational)
//{
//	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_rational (self, rational);
//}

void exiv2_iptcdatum_setValueString (Exiv2IptcDatum *self, const char* value)
{
	return EXIV2_IPTCDATUM_GET_CLASS (self)->set_value_string (self, value);		
}

const char*
exiv2_iptcdatum_real_get_key (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUM (self), NULL);
	return self->priv->datum->key ().c_str ();	
}

guint16
exiv2_iptcdatum_real_get_tag (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUM (self), -1);
	return self->priv->datum->tag ();	
}


const char*
exiv2_iptcdatum_real_get_typename (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUM (self), NULL);
	return self->priv->datum->typeName ();
}

glong
exiv2_iptcdatum_real_get_count (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUM (self), -1);
	return self->priv->datum->count ();
}

const char*
exiv2_iptcdatum_real_toString (Exiv2IptcDatum *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCDATUM (self), NULL);
	return self->priv->datum->toString ().c_str ();
}

void exiv2_iptcdatum_real_setValueUShort (Exiv2IptcDatum *self, const uint16_t value)
{
	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
	Exiv2::Iptcdatum* datum = self->priv->datum;
	(*datum) = value;
}

//void exiv2_iptcdatum_real_setValueULong (Exiv2IptcDatum *self, const uint32_t value)
//{
//	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
//	Exiv2::Iptcdatum* datum = self->priv->datum;
//	(*datum) = value;
//}

//void exiv2_iptcdatum_real_setValueURational (Exiv2IptcDatum *self, Exiv2URational *urational)
//{
//	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
//	g_return_if_fail (EXIV2_IS_URATIONAL (urational));
//	Exiv2::Iptcdatum* datum = self->priv->datum;
//	(*datum) = urational->priv->urational;
//}

//void exiv2_iptcdatum_real_setValueSShort (Exiv2IptcDatum *self, const int16_t value)
//{
//	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
//	Exiv2::Iptcdatum* datum = self->priv->datum;
//	(*datum) = value;
//}

//void exiv2_iptcdatum_real_setValueSLong (Exiv2IptcDatum *self, const int32_t value)
//{
//	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
//	Exiv2::Iptcdatum* datum = self->priv->datum;
//	(*datum) = value;
//}

//void exiv2_iptcdatum_real_setValueRational (Exiv2IptcDatum *self, Exiv2Rational *rational)
//{
//	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
//	g_return_if_fail (EXIV2_IS_RATIONAL (rational));
//	Exiv2::Iptcdatum* datum = self->priv->datum;
//	(*datum) = rational->priv->rational;
//}

void exiv2_iptcdatum_real_setValueString (Exiv2IptcDatum *self, const char* value)
{
	g_return_if_fail (EXIV2_IS_IPTCDATUM (self));
	Exiv2::Iptcdatum* datum = self->priv->datum;
	(*datum) = value;
}

G_END_DECLS
