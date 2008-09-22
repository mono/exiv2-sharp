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
			foreach (string image in images)
				OpenAsyncPath (image);		
			System.Threading.Thread.Sleep (1000);
		}

		void OpenAsyncPath (string file)
		{
			ImageFactory.OpenAsync (file, null, OpenAsyncCompleted);
		}

		void OpenAsyncCompleted (object o, OpenCompletedEventArgs args)
		{
			Assert.IsNull (o);
			Assert.IsNotNull (args);
			Assert.IsFalse (args.Cancelled);
			Assert.IsNull (args.Error);
			Assert.IsTrue(args.Result.Good);
		}
	}
}
