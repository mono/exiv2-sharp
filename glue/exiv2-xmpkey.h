/*
 * exiv2-xmpkey.h
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
#ifndef __EXIV2_XMPKEY_H__
#define __EXIV2_XMPKEY_H__

#include <glib-object.h>
#include "exiv2-key.h"

G_BEGIN_DECLS

#define EXIV2_TYPE_XMPKEY		(exiv2_xmpkey_get_type ())
#define EXIV2_XMPKEY(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_XMPKEY, Exiv2XmpKey))
#define EXIV2_IS_XMPKEY(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_XMPKEY))
#define EXIV2_XMPKEY_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_XMPKEY, Exiv2XmpKeyClass))
#define EXIV2_IS_XMPKEY_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_XMPKEY))
#define EXIV2_XMPKEY_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_XMPKEY, Exiv2XmpKeyClass))

#define EXIV2_XMPKEY_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_XMPKEY, Exiv2XmpKeyPrivate))

typedef struct _Exiv2XmpKey		Exiv2XmpKey;
typedef struct _Exiv2XmpKeyClass	Exiv2XmpKeyClass;
typedef struct _Exiv2XmpKeyPrivate	Exiv2XmpKeyPrivate;

struct _Exiv2XmpKey
{
	Exiv2Key parent_instance;

	/*< private >*/
	Exiv2XmpKeyPrivate *priv;
};

struct _Exiv2XmpKeyClass
{
	Exiv2KeyClass parent_class;
};

GType		exiv2_xmpkey_get_type	 	(void);

Exiv2XmpKey*	exiv2_xmpkey_new 		(const char* key);

const char*	exiv2_xmpkey_get_ns		(Exiv2XmpKey *self);

G_END_DECLS

#endif /*  __EXIV2_XMPKEY_H__ */
