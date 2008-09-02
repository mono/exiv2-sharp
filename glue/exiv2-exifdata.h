/*
 * exiv2-exifdata.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_EXIFDATA_H__
#define __EXIV2_EXIFDATA_H__

#include <glib-object.h>
#include "exiv2-exifdatum.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFDATA		(exiv2_exifdata_get_type ())
#define EXIV2_EXIFDATA(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifData))
#define EXIV2_IS_EXIFDATA(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFDATA))
#define EXIV2_EXIFDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataClass))
#define EXIV2_IS_EXIFDATA_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFDATA))
#define EXIV2_EXIFDATA_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataClass))

#define EXIV2_EXIFDATA_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_EXIFDATA, Exiv2ExifDataPrivate))

typedef struct _Exiv2ExifData		Exiv2ExifData;
typedef struct _Exiv2ExifDataClass	Exiv2ExifDataClass;
typedef struct _Exiv2ExifDataPrivate	Exiv2ExifDataPrivate;

struct _Exiv2ExifData
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ExifDataPrivate *priv;
};

struct _Exiv2ExifDataClass
{
	GObjectClass parent_class;

};

GType		exiv2_exifdata_get_type 	(void);
long		exiv2_exifdata_get_count 	(Exiv2ExifData *self);
gboolean	exiv2_exifdata_get_isEmpty	(Exiv2ExifData *self);
Exiv2ExifDatum*	exiv2_exifdata_begin		(Exiv2ExifData *self);
Exiv2ExifDatum*	exiv2_exifdata_end		(Exiv2ExifData *self);

G_END_DECLS

#endif /*  __EXIV2_EXIFDATA_H__ */
