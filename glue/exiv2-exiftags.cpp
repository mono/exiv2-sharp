/*
 * exiv2-exiftags.cpp
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

#include "exiv2-exiftags.h"
#include <exiv2/tags.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifTags, exiv2_exiftags, G_TYPE_OBJECT);

static void
exiv2_exiftags_init (Exiv2ExifTags *self)
{
}

static void
exiv2_exiftags_class_init (Exiv2ExifTagsClass *klass)
{
	
}

const char*
exiv2_exiftags_get_tagName (guint16 tag, Exiv2IfdId ifdid)
{
	return g_strdup (Exiv2::ExifTags::tagName (tag, (Exiv2::IfdId)ifdid).c_str ());
}

G_END_DECLS