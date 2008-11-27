/*
 * exiv2-previewmanager.cpp
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
#include <exiv2/preview.hpp>
#include "exiv2-previewmanager.h"
#include "exiv2-previewmanager-private.h"

G_BEGIN_DECLS
G_DEFINE_TYPE (Exiv2PreviewManager, exiv2_previewmanager, G_TYPE_OBJECT);

static void
exiv2_previewmanager_init (Exiv2PreviewManager *self)
{
	Exiv2PreviewManagerPrivate *priv;
	self->priv = priv = EXIV2_PREVIEWMANAGER_GET_PRIVATE (self);

	/* Initialize members */
}

static void
exiv2_previewmanager_class_init (Exiv2PreviewManagerClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2PreviewManagerPrivate));
}

G_END_DECLS
