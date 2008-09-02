/*
 * exiv2-exifdatum.h
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
#ifndef __EXIV2_EXIFDATUM_H__
#define __EXIV2_EXIFDATUM_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFDATUM			(exiv2_exifdatum_get_type ())
#define EXIV2_EXIFDATUM(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFDATUM, Exiv2ExifDatum))
#define EXIV2_IS_EXIFDATUM(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFDATUM))
#define EXIV2_EXIFDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFDATUM, Exiv2ExifDatumClass))
#define EXIV2_IS_EXIFDATUM_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFDATUM))
#define EXIV2_EXIFDATUM_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFDATUM, Exiv2ExifDatumClass))

#define EXIV2_EXIFDATUM_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_EXIFDATUM, Exiv2ExifDatumPrivate))

typedef struct _Exiv2ExifDatum		Exiv2ExifDatum;
typedef struct _Exiv2ExifDatumClass	Exiv2ExifDatumClass;
typedef struct _Exiv2ExifDatumPrivate	Exiv2ExifDatumPrivate;

struct _Exiv2ExifDatum
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ExifDatumPrivate *priv;
};

struct _Exiv2ExifDatumClass
{
	GObjectClass parent_class;

	/* virtual public methods */
	const char* 	(*get_key) 		(Exiv2ExifDatum *self);
	guint16		(*get_tag)		(Exiv2ExifDatum *self);
	const char*	(*get_typename)		(Exiv2ExifDatum *self);
	glong		(*get_count)		(Exiv2ExifDatum *self);
	const char*	(*toString)		(Exiv2ExifDatum *self);

	void		(*set_value_ushort)	(Exiv2ExifDatum *self, const guint16 value);
	void		(*set_value_ulong)	(Exiv2ExifDatum *self, const guint32 value);
	void		(*set_value_urational)	(Exiv2ExifDatum *self, const guint32 denominator, const guint32 numerator);
	void		(*set_value_sshort)	(Exiv2ExifDatum *self, const gint16 value);
	void		(*set_value_slong)	(Exiv2ExifDatum *self, const gint32 value);
	void		(*set_value_rational)	(Exiv2ExifDatum *self, const gint32 numerator, const gint32 denominator);
	void		(*set_value_string)	(Exiv2ExifDatum *self, const char* value);
};

GType		exiv2_exifdatum_get_type 	(void);
const char*	exiv2_exifdatum_get_key		(Exiv2ExifDatum *self);
guint16		exiv2_exifdatum_get_tag		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_get_typename	(Exiv2ExifDatum *self);
glong		exiv2_exifdatum_get_count	(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_toString	(Exiv2ExifDatum *self);

void		exiv2_exifdatum_setValueUShort		(Exiv2ExifDatum *self, const guint16 value);
void		exiv2_exifdatum_setValueULong		(Exiv2ExifDatum *self, const guint32 value);
void		exiv2_exifdatum_setValueURational	(Exiv2ExifDatum *self, const guint32 numerator, const guint32 denominator);
void		exiv2_exifdatum_setValueSShort		(Exiv2ExifDatum *self, const gint16 value);
void		exiv2_exifdatum_setValueSLong		(Exiv2ExifDatum *self, const gint32 value);
void		exiv2_exifdatum_setValueRational	(Exiv2ExifDatum *self, const gint32 numerator, const gint32 denominator);
void		exiv2_exifdatum_setValueString		(Exiv2ExifDatum *self, const char* value);

G_END_DECLS

#endif /*  __EXIV2_EXIFDATUM_H__ */
