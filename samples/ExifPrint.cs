/*
 * ExifPrint.cs: c# port of http://www.exiv2.org/doc/exifprint_8cpp-example.html
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
	public class ExifPrint
	{
		static void Main (string [] args)
		{
			try {

				GLib.GType.Init ();

				GLib.LogFunc logFunc = new GLib.LogFunc (GLib.Log.PrintTraceLogFunction);
				GLib.Log.SetLogHandler ("GLib", GLib.LogLevelFlags.Critical, logFunc);
				GLib.Log.SetLogHandler ("GLib-GObject", GLib.LogLevelFlags.Critical, logFunc);
				GLib.Log.SetLogHandler ("GLib-GObject", GLib.LogLevelFlags.Warning, logFunc);
				if (args.Length != 1) {
					Console.WriteLine ("Usage: ExifPrint.exe file");
					System.Environment.Exit (1);
				}
				Exiv2.Image image = Exiv2.ImageFactory.Open (args [0]);
				image.ReadMetadata ();

				Console.WriteLine (image.Good);

				ExifData exif_data = image.ExifData;
				if (exif_data.IsEmpty) {
					Console.WriteLine ("No Exif data found in file");
					return;
				}

				Console.WriteLine ("Exif count: {0}", exif_data.Count);

				foreach (ExifDatum datum in exif_data)
					Console.WriteLine ("{0} {1} {2} {3} {4}",
							datum.Key,
							datum.Tag, 
							datum.Typename,
							datum.Count,
							datum.ToString ());

			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
