/*
 * exiv2-xmpdatum.h
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
#ifndef __EXIV2_XMPDATUM_H__
#define __EXIV2_XMPDATUM_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_XMPDATUM			(exiv2_xmpdatum_get_type ())
#define EXIV2_XMPDATUM(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_XMPDATUM, Exiv2XmpDatum))
#define EXIV2_IS_XMPDATUM(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_XMPDATUM))
#define EXIV2_XMPDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_XMPDATUM, Exiv2XmpDatumClass))
#define EXIV2_IS_XMPDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_XMPDATUM))
#define EXIV2_XMPDATUM_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_XMPDATUM, Exiv2XmpDatumClass))

#define EXIV2_XMPDATUM_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_XMPDATUM, Exiv2XmpDatumPrivate))

typedef struct _Exiv2XmpDatum		Exiv2XmpDatum;
typedef struct _Exiv2XmpDatumClass	Exiv2XmpDatumClass;
typedef struct _Exiv2XmpDatumPrivate	Exiv2XmpDatumPrivate;

struct _Exiv2XmpDatum
{
	GObject parent_instance;

	/*< private >*/
	Exiv2XmpDatumPrivate *priv;
};

struct _Exiv2XmpDatumClass
{
	GObjectClass parent_class;

	/* virtual public methods */
//	const char* 	(*get_key) 		(Exiv2XmpDatum *self);
//	guint16		(*get_tag)		(Exiv2XmpDatum *self);
//	const char*	(*get_typename)		(Exiv2XmpDatum *self);
//	glong		(*get_count)		(Exiv2XmpDatum *self);
	const char*	(*toString)		(Exiv2XmpDatum *self);

	void		(*set_value_ushort)	(Exiv2XmpDatum *self, const guint16 value);
	void		(*set_value_ulong)	(Exiv2XmpDatum *self, const guint32 value);
	void		(*set_value_urational)	(Exiv2XmpDatum *self, const guint32 denominator, const guint32 numerator);
	void		(*set_value_sshort)	(Exiv2XmpDatum *self, const gint16 value);
	void		(*set_value_slong)	(Exiv2XmpDatum *self, const gint32 value);
	void		(*set_value_rational)	(Exiv2XmpDatum *self, const gint32 numerator, const gint32 denominator);
	void		(*set_value_string)	(Exiv2XmpDatum *self, const char* value);
};

GType		exiv2_xmpdatum_get_type 	(void);
//const char*	exiv2_xmpdatum_get_key		(Exiv2XmpDatum *self);
//guint16		exiv2_xmpdatum_get_tag		(Exiv2XmpDatum *self);
//const char*	exiv2_xmpdatum_get_typename	(Exiv2XmpDatum *self);
//glong		exiv2_xmpdatum_get_count	(Exiv2XmpDatum *self);
const char*	exiv2_xmpdatum_toString	(Exiv2XmpDatum *self);

//void		exiv2_xmpdatum_setValueUShort		(Exiv2XmpDatum *self, const guint16 value);
//void		exiv2_xmpdatum_setValueULong		(Exiv2XmpDatum *self, const guint32 value);
//void		exiv2_xmpdatum_setValueURational	(Exiv2XmpDatum *self, const guint32 numerator, const guint32 denominator);
//void		exiv2_xmpdatum_setValueSShort		(Exiv2XmpDatum *self, const gint16 value);
//void		exiv2_xmpdatum_setValueSLong		(Exiv2XmpDatum *self, const gint32 value);
//void		exiv2_xmpdatum_setValueRational	(Exiv2XmpDatum *self, const gint32 numerator, const gint32 denominator);
//void		exiv2_xmpdatum_setValueString		(Exiv2XmpDatum *self, const char* value);

G_END_DECLS

#endif /*  __EXIV2_XMPDATUM_H__ */
