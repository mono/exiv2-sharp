/*
 * exiv2-imagefactory.h
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
#ifndef __EXIV2_IMAGEFACTORY_H__
#define __EXIV2_IMAGEFACTORY_H__

#include <glib-object.h>

#include "exiv2-image.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_IMAGEFACTORY			(exiv2_imagefactory_get_type ())
#define EXIV2_IMAGEFACTORY(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IMAGEFACTORY, Exiv2ImageFactory))
#define EXIV2_IS_IMAGEFACTORY(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IMAGEFACTORY))
#define EXIV2_IMAGEFACTORY_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IMAGEFACTORY, Exiv2ImageFactoryClass))
#define EXIV2_IS_IMAGEFACTORY_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IMAGEFACTORY))
#define EXIV2_IMAGEFACTORY_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IMAGEFACTORY, Exiv2ImageFactoryClass))

typedef struct _Exiv2ImageFactory	Exiv2ImageFactory;
typedef struct _Exiv2ImageFactoryClass	Exiv2ImageFactoryClass;

struct _Exiv2ImageFactory
{
	GObject parent_instance;

};

struct _Exiv2ImageFactoryClass
{
	GObjectClass parent_class;

};

GType exiv2_imagefactory_get_type (void);
Exiv2Image* exiv2_imagefactory_open (const char *path, GError **error);

G_END_DECLS
#endif /*  __EXIV2_IMAGEFACTORY_H__ */
