all: ExifPrint.exe ExifComment.exe AddModel.exe exifprint

FLAGS=-debug -pkg:glib-sharp-2.0 -pkg:gtk-sharp-2.0

EXIFPRINT_CSFILES = 		\
	$(srcdir)/ExifPrint.cs

EXIFCOMMENT_CSFILES = 		\
	$(srcdir)/ExifComment.cs

ADDMODEL_CSFILES =		\
	$(srcdir)/AddModel.cs

EXIFPRINT_CFILES =		\
	$(srcdir)/exifprint.c

ExifPrint.exe: $(EXIFPRINT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

ExifComment.exe: $(EXIFCOMMENT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

AddModel.exe: $(ADDMODEL_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

$(top_builddir)/lib/Exiv2.dll:
	$(MAKE) -C ../lib

exiv2-sharp.dll: $(top_builddir)/exiv2/exiv2-sharp.dll
	cp $<* .

exifprint: exifprint.c
	gcc -o exifprint -I ../glue/ -L ../glue/.libs/ `pkg-config --libs --cflags gobject-2.0` -lexiv2glue exifprint.c

CLEANFILES =			\
	ExifPrint.exe		\
	ExifPrint.exe.mdb	\
	ExifComment.exe		\
	ExifComment.exe.mdb	\
	exiv2-sharp.dll		\
	exiv2-sharp.dll.mdb

EXTRA_DIST = 			\
	$(EXIFPRINT_CSFILES)	\
	$(EXIFPRINT_CFILES)	\
	$(ADDMODEL_CSFILES)	\
	$(EXIFCOMMENT_CSFILES)	\
	AddModel		\
	ExifPrint		\
	ExifComment
