all: $(TARGETS)

TARGETS =		\
	ExifPrint.exe	\
	ExifComment.exe	\
	AddModel.exe	\
	exifprint	\
	XmpSample.exe	\
	ImageInfo.exe	\
	ExifThumb.exe

FLAGS=-debug -pkg:glib-sharp-2.0 -pkg:gtk-sharp-2.0

%.exe: %.cs exiv2-sharp.dll
	gmcs $(FLAGS) $< -r:exiv2-sharp.dll

$(top_builddir)/lib/Exiv2.dll:
	$(MAKE) -C ../lib

exiv2-sharp.dll: $(top_builddir)/exiv2/exiv2-sharp.dll
	cp $<* .

exifprint: $(srcdir)/exifprint.c ../glue/.libs/libexiv2glue.so
	gcc -o exifprint -I $(top_srcdir)/glue/ -L $(top_builddir)/glue/.libs/ `pkg-config --libs --cflags gobject-2.0` -lexiv2glue $(srcdir)/exifprint.c

CLEANFILES =			\
	*.exe			\
	*.dll			\
	*.mdb

EXTRA_DIST = 			\
	*.cs			\
	exifprint.c		\
	AddModel		\
	ExifPrint		\
	ExifComment		\
	XmpSample		\
	ImageInfo		\
	ExifThumb

