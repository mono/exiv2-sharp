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
			try {
				if (args.Length != 1) {
					Console.WriteLine ("Usage: ExifPrint.exe file");
					System.Environment.Exit (1);
				}
				Exiv2.Image image = Exiv2.ImageFactory.Open (args [0]);
				image.ReadMetadata ();
				ExifData exif_data = image.ExifData;

				/*
				Exiv2 uses a CommentValue for Exif user comments. The format of the
				comment string includes an optional charset specification at the beginning:

				[charset=["]Ascii|Jis|Unicode|Undefined["] ]comment
				
				Undefined is used as a default if the comment doesn't start with a charset
				definition.
				
				Following are a few examples of valid comments. The last one is written to
				the file.
				*/
				Console.WriteLine ("usercomment {0}", exif_data ["Exif.Photo.UserComment"].ToString ());
				Console.WriteLine ("usercomment {0}", exif_data ["Exif.Photo.UserComment"].ToString ());
				Console.WriteLine ("usercomment {0}", exif_data ["Exif.Photo.UserComment"].ToString ());

			//	exif_data["Exif.Photo.UserComment"] = "charset=\"Unicode\" An Unicode Exif comment added with Exiv2";
			//	exif_data["Exif.Photo.UserComment"] = "charset=\"Undefined\" An undefined Exif comment added with Exiv2";
			//	exif_data["Exif.Photo.UserComment"] = "Another undefined Exif comment added with Exiv2";
				exif_data["Exif.Photo.UserComment"] = "charset=Ascii An ASCII Exif comment added with Exiv2-sharp";
				image.WriteMetadata ();
				Console.WriteLine ("Writing user comment '{0}' back to the image", exif_data ["Exif.Photo.UserComment"]);
				

			} catch (Exiv2Exception e) {
				Console.WriteLine ("Exiv2.Exception caught {0} {1}", e.Code, e.What);
			}
		}
	}
}
