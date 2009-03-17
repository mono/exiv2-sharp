/*
 * exiv2-iptckey.cpp
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

#include "exiv2-key.h"
#include "exiv2-iptckey.h"
#include "exiv2-iptckey-private.h"

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2IptcKey, exiv2_iptckey, EXIV2_TYPE_KEY);

static void exiv2_iptckey_finalize (GObject *gobject);

const char*	exiv2_iptckey_real_to_string 		(Exiv2Key *self);
const char*	exiv2_iptckey_real_get_familyName	(Exiv2Key *self);
const char*	exiv2_iptckey_real_get_groupName		(Exiv2Key *self);
const char*	exiv2_iptckey_real_get_tagName		(Exiv2Key *self);
const char*	exiv2_iptckey_real_get_tagLabel		(Exiv2Key *self);
guint16		exiv2_iptckey_real_get_tag		(Exiv2Key *self);


static void
exiv2_iptckey_init (Exiv2IptcKey *self)
{
	Exiv2IptcKeyPrivate *priv;
	self->priv = priv = EXIV2_IPTCKEY_GET_PRIVATE (self);
}

static void
exiv2_iptckey_class_init (Exiv2IptcKeyClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	gobject_class->finalize = exiv2_iptckey_finalize;

	Exiv2KeyClass *key_class = EXIV2_KEY_CLASS (klass);

	key_class->to_string = exiv2_iptckey_real_to_string;
	key_class->get_familyName = exiv2_iptckey_real_get_familyName;
	key_class->get_groupName = exiv2_iptckey_real_get_groupName;
	key_class->get_tagName = exiv2_iptckey_real_get_tagName;
	key_class->get_tagLabel = exiv2_iptckey_real_get_tagLabel;
	key_class->get_tag = exiv2_iptckey_real_get_tag;

	g_type_class_add_private (klass, sizeof	(Exiv2IptcKeyPrivate));
}

static void
exiv2_iptckey_finalize (GObject *gobject)
{
	Exiv2IptcKey *self = EXIV2_IPTCKEY (gobject);
	if (self->priv->key) {
		delete self->priv->key;
		self->priv->key = NULL;
	}
	G_OBJECT_CLASS (exiv2_iptckey_parent_class)->finalize (gobject);
}

Exiv2IptcKey*
exiv2_iptckey_new (const char* key)
{
	Exiv2IptcKey *iptckey;
	iptckey = EXIV2_IPTCKEY (g_object_new (EXIV2_TYPE_IPTCKEY, NULL));
	iptckey->priv->key = new Exiv2::IptcKey (key);

	return iptckey;	
}

const char*
exiv2_iptckey_real_to_string (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->key ().c_str ();
}

const char*
exiv2_iptckey_real_get_familyName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->familyName ();
}

const char*
exiv2_iptckey_real_get_groupName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->groupName ().c_str ();
}

const char*
exiv2_iptckey_real_get_tagName (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->tagName ().c_str ();
}

const char*
exiv2_iptckey_real_get_tagLabel (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->tagLabel ().c_str ();
}

guint16
exiv2_iptckey_real_get_tag (Exiv2Key *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	Exiv2IptcKey* key = EXIV2_IPTCKEY (self);
	return key->priv->key->tag ();
}

const char*
exiv2_iptckey_get_recordName (Exiv2IptcKey *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	return self->priv->key->recordName ().c_str();
}

guint16
exiv2_iptckey_get_record (Exiv2IptcKey *self)
{
	g_return_val_if_fail (EXIV2_IS_IPTCKEY (self), NULL);
	return self->priv->key->record ();
}

G_END_DECLS
