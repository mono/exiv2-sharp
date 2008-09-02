/*
 * exiv2-imagefactory.cpp
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#include "exiv2-image-private.h"
#include "exiv2-imagefactory.h"
#include "exiv2-image.h"

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ImageFactory, exiv2_imagefactory, G_TYPE_OBJECT);

static void
exiv2_imagefactory_init (Exiv2ImageFactory *self)
{
}

static void
exiv2_imagefactory_class_init (Exiv2ImageFactoryClass *klass)
{
	
}

Exiv2Image*
exiv2_imagefactory_open (const char *path, GError **error)
{
	Exiv2Image *image;
	image = EXIV2_IMAGE (g_object_new (EXIV2_TYPE_IMAGE, NULL));
	try {
		image->priv->imptr = (Exiv2::ImageFactory::open (path)).release ();
	} catch (Exiv2::Error e) {
		g_set_error (error, g_quark_from_string ("Exiv2"), e.code (), e.what ());
	}

	return image;
}

G_END_DECLS
