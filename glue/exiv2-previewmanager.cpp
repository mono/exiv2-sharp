/*
 * exiv2-previewmanager.cpp
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
#include <glib-object.h>
#include <exiv2/preview.hpp>
#include <vector>
#include "exiv2-image-private.h"
#include "exiv2-previewmanager.h"
#include "exiv2-previewmanager-private.h"
#include "exiv2-previewproperties-private.h"

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

Exiv2PreviewManager*
exiv2_previewmanager_new (Exiv2Image *image)
{
	g_return_val_if_fail (EXIV2_IS_IMAGE (image), NULL);
	
	Exiv2PreviewManager *previewmanager;
	previewmanager = EXIV2_PREVIEWMANAGER (g_object_new (EXIV2_TYPE_PREVIEWMANAGER, NULL));
	previewmanager->priv->manager = new Exiv2::PreviewManager (*(image->priv->imptr));

	return previewmanager;	
}

GList*
exiv2_previewmanager_get_previewProperties (Exiv2PreviewManager *self)
{
	g_return_val_if_fail (EXIV2_IS_PREVIEWMANAGER (self), NULL);
	
	GList* list = NULL;
	std::vector<Exiv2::PreviewProperties>::iterator iter;
	std::vector<Exiv2::PreviewProperties> vector = self->priv->manager->getPreviewProperties ();
	for (iter = vector.begin(); iter != vector.end(); iter++) {
		Exiv2PreviewProperties *prop = EXIV2_PREVIEWPROPERTIES (g_object_new (EXIV2_TYPE_PREVIEWPROPERTIES, NULL));
		prop->priv->prop = new Exiv2::PreviewProperties (*iter);
		list = g_list_prepend (list, prop);
	}

	return g_list_reverse (list);
	
}

G_END_DECLS
