/*
 * ImageInfo.cs: get the image level info
 *
 * Author(s):
 *	Stephane Delcroix  <stephane@delcroix.org>
 *
 * This is free software. See COPYING for details
 */

using System;
using Exiv2;

namespace Sample
{
	public class ImageInfo
	{
		static void Main (string [] args)
		{
			GLib.GType.Init ();
			try {
				if (args.Length != 1) {
					Console.WriteLine ("Usage: ExifPrint.exe file");
					System.Environment.Exit (1);
				}
				Exiv2.Image image = Exiv2.ImageFactory.Open (args [0]);
				if (!image.Good)
					return;
				image.ReadMetadata ();

				Console.WriteLine ("Mime type: {0}", image.MimeType);
				Console.WriteLine ("pixel width: {0}", image.PixelWidth);
				Console.WriteLine ("pixel height: {0}", image.PixelHeight);
			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
