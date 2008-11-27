/*
 * ExifComment.cs: c# port of http://www.exiv2.org/doc/exifcomment_8cpp-example.html
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
	public class ExifComment
	{
		static void Main (string [] args)
		{
			GLib.GType.Init ();
			try {
				if (args.Length != 1) {
					Console.WriteLine ("Usage: Previews.exe file");
					System.Environment.Exit (1);
				}
				Exiv2.Image image = Exiv2.ImageFactory.Open (args [0]);
				image.ReadMetadata ();

				PreviewManager manager = image.PreviewManager;
				Console.WriteLine ("manager.PreviewProperties.Count = {0}", manager.PreviewProperties.Count);
				foreach (PreviewProperties prop in manager.PreviewProperties) {
					Console.WriteLine ("\t t:{0} e:{1} s:{2} w:{3} h:{4}", prop.MimeType, prop.Extension, prop.Size, prop.Width, prop.Height );
					PreviewImage prev = manager.GetPreviewImage (prop);
					Console.WriteLine ("t\t t:{0} e:{1} s:{2}", prev.MimeType, prev.Extension, prev.Size);
				}
			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
