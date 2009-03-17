/*
 * exiv2-iptcdatum.h
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
#ifndef __EXIV2_IPTCDATUM_H__
#define __EXIV2_IPTCDATUM_H__

#include <glib-object.h>
#include "exiv2-rational.h"
#include "exiv2-urational.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_IPTCDATUM			(exiv2_iptcdatum_get_type ())
#define EXIV2_IPTCDATUM(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IPTCDATUM, Exiv2IptcDatum))
#define EXIV2_IS_IPTCDATUM(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IPTCDATUM))
#define EXIV2_IPTCDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IPTCDATUM, Exiv2IptcDatumClass))
#define EXIV2_IS_IPTCDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IPTCDATUM))
#define EXIV2_IPTCDATUM_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IPTCDATUM, Exiv2IptcDatumClass))

#define EXIV2_IPTCDATUM_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_IPTCDATUM, Exiv2IptcDatumPrivate))

typedef struct _Exiv2IptcDatum		Exiv2IptcDatum;
typedef struct _Exiv2IptcDatumClass	Exiv2IptcDatumClass;
typedef struct _Exiv2IptcDatumPrivate	Exiv2IptcDatumPrivate;

struct _Exiv2IptcDatum
{
	GObject parent_instance;

	/*< private >*/
	Exiv2IptcDatumPrivate *priv;
};

struct _Exiv2IptcDatumClass
{
	GObjectClass parent_class;

	/* virtual public methods */
	const char* 	(*get_key) 		(Exiv2IptcDatum *self);
	guint16		(*get_tag)		(Exiv2IptcDatum *self);
	const char*	(*get_typename)		(Exiv2IptcDatum *self);
	glong		(*get_count)		(Exiv2IptcDatum *self);
	const char*	(*toString)		(Exiv2IptcDatum *self);

	void		(*set_value_ushort)	(Exiv2IptcDatum *self, const guint16 value);
//	void		(*set_value_ulong)	(Exiv2IptcDatum *self, const guint32 value);
//	void		(*set_value_urational)	(Exiv2IptcDatum *self, Exiv2URational *urational);
//	void		(*set_value_sshort)	(Exiv2IptcDatum *self, const gint16 value);
//	void		(*set_value_slong)	(Exiv2IptcDatum *self, const gint32 value);
//	void		(*set_value_rational)	(Exiv2IptcDatum *self, Exiv2Rational *rational);
	void		(*set_value_string)	(Exiv2IptcDatum *self, const char* value);
};

GType		exiv2_iptcdatum_get_type 	(void);
const char*	exiv2_iptcdatum_get_key		(Exiv2IptcDatum *self);
guint16		exiv2_iptcdatum_get_tag		(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatum_get_typename	(Exiv2IptcDatum *self);
glong		exiv2_iptcdatum_get_count	(Exiv2IptcDatum *self);
const char*	exiv2_iptcdatum_toString	(Exiv2IptcDatum *self);

void		exiv2_iptcdatum_setValueUShort		(Exiv2IptcDatum *self, const guint16 value);
//void		exiv2_iptcdatum_setValueULong		(Exiv2IptcDatum *self, const guint32 value);
//void		exiv2_iptcdatum_setValueURational	(Exiv2IptcDatum *self, Exiv2URational *urational);
//void		exiv2_iptcdatum_setValueSShort		(Exiv2IptcDatum *self, const gint16 value);
//void		exiv2_iptcdatum_setValueSLong		(Exiv2IptcDatum *self, const gint32 value);
//void		exiv2_iptcdatum_setValueRational	(Exiv2IptcDatum *self, Exiv2Rational *rational);
void		exiv2_iptcdatum_setValueString		(Exiv2IptcDatum *self, const char* value);

G_END_DECLS

#endif /*  __EXIV2_IPTCDATUM_H__ */

