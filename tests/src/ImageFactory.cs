/*
 * Exiv2.Tests.ImageFactory.cs
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
	public class ImageFactoryTests
	{
	
		string [] images = {
			"alex.jpg",
		};

		[SetUp]
		public void SetUp ()
		{
			GLib.GType.Init ();
			foreach (string image in images)
				File.Copy ("../data/" + image, "./" + image, true);
		}

		[TearDown]
		public void TearDown ()
		{
			foreach (string image in images)
				try {
					File.Delete ("./" + image);
				} catch {}
		}

		[Test]
		public void OpenPath ()
		{
			foreach (string image in images)
				OpenPath (image);
		}

		void OpenPath (string file)
		{
			Image image = ImageFactory.Open ("./" + file);
			Assert.IsTrue (image.Good, String.Format ("Exiv2.Image.Good returned false for {0}", file));
		}

		[Test]
		public void OpenByteArray ()
		{
			foreach (string image in images)
				OpenByteArray (image);	
		}

		void OpenByteArray (string file)
		{
			FileStream fs = new FileStream ("./" + file, FileMode.Open, FileAccess.Read);
			byte [] buffer = new byte [fs.Length];
			int count = (int)fs.Read (buffer, 0, (int)fs.Length);
			Assert.IsTrue (count > 0);
			Image image = ImageFactory.Open (buffer);
			Assert.IsTrue (image.Good, String.Format ("Exiv2.Image.Good returned false for {0}", file));
		}

		[Test]
		public void OpenAsyncPath ()
		{
			foreach (string image in images) {
				OpenAsyncPath (image);		
				System.Threading.Thread.Sleep (200);
				OpenAsyncTests ();
			}
		}

		void OpenAsyncPath (string file)
		{
			ImageFactory.OpenAsync (file, null, OpenAsyncCompleted);
		}

		[Test]
		public void OpenAsyncStream ()
		{
			foreach (string image in images) {
				OpenAsyncStream (image);		
				System.Threading.Thread.Sleep (200); //wait for thread termination
				OpenAsyncTests ();
			}
		}

		void OpenAsyncStream (string file)
		{
			FileStream fs = new FileStream ("./" + file, FileMode.Open, FileAccess.Read);
			ImageFactory.OpenAsync (fs, null, OpenAsyncCompleted);	
		}


		OpenCompletedEventArgs args;
		void OpenAsyncCompleted (object o, OpenCompletedEventArgs args)
		{
			this.args = args;
		}

		void OpenAsyncTests ()
		{
			Assert.IsNotNull (args);
			Assert.IsFalse (args.Cancelled);
			Assert.IsNull (args.Error);
			Assert.IsNotNull (args.Result);
			Assert.IsTrue(args.Result.Good);
		}
	}
}
