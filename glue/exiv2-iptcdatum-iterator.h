/*
 * exiv2-iptcdatum-iterator.h
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *	Mike Gemuende (mike@gemuende.de)
 *
 * Copyright (c) 2008-2009 Novell, Inc
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
#ifndef __EXIV2_IPTCDATUMITERATOR_H__
#define __EXIV2_IPTCDATUMITERATOR_H__

#include <glib-object.h>
#include "exiv2-iptcdatum.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_IPTCDATUMITERATOR			(exiv2_iptcdatumiterator_get_type ())
#define EXIV2_IPTCDATUMITERATOR(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_IPTCDATUMITERATOR, Exiv2IptcDatumIterator))
#define EXIV2_IS_IPTCDATUMITERATOR(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_IPTCDATUMITERATOR))
#define EXIV2_IPTCDATUMITERATOR_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_IPTCDATUMITERATOR, Exiv2IptcDatumIteratorClass))
#define EXIV2_IS_IPTCDATUMITERATOR_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_IPTCDATUMITERATOR))
#define EXIV2_IPTCDATUMITERATOR_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_IPTCDATUMITERATOR, Exiv2IptcDatumIteratorClass))

#define EXIV2_IPTCDATUMITERATOR_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_IPTCDATUMITERATOR, Exiv2IptcDatumIteratorPrivate))

typedef struct _Exiv2IptcDatumIterator		Exiv2IptcDatumIterator;
typedef struct _Exiv2IptcDatumIteratorClass	Exiv2IptcDatumIteratorClass;
typedef struct _Exiv2IptcDatumIteratorPrivate	Exiv2IptcDatumIteratorPrivate;

struct _Exiv2IptcDatumIterator
{
	Exiv2IptcDatum parent_instance;

	/*< private >*/
	Exiv2IptcDatumIteratorPrivate *priv;
};

struct _Exiv2IptcDatumIteratorClass
{
	Exiv2IptcDatumClass parent_class;
};

GType		exiv2_iptcdatumiterator_get_type 	(void);

void		exiv2_iptcdatumiterator_next		(Exiv2IptcDatumIterator *self);
gboolean	exiv2_iptcdatumiterator_equals		(Exiv2IptcDatumIterator *self, Exiv2IptcDatumIterator *other);

G_END_DECLS

#endif /*  __EXIV2_IPTCDATUMITERATOR_H__ */

