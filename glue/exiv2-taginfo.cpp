/*
 * exiv2-taginfo.cpp
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
#include <exiv2/tags.hpp>
#include "exiv2-taginfo.h"
#include "exiv2-taginfo-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2TagInfo, exiv2_taginfo, G_TYPE_OBJECT);

static void
exiv2_taginfo_init (Exiv2TagInfo *self)
{
	Exiv2TagInfoPrivate *priv;
	self->priv = priv = EXIV2_TAGINFO_GET_PRIVATE (self);

	/* Initialize members */
}

static void
exiv2_taginfo_class_init (Exiv2TagInfoClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2TagInfoPrivate));
}

guint16
exiv2_taginfo_get_tag (Exiv2TagInfo *self)
{
	g_return_val_if_fail (EXIV2_IS_TAGINFO (self), 0);
	return self->priv->taginfo->tag_;	
}

const char*
exiv2_taginfo_get_name (Exiv2TagInfo *self)
{
	g_return_val_if_fail (EXIV2_IS_TAGINFO (self), NULL);
	return self->priv->taginfo->name_;	
}

const char*
exiv2_taginfo_get_title	(Exiv2TagInfo *self)
{
	g_return_val_if_fail (EXIV2_IS_TAGINFO (self), NULL);
	return self->priv->taginfo->title_;	
}

const char*
exiv2_taginfo_get_desc (Exiv2TagInfo *self)
{
	g_return_val_if_fail (EXIV2_IS_TAGINFO (self), NULL);
	return self->priv->taginfo->desc_;	
}

G_END_DECLS
