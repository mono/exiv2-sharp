/*
 * AddModel.cs - c# port of http://www.exiv2.org/doc/addmoddel_8cpp-example.html
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell
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

using System;
using Exiv2;

namespace Sample
{
	public class AddModel
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
					Console.WriteLine ("Usage: AddModel.exe file");
					System.Environment.Exit (1);
				}

				// Container for exif metadata. This is an example of creating
				// exif metadata from scratch. If you want to add, modify, delete
				// metadata that exists in an image, start with ImageFactory.Open
				ExifData exifData = new ExifData ();

				//Add to the Exif data

				// This is the quickest way to add (simple) Exif data. If a metadatum for
				// a given key already exists, its value is overwritten. Otherwise a new
				// tag is added.
				exifData["Exif.Image.Model"] = "Test 1";				// AsciiValue
				exifData["Exif.Image.SamplesPerPixel"] = (UInt16)162;			// UShortValue
				exifData["Exif.Image.XResolution"] = (Int32)(-2);			// LongValue
				exifData["Exif.Image.YResolution"] = new Exiv2.Rational (-2, 3);	// RationalValue
				exifData["Exif.Photo.DateTimeOriginal"] = "1999:12:31 23:59:59";	// AsciiValue
				Console.WriteLine ("Added a few tags the quick way.");

				// Modify Exif data

				// Since we know that the metadatum exists (or we don't mind creating a new
				// tag if it doesn't), we can simply do this:
				ExifDatum tag = exifData["Exif.Photo.DateTimeOriginal"] as ExifDatum;
				string date = tag.ToString ();
				date = "2000" + ((date.Length > 4) ? date.Substring (4) : null);
				tag.Value = date;
				Console.WriteLine ("Modified key '{0}', new value '{1}'", tag.Key, tag.ToString ());

//				tag.setValue(date);
//				std::cout << "Modified key \"" << key
//				          << "\", new value \"" << tag.value() << "\"\n";
//				
//				// Alternatively, we can use findKey()
//				key = Exiv2::ExifKey("Exif.Image.PrimaryChromaticities");
//				Exiv2::ExifData::iterator pos = exifData.findKey(key);
//				if (pos == exifData.end()) throw Exiv2::Error(1, "Key not found");
//				// Get a pointer to a copy of the value
//				v = pos->getValue();
//				// Downcast the Value pointer to its actual type
//				Exiv2::URationalValue* prv = dynamic_cast<Exiv2::URationalValue*>(v.release());
//				if (prv == 0) throw Exiv2::Error(1, "Downcast failed");
//				rv = Exiv2::URationalValue::AutoPtr(prv);
//				// Modify the value directly through the interface of URationalValue
//				rv->value_[2] = std::make_pair(88,77);
//				// Copy the modified value back to the metadatum
//				pos->setValue(rv.get());
//				std::cout << "Modified key \"" << key
//				          << "\", new value \"" << pos->value() << "\"\n";


				exifData.Erase ("Exif.Image.XResolution");

				//Finally, write the remaining data to the image file
				Exiv2.Image image = ImageFactory.Open (args [0]);
				image.ExifData = exifData;
				image.WriteMetadata ();

			} catch (GLib.GException e) {
				Console.WriteLine ("caught a GException {0}", e);
			}
		}
	}
}


