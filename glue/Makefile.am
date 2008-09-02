lib_LTLIBRARIES = libexiv2glue.la

INCLUDES =				\
	$(EXIV2_CFLAGS)			\
	$(GLIB_CFLAGS)			\
	$(GOBJECT_CFLAGS)

libexiv2glue_la_SOURCES =			\
	exiv2-exifdata.cpp			\
	exiv2-exifdata.h			\
	exiv2-exifdata-private.h		\
	exiv2-exifdatum.cpp			\
	exiv2-exifdatum.h			\
	exiv2-exifdatum-private.h		\
	exiv2-exifdatum-iterator.cpp		\
	exiv2-exifdatum-iterator.h		\
	exiv2-exifdatum-iterator-private.h	\
	exiv2-exifkey.cpp			\
	exiv2-exifkey.h				\
	exiv2-exifkey-private.h			\
	exiv2-image.cpp				\
	exiv2-image.h				\
	exiv2-image-private.h			\
	exiv2-imagefactory.cpp			\
	exiv2-imagefactory.h			\
	exiv2-key.cpp				\
	exiv2-key.h

libexiv2glue_la_INCLUDES =		\
	exiv2-exifdata.h		\
	exiv2-image.h			\
	exiv2-imagefactory.h

libexiv2glue_la_LIBADD =		\
	$(EXIV2_LIBS)			\
	$(GLIB_LIBS)			\
	$(GOBJECT_LIBS)
	

