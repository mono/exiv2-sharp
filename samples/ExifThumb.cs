/*
 * ExifThumb.cs: set or get the exif thumbnail
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
	public class ExifThumb
	{
		static void Main (string [] args)
		{
			GLib.GType.Init ();
			try {
				if (args.Length != 3) {
					Console.WriteLine ("Usage: ExifThumb.exe command file thumb");
					Console.WriteLine ("command is 'get' or 'set', file is the image file, thumb is the thumbnail source or destination");
					System.Environment.Exit (1);
				}
				Exiv2.Image image = Exiv2.ImageFactory.Open (args [1]);
				image.ReadMetadata ();
				ExifData exif_data = image.ExifData;
				Exiv2.ExifThumb thumb = exif_data.Thumb;

				switch (args[0]) {
				case "get":
					Console.WriteLine ("thumb mimetype {0}", thumb.MimeType);
					Console.WriteLine ("thumb extensions {0}", thumb.Extension);
					Console.WriteLine (thumb.WriteFile (args[2]));
					break;
				}

			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
