dnl Process this file with autoconf to produce a configure script.
AC_INIT(exiv2-sharp, 0.3.1, stephane@delcroix.org)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(glue/exiv2-imagefactory.cpp)

AM_INIT_AUTOMAKE

AC_PROG_CXX

AC_PROG_LIBTOOL

PKG_CHECK_MODULES(EXIV2, exiv2 >= 0.17)
PKG_CHECK_MODULES(GLIB, glib-2.0)
PKG_CHECK_MODULES(GOBJECT, gobject-2.0)

AC_OUTPUT(
Makefile 
exiv2/Makefile
glue/Makefile
sources/Makefile
samples/Makefile
docs/Makefile
)
