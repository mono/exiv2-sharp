/*
 * exiv2-key.cpp
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

#include "exiv2-key.h"

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2Key, exiv2_key, G_TYPE_OBJECT);

static void
exiv2_key_init (Exiv2Key *self)
{
}

static void
exiv2_key_class_init (Exiv2KeyClass *klass)
{
	klass->to_string = NULL;	
	klass->get_familyName = NULL;
	klass->get_groupName = NULL;
	klass->get_tagName = NULL;	
	klass->get_tagLabel = NULL;	
	klass->get_tag = NULL;
}

const char*
exiv2_key_to_string (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->to_string (self);
}

const char*
exiv2_key_get_familyName (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->get_familyName (self);
}

const char*
exiv2_key_get_groupName (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->get_groupName (self);
}

const char*
exiv2_key_get_tagName (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->get_tagName (self);
}

const char*
exiv2_key_get_tagLabel (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->get_tagLabel (self);	
}

guint16
exiv2_key_get_tag (Exiv2Key *self)
{
	return EXIV2_KEY_GET_CLASS (self)->get_tag (self);	
}

G_END_DECLS
