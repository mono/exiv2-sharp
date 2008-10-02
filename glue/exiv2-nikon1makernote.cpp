/*
 * exiv2-nikon1makernote.cpp
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
#include <glib-object.h>
#include "exiv2-nikon1makernote.h"
#include "exiv2-taginfo-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2Nikon1MakerNote, exiv2_nikon1makernote, G_TYPE_OBJECT);

static void
exiv2_nikon1makernote_init (Exiv2Nikon1MakerNote *self)
{
	/* Initialize members */
}

static void
exiv2_nikon1makernote_class_init (Exiv2Nikon1MakerNoteClass *klass)
{
}

Exiv2TagInfo*
exiv2_nikon1makernote_tagList_item (int item)
{
	Exiv2TagInfo *taginfo;
	const Exiv2::TagInfo *native_taginfo = &(Exiv2::Nikon1MakerNote::tagList () [item]);
	if (native_taginfo->tag_ == 0xffff)
		return NULL;
	taginfo = EXIV2_TAGINFO (g_object_new (EXIV2_TYPE_TAGINFO, NULL));
	taginfo->priv->taginfo = native_taginfo;
	return taginfo;	
}

G_END_DECLS
