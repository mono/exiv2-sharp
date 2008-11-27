/*
 * exiv2-exifdatum-iterator.h
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
#ifndef __EXIV2_EXIFDATUMITERATOR_H__
#define __EXIV2_EXIFDATUMITERATOR_H__

#include <glib-object.h>
#include "exiv2-exifdatum.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_EXIFDATUMITERATOR			(exiv2_exifdatumiterator_get_type ())
#define EXIV2_EXIFDATUMITERATOR(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_EXIFDATUMITERATOR, Exiv2ExifDatumIterator))
#define EXIV2_IS_EXIFDATUMITERATOR(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_EXIFDATUMITERATOR))
#define EXIV2_EXIFDATUMITERATOR_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_EXIFDATUMITERATOR, Exiv2ExifDatumIteratorClass))
#define EXIV2_IS_EXIFDATUMITERATOR_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_EXIFDATUMITERATOR))
#define EXIV2_EXIFDATUMITERATOR_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_EXIFDATUMITERATOR, Exiv2ExifDatumIteratorClass))

#define EXIV2_EXIFDATUMITERATOR_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_EXIFDATUMITERATOR, Exiv2ExifDatumIteratorPrivate))

typedef struct _Exiv2ExifDatumIterator		Exiv2ExifDatumIterator;
typedef struct _Exiv2ExifDatumIteratorClass	Exiv2ExifDatumIteratorClass;
typedef struct _Exiv2ExifDatumIteratorPrivate	Exiv2ExifDatumIteratorPrivate;

struct _Exiv2ExifDatumIterator
{
	Exiv2ExifDatum parent_instance;

	/*< private >*/
	Exiv2ExifDatumIteratorPrivate *priv;
};

struct _Exiv2ExifDatumIteratorClass
{
	Exiv2ExifDatumClass parent_class;
};

GType		exiv2_exifdatumiterator_get_type 	(void);

void		exiv2_exifdatumiterator_next		(Exiv2ExifDatumIterator *self);
gboolean	exiv2_exifdatumiterator_equals		(Exiv2ExifDatumIterator *self, Exiv2ExifDatumIterator *other);

G_END_DECLS

#endif /*  __EXIV2_EXIFDATUMITERATOR_H__ */
