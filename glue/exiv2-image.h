/*
 * exiv2-image.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_IMAGE_H__
#define __EXIV2_IMAGE_H__

#include <glib-object.h>
#include "exiv2-exifdata.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_IMAGE		(exiv2_image_get_type ())
#define EXIV2_IMAGE(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IMAGE, Exiv2Image))
#define EXIV2_IS_IMAGE(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IMAGE))
#define EXIV2_IMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IMAGE, Exiv2ImageClass))
#define EXIV2_IS_IMAGE_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IMAGE))
#define EXIV2_IMAGE_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IMAGE, Exiv2ImageClass))

#define EXIV2_IMAGE_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_IMAGE, Exiv2ImagePrivate))

typedef struct _Exiv2Image	Exiv2Image;
typedef struct _Exiv2ImageClass	Exiv2ImageClass;
typedef struct _Exiv2ImagePrivate Exiv2ImagePrivate;

struct _Exiv2Image
{
	GObject parent_instance;

	/*< private >*/
	Exiv2ImagePrivate *priv;
};

struct _Exiv2ImageClass
{
	GObjectClass parent_class;

};

GType exiv2_image_get_type (void);

void		exiv2_image_readMetadata (Exiv2Image *self, GError **error);
gboolean	exiv2_image_get_good (Exiv2Image *self);
Exiv2ExifData*	exiv2_image_get_exifData (Exiv2Image *self);

G_END_DECLS

#endif /*  __EXIV2_IMAGEFACTORY_H__ */
