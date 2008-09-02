all: ExifPrint.exe

FLAGS=-debug -pkg:glib-sharp-2.0 -pkg:gtk-sharp-2.0

EXIFPRINT_CSFILES = 		\
	$(srcdir)/ExifPrint.cs

EXIFCOMMENT_CSFILES = 		\
	$(srcdir)/ExifComment.cs

ExifPrint.exe: $(EXIFPRINT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

ExifComment.exe: $(EXIFCOMMENT_CSFILES) exiv2-sharp.dll
	gmcs $(FLAGS) -out:$@ $< -r:exiv2-sharp.dll

$(top_builddir)/lib/Exiv2.dll:
	$(MAKE) -C ../lib

exiv2-sharp.dll: $(top_builddir)/exiv2/exiv2-sharp.dll
	cp $< $@

CLEANFILES =			\
	ExifPrint.exe		\
	ExifPrint.exe.mdb	\
	ExifComment.exe		\
	ExifComment.exe.mdb	\
	exiv2-sharp.dll

EXTRA_DIST = 			\
	$(EXIFPRINT_CSFILES)	\
	$(EXIFCOMMENT_CSFILES)
