all: ExifPrint.exe ExifComment.exe AddModel.exe exifprint XmpSample.exe

FLAGS=-debug -pkg:glib-sharp-2.0 -pkg:gtk-sharp-2.0

EXIFPRINT_CSFILES = 		\
	$(srcdir)/ExifPrint.cs

EXIFCOMMENT_CSFILES = 		\
	$(srcdir)/ExifComment.cs

ADDMODEL_CSFILES =		\
	$(srcdir)/AddModel.cs

EXIFPRINT_CFILES =		\
	$(srcdir)/exifprint.c

XMPSAMPLE_CSFILES =		\
	$(srcdir)/XmpSample.cs

ExifPrint.exe: $(EXIFPRINT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

ExifComment.exe: $(EXIFCOMMENT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

AddModel.exe: $(ADDMODEL_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

XmpSample.exe: $(XMPSAMPLE_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

$(top_builddir)/lib/Exiv2.dll:
	$(MAKE) -C ../lib

exiv2-sharp.dll: $(top_builddir)/exiv2/exiv2-sharp.dll
	cp $<* .

exifprint: $(srcdir)/exifprint.c ../glue/.libs/libexiv2glue.so
	gcc -o exifprint -I $(top_srcdir)/glue/ -L $(top_builddir)/glue/.libs/ `pkg-config --libs --cflags gobject-2.0` -lexiv2glue $(srcdir)/exifprint.c

CLEANFILES =			\
	ExifPrint.exe		\
	ExifPrint.exe.mdb	\
	ExifComment.exe		\
	ExifComment.exe.mdb	\
	AddModel.exe		\
	AddModel.exe.mdb	\
	XmpSample.exe		\
	XmpSample.exe.mdb	\
	exifprint		\
	exiv2-sharp.dll		\
	exiv2-sharp.dll.mdb

EXTRA_DIST = 			\
	$(EXIFPRINT_CSFILES)	\
	$(EXIFPRINT_CFILES)	\
	$(ADDMODEL_CSFILES)	\
	$(EXIFCOMMENT_CSFILES)	\
	exifprint.c		\
	AddModel		\
	ExifPrint		\
	ExifComment
