/*
 * exiv2-exifdatum-private.h
 *
 * Author(s)
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details.
 */

#ifndef __EXIV2_EXIFDATUM_PRIVATE_H__
#define __EXIV2_EXIFDATUM_PRIVATE_H__

#include "exiv2-exifdatum.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

struct _Exiv2ExifDatumPrivate
{
	Exiv2::ExifMetadata::iterator iterator;
};

G_END_DECLS

#endif /* __EXIV2_EXIFDATUM_PRIVATE_H__ */
