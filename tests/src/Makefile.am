all: run-tests

TESTASSEMBLY = exiv2.tests.dll

SOURCES =			\
	ExifThumb.cs		\
	Image.cs		\
	ImageFactory.cs

PKGS =				\
	-pkg:mono-nunit		\
	-pkg:gtk-sharp-2.0	\
	-pkg:glib-sharp-2.0

REFS =				\
	-r:$(top_builddir)/exiv2/exiv2-sharp.dll

FLAGS = -g -t:library

$(TESTASSEMBLY): $(SOURCES)
	gmcs $(FLAGS) $(PKGS) $(REFS) $(SOURCES) -out:$@

run-tests: $(TESTASSEMBLY)
	MONO_PATH=$(top_builddir)/exiv2/ LD_LIBRARY_PATH=$(top_builddir)/glue/.libs/ nunit-console2 $(TESTASSEMBLY)

run-gui: $(TESTASSEMBLY)
	MONO_PATH=$(top_builddir)/exiv2/ LD_LIBRARY_PATH=$(top_builddir)/glue/.libs/ gnunit2 $(TESTASSEMBLY)


EXTRA_DIST =		\
	$(SOURCES)

CLEANFILES =		\
	*~		\
	TestResults.xml	\
	$(TESTASSEMBLY)*

.PHONY = all run-tests run-gui
