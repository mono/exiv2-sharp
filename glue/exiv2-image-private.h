/*
 * exiv2-image-private.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_IMAGE_PRIVATE_H__
#define __EXIV2_IMAGE_PRIVATE_H__

#include "exiv2-image.h"
#include <exiv2/image.hpp>

G_BEGIN_DECLS


struct _Exiv2ImagePrivate
{
	Exiv2::Image* imptr;
};

G_END_DECLS

#endif /* __EXIV2_IMAGE_PRIVATE_H__ */
