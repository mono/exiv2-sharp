#include <exiv2-image.h>
#include <exiv2-imagefactory.h>

void main (int argc, char ** argv)
{
	g_type_init ();
	Exiv2Image* image;
	Exiv2ExifData* exifdata;
	Exiv2ExifDatumIterator* it;
	Exiv2ExifDatumIterator* end;

	image = exiv2_imagefactory_open (argv [1], NULL);
	exiv2_image_readMetadata (image, NULL);
	printf ("%d\n", exiv2_image_get_good (image));
	exifdata = exiv2_image_get_exifData (image);
	it = exiv2_exifdata_begin (exifdata);
	end = exiv2_exifdata_end (exifdata);

	while (!exiv2_exifdatumiterator_equals (it, end)) {
		printf ("%s %s\n", exiv2_exifdatum_get_key (it), exiv2_exifdatum_toString (it));
		exiv2_exifdatumiterator_next (it);
	}
}
