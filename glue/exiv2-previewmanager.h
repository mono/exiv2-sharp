/*
 * exiv2-previewmanager.h
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
#ifndef __EXIV2_PREVIEWMANAGER_H__
#define __EXIV2_PREVIEWMANAGER_H__

#include <glib-object.h>
#include "exiv2-image.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_PREVIEWMANAGER		(exiv2_previewmanager_get_type ())
#define EXIV2_PREVIEWMANAGER(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_PREVIEWMANAGER, Exiv2PreviewManager))
#define EXIV2_IS_PREVIEWMANAGER(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_PREVIEWMANAGER))
#define EXIV2_PREVIEWMANAGER_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_PREVIEWMANAGER, Exiv2PreviewManagerClass))
#define EXIV2_IS_PREVIEWMANAGER_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_PREVIEWMANAGER))
#define EXIV2_PREVIEWMANAGER_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_PREVIEWMANAGER, Exiv2PreviewManagerClass))
#define EXIV2_PREVIEWMANAGER_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_PREVIEWMANAGER, Exiv2PreviewManagerPrivate))

typedef struct _Exiv2PreviewManager		Exiv2PreviewManager;
typedef struct _Exiv2PreviewManagerClass	Exiv2PreviewManagerClass;
typedef struct _Exiv2PreviewManagerPrivate	Exiv2PreviewManagerPrivate;

struct _Exiv2PreviewManager
{
	GObject parent_instance;

	/*< private >*/
	Exiv2PreviewManagerPrivate *priv;
};

struct _Exiv2PreviewManagerClass
{
	GObjectClass parent_class;

};

GType 			exiv2_previewmanager_get_type		(void);

Exiv2PreviewManager*	exiv2_previewmanager_new			(Exiv2Image *image);
GList*			exiv2_previewmanager_get_previewProperties	(Exiv2PreviewManager *self);

G_END_DECLS

#endif /*  __EXIV2_PREVIEWMANAGER_H__ */
