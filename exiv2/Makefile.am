all: exiv2-sharp.dll

codegen: exiv2-api.xml
	gapi2-codegen --outdir=generated --customdir=$(srcdir) --generate exiv2-api.xml

exiv2-sharp.dll: codegen $(SOURCES)
	gmcs -unsafe -pkg:glib-sharp-2.0 -target:library -out:exiv2-sharp.dll generated/*.cs $(SOURCES)

exiv2-api.xml: $(srcdir)/exiv2-api.raw $(srcdir)/Exiv2.metadata
	cp $(srcdir)/exiv2-api.raw exiv2-api.xml
	chmod +w $(builddir)/exiv2-api.xml
	gapi2-fixup --api=exiv2-api.xml --metadata=$(srcdir)/Exiv2.metadata

CUSTOMS =					\
	$(srcdir)/ExifData.custom		\
	$(srcdir)/ExifDatum.custom		\
	$(srcdir)/ExifDatumIterator.custom	\
	$(srcdir)/ImageFactory.custom		\
	$(srcdir)/XmpDatum.custom

SOURCES =					\
	$(srcdir)/OpenCompletedEventArgs.cs	\
	$(srcdir)/OpenCompletedEventHandler.cs

CLEANFILES =			\
	exiv2-api.xml		\
	exiv2-sharp.dll		\
	*.mdb

EXTRA_DIST =		\
	$(SOURCES)	\
	$(CUSTOMS)	\
	exiv2-api.raw	\
	generated/*.cs	\
	Exiv2.metadata	

.PHONY = codegen all
