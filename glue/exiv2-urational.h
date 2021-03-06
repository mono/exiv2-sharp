/*
 * exiv2-urational.h
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

#ifndef __EXIV2_URATIONAL_H__
#define __EXIV2_URATIONAL_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_URATIONAL		(exiv2_urational_get_type ())
#define EXIV2_URATIONAL(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_URATIONAL, Exiv2URational))
#define EXIV2_IS_URATIONAL(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_URATIONAL))
#define EXIV2_URATIONAL_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_URATIONAL, Exiv2URationalClass))
#define EXIV2_IS_URATIONAL_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_URATIONAL))
#define EXIV2_URATIONAL_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_URATIONAL, Exiv2URationalClass))

#define EXIV2_URATIONAL_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), EXIV2_TYPE_URATIONAL, Exiv2URationalPrivate))

typedef struct _Exiv2URational		Exiv2URational;
typedef struct _Exiv2URationalClass	Exiv2URationalClass;
typedef struct _Exiv2URationalPrivate	Exiv2URationalPrivate;

struct _Exiv2URational
{
	GObject parent_instance;

	/*< private >*/
	Exiv2URationalPrivate *priv;
};

struct _Exiv2URationalClass
{
	GObjectClass parent_class;
};

GType			exiv2_urational_get_type 	(void);

Exiv2URational*		exiv2_urational_new (guint32 numerator, guint32 denominator);
guint32			exiv2_urational_getNumerator	(Exiv2URational *self);
void			exiv2_urational_setNumerator	(Exiv2URational *self, guint32 numerator);
guint32			exiv2_urational_getDenominator	(Exiv2URational *self);
void			exiv2_urational_setDenominator	(Exiv2URational *self, guint32 denominator);

G_END_DECLS

#endif /*  __EXIV2_URATIONAL_H__ */
