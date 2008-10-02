/*
 * Exiv2.Tests.Nikon3MakerNote.cs
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell, Inc.
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

using NUnit.Framework;
using System;
using System.IO;
using Exiv2;

namespace Exiv2.Tests
{
	[TestFixture]
	public class Nikon3MakerNoteTests
	{
	
		string imagefile = "alex.jpg";
		Image image;

		[SetUp]
		public void SetUp ()
		{
			GLib.GType.Init ();
			File.Copy ("../data/" + imagefile, "./" + imagefile, true);
			image = ImageFactory.Open ("./" + imagefile);
			image.ReadMetadata ();
		}

		[TearDown]
		public void TearDown ()
		{
			try {
				File.Delete ("./" + imagefile);
			} catch {}
		}

		[Test]
		public void TagList1 ()
		{
			TagInfo [] taglist = Nikon1MakerNote.TagList;
			Assert.AreEqual (16, taglist.Length);
		}

		[Test]
		public void TagList2 ()
		{
			TagInfo [] taglist = Nikon2MakerNote.TagList;
			Assert.AreEqual (11, taglist.Length);
		}

		[Test]
		public void TagList3 ()
		{
			TagInfo [] taglist = Nikon3MakerNote.TagList;
			Assert.AreEqual (71, taglist.Length);
		}
	}
}
