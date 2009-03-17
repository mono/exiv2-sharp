/*
 * IptcSample: some tests using Iptc
 *
 * Author(s):
 *	Stephane Delcroix  <stephane@delcroix.org>
 *	Mike Gemuende <mike@gemuende.de>
 *
 * This is free software. See COPYING for details
 */

using System;
using Exiv2;

namespace Sample
{
	public class IptcSample
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
					Console.WriteLine ("Usage: IptcSample.exe [file list]");
					System.Environment.Exit (1);
				}
				
				foreach (string file in args) {
					Console.WriteLine ("File {0}", file);
					Exiv2.Image image = Exiv2.ImageFactory.Open (file);
					image.ReadMetadata ();

					Console.WriteLine (image.Good);
	
					IptcData iptc_data = image.IptcData;
					if (iptc_data.IsEmpty)
						Console.WriteLine ("No Iptc data found in file");

					Console.WriteLine ("Iptc count: {0}", iptc_data.Count);

					foreach (IptcDatum datum in iptc_data)
						Console.WriteLine ("{0} {1} {2} {3}", datum.Key, datum.Typename, datum.Count, datum.ToString ());
				}
				

			} catch (GLib.GException e) {
				Console.WriteLine ("Exiv2.Exception caught {0}", e);
			}
		}
	}
}
