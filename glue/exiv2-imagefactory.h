/*
 * exiv2-imagefactory.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_IMAGEFACTORY_H__
#define __EXIV2_IMAGEFACTORY_H__

#include <glib-object.h>
#include <exiv2/image.hpp>

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
	GObject parent_class;

};

GType exiv2_imagefactory_get_type (void);

#endif /*  __EXIV2_IMAGEFACTORY_H__ */
