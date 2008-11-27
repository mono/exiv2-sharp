/*
 * exiv2-key.h
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
#ifndef __EXIV2_KEY_H__
#define __EXIV2_KEY_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EXIV2_TYPE_KEY			(exiv2_key_get_type ())
#define EXIV2_KEY(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), EXIV2_TYPE_KEY, Exiv2Key))
#define EXIV2_IS_KEY(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXIV2_TYPE_KEY))
#define EXIV2_KEY_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), EXIV2_TYPE_KEY, Exiv2KeyClass))
#define EXIV2_IS_KEY_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), EXIV2_TYPE_KEY))
#define EXIV2_KEY_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), EXIV2_TYPE_KEY, Exiv2KeyClass))

typedef struct _Exiv2Key		Exiv2Key;
typedef struct _Exiv2KeyClass		Exiv2KeyClass;

struct _Exiv2Key
{
	GObject parent_instance;
};

struct _Exiv2KeyClass
{
	GObjectClass parent_class;

	/* virtual public methods */
	const char*	(*to_string) 		(Exiv2Key *self);
	const char*	(*get_familyName)	(Exiv2Key *self);
	const char*	(*get_groupName)	(Exiv2Key *self);
	const char*	(*get_tagName)		(Exiv2Key *self);
	const char*	(*get_tagLabel)		(Exiv2Key *self);
	guint16		(*get_tag)		(Exiv2Key *self);	

};

GType		exiv2_key_get_type	 	(void);

const char*	exiv2_key_to_string 		(Exiv2Key *self);
const char*	exiv2_key_get_familyName	(Exiv2Key *self);
const char*	exiv2_key_get_groupName		(Exiv2Key *self);
const char*	exiv2_key_get_tagName		(Exiv2Key *self);
const char*	exiv2_key_get_tagLabel		(Exiv2Key *self);
guint16		exiv2_key_get_tag		(Exiv2Key *self);	

G_END_DECLS

#endif /*  __EXIV2_KEY_H__ */
