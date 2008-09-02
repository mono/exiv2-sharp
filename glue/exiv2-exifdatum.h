/*
 * exiv2-exifdatum.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
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

};

GType		exiv2_exifdatum_get_type 	(void);
const char*	exiv2_exifdatum_get_key		(Exiv2ExifDatum *self);
guint16		exiv2_exifdatum_get_tag		(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_get_typename	(Exiv2ExifDatum *self);
glong		exiv2_exifdatum_get_count	(Exiv2ExifDatum *self);
const char*	exiv2_exifdatum_toString	(Exiv2ExifDatum *self);
void		exiv2_exifdatum_next		(Exiv2ExifDatum *self);
gboolean	exiv2_exifdatum_equals		(Exiv2ExifDatum *self, Exiv2ExifDatum *other);

G_END_DECLS

#endif /*  __EXIV2_EXIFDATUM_H__ */
