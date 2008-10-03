/*
 * exiv2-exifkey.cpp
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

#include "exiv2-key.h"
#include "exiv2-exifkey.h"
#include "exiv2-exifkey-private.h"

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifKey, exiv2_exifkey, EXIV2_TYPE_KEY);

static void exiv2_exifkey_finalize (GObject *gobject);

const char*	exiv2_exifkey_real_to_string 		(Exiv2Key *self);
const char*	exiv2_exifkey_real_get_familyName	(Exiv2Key *self);
const char*	exiv2_exifkey_real_get_groupName	(Exiv2Key *self);
const char*	exiv2_exifkey_real_get_tagName		(Exiv2Key *self);
const char*	exiv2_exifkey_real_get_tagLabel		(Exiv2Key *self);
guint16		exiv2_exifkey_real_get_tag		(Exiv2Key *self);	


static void
exiv2_exifkey_init (Exiv2ExifKey *self)
{
	Exiv2ExifKeyPrivate *priv;
	self->priv = priv = EXIV2_EXIFKEY_GET_PRIVATE (self);
}

static void
exiv2_exifkey_class_init (Exiv2ExifKeyClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_exifkey_finalize;

	Exiv2KeyClass *key_class = EXIV2_KEY_CLASS (klass);

	key_class->to_string = exiv2_exifkey_real_to_string;
	key_class->get_familyName = exiv2_exifkey_real_get_familyName;
	key_class->get_groupName = exiv2_exifkey_real_get_groupName;
	key_class->get_tagName = exiv2_exifkey_real_get_tagName;
	key_class->get_tagLabel = exiv2_exifkey_real_get_tagLabel;
	key_class->get_tag = exiv2_exifkey_real_get_tag;

	g_type_class_add_private (klass, sizeof	(Exiv2ExifKeyPrivate));
}

static void
exiv2_exifkey_finalize (GObject *gobject)
{
	Exiv2ExifKey *self = EXIV2_EXIFKEY (gobject);
	if (self->priv->key) {
		delete self->priv->key;
		self->priv->key = NULL;
	}
	G_OBJECT_CLASS (exiv2_exifkey_parent_class)->finalize (gobject);
}

Exiv2ExifKey*
exiv2_exifkey_new (const char* key)
{
	Exiv2ExifKey *exifkey;
	exifkey = EXIV2_EXIFKEY (g_object_new (EXIV2_TYPE_EXIFKEY, NULL));
	exifkey->priv->key = new Exiv2::ExifKey (key);

	return exifkey;	
}

//Exiv2IfdId*	exiv2_exifkey_get_ifdId 	(Exiv2ExifKey *self)
//{
//	
//}

const char*
exiv2_exifkey_get_ifdName (Exiv2ExifKey *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	return self->priv->key->ifdName ();
}

const char*
exiv2_exifkey_get_sectionName	(Exiv2ExifKey *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	return self->priv->key->sectionName ().c_str ();	
}

gint exiv2_exifkey_get_idx (Exiv2ExifKey *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), -1);
	return self->priv->key->idx ();		
}

const char*
exiv2_exifkey_real_to_string (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->key ().c_str ();
}

const char*
exiv2_exifkey_real_get_familyName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->familyName ();
}

const char*
exiv2_exifkey_real_get_groupName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->groupName ().c_str ();
}

const char*
exiv2_exifkey_real_get_tagName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->tagName ().c_str ();
}

const char*
exiv2_exifkey_real_get_tagLabel (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->tagLabel ().c_str ();
}

guint16
exiv2_exifkey_real_get_tag (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFKEY (self), NULL);
	Exiv2ExifKey* key = EXIV2_EXIFKEY (self);
	return key->priv->key->tag ();
}

G_END_DECLS
