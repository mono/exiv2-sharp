/*
 * exiv2-exifdata-private.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_EXIFDATA_PRIVATE_H__
#define __EXIV2_EXIFDATA_PRIVATE_H__

#include "exiv2-exifdata.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

struct _Exiv2ExifDataPrivate
{
	Exiv2::ExifData* data;
};

G_END_DECLS

#endif /* __EXIV2_EXIFDATA_PRIVATE_H__ */
