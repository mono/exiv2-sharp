/*
 * XmpSample: some tests using Xmp
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
	public class XmpSample
	{
		static void Main (string [] args)
		{
			try {

				GLib.GType.Init ();

				GLib.LogFunc logFunc = new GLib.LogFunc (GLib.Log.PrintTraceLogFunction);
				GLib.Log.SetLogHandler ("GLib", GLib.LogLevelFlags.Critical, logFunc);
				GLib.Log.SetLogHandler ("GLib-GObject", GLib.LogLevelFlags.Critical, logFunc);
				GLib.Log.SetLogHandler ("GLib-GObject", GLib.LogLevelFlags.Warning, logFunc);
				if (args.Length == 0) {
					Console.WriteLine ("Usage: XmpSample.exe [file list]");
					System.Environment.Exit (1);
				}
				
				foreach (string file in args) {
					Console.WriteLine ("File {0}", file);
					Exiv2.Image image = Exiv2.ImageFactory.Open (file);
					image.ReadMetadata ();

					Console.WriteLine (image.Good);

					XmpData xmp_data = image.XmpData;
					if (xmp_data.IsEmpty)
						Console.WriteLine ("No XMP data found in file");

					Console.WriteLine ("Xmp count: {0}", xmp_data.Count);
	
					foreach (XmpDatum datum in xmp_data)
						Console.WriteLine ("{0} {1} {2} {3}", datum.Key, datum.Typename, datum.Count, datum.ToString ());

				}
					
			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
