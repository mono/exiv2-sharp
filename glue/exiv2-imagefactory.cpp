/*
 * exiv2-imagefactory.cpp
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
		image->priv->imptr = (Exiv2::ImageFactory::open (path));
	} catch (Exiv2::Error e) {
		g_set_error (error, g_quark_from_string ("Exiv2"), e.code (), e.what ());
	}

	return image;
}
Exiv2Image*
exiv2_imagefactory_open_buf (const guint8 *data, glong n_data, GError **error)
{
	Exiv2Image *image;
	image = EXIV2_IMAGE (g_object_new (EXIV2_TYPE_IMAGE, NULL));
	try {
		image->priv->imptr = (Exiv2::ImageFactory::open (data, n_data));
	} catch (Exiv2::Error e) {
		g_set_error (error, g_quark_from_string ("Exiv2"), e.code (), e.what ());
	}

	return image;	
}

G_END_DECLS
