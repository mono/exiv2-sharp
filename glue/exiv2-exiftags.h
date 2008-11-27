/*
 * exiv2-exiftags.h
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
#ifndef __EXIV2_EXIFTAGS_H__
#define __EXIV2_EXIFTAGS_H__

#include <glib-object.h>
#include "exiv2-ifdid.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFTAGS			(exiv2_exiftags_get_type ())
#define EXIV2_EXIFTAGS(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFTAGS, Exiv2ExifTags))
#define EXIV2_IS_EXIFTAGS(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFTAGS))
#define EXIV2_EXIFTAGS_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFTAGS, Exiv2ExifTagsClass))
#define EXIV2_IS_EXIFTAGS_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFTAGS))
#define EXIV2_EXIFTAGS_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFTAGS, Exiv2ExifTagsClass))

typedef struct _Exiv2ExifTags	Exiv2ExifTags;
typedef struct _Exiv2ExifTagsClass	Exiv2ExifTagsClass;

struct _Exiv2ExifTags
{
	GObject parent_instance;

};

struct _Exiv2ExifTagsClass
{
	GObjectClass parent_class;

};

GType 		exiv2_exiftags_get_type 	(void);

const char*	exiv2_exiftags_get_tagName 	(guint16 tag, Exiv2IfdId ifdid);

G_END_DECLS
#endif /*  __EXIV2_EXIFTAGS_H__ */
