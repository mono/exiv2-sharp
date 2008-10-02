/*
 * exiv2-nikon2makernote.h
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
#ifndef __EXIV2_NIKON2MAKERNOTE_H__
#define __EXIV2_NIKON2MAKERNOTE_H__

#include <glib-object.h>
#include <exiv2/nikonmn.hpp>
#include "exiv2-taginfo.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_NIKON2MAKERNOTE		(exiv2_nikon2makernote_get_type ())
#define EXIV2_NIKON2MAKERNOTE(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_NIKON2MAKERNOTE, Exiv2Nikon2MakerNote))
#define EXIV2_IS_NIKON2MAKERNOTE(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_NIKON2MAKERNOTE))
#define EXIV2_NIKON2MAKERNOTE_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_NIKON2MAKERNOTE, Exiv2Nikon2MakerNoteClass))
#define EXIV2_IS_NIKON2MAKERNOTE_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_NIKON2MAKERNOTE))
#define EXIV2_NIKON2MAKERNOTE_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_NIKON2MAKERNOTE, Exiv2Nikon2MakerNoteClass))

#define EXIV2_NIKON2MAKERNOTE_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_NIKON2MAKERNOTE, Exiv2Nikon2MakerNotePrivate))

typedef struct _Exiv2Nikon2MakerNote	Exiv2Nikon2MakerNote;
typedef struct _Exiv2Nikon2MakerNoteClass	Exiv2Nikon2MakerNoteClass;

struct _Exiv2Nikon2MakerNote
{
	GObject parent_instance;

	/*< private >*/
};

struct _Exiv2Nikon2MakerNoteClass
{
	GObjectClass parent_class;

};

GType 		exiv2_nikon2makernote_get_type		(void);

Exiv2TagInfo*	exiv2_nikon2makernote_tagList_item	(int item);

G_END_DECLS

#endif /*  __EXIV2_NIKON2MAKERNOTE_H__ */
