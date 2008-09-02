#include <exiv2-image.h>
#include <exiv2-imagefactory.h>

void main (int argc, char ** argv)
{
	g_type_init ();
	Exiv2Image* image;
	Exiv2ExifData* exifdata;

	image = exiv2_imagefactory_open (argv [1]);
	exiv2_image_readMetadata (image);
	printf ("%d\n", exiv2_image_get_good (image));
	exifdata = exiv2_image_get_exifData (image);
}
