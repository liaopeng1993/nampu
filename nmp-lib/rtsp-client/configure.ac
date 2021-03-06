# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(libnmprtspclient, 2.0.0, bugs@nampu.com)
AC_CONFIG_SRCDIR([src/fnc_log.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE(foreign)

: ${CFLAGS=""}

# Checks for programs.
AC_PROG_CC
AM_PROG_AR

# Checks for libraries.
AC_PROG_RANLIB

# FIXME: Replace `main' with a function in `-lev':
AC_CHECK_LIB(ev, ev_io_init)

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netinet/in.h stdint.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

PKG_PROG_PKG_CONFIG()
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.2 gthread-2.0 gobject-2.0])

CFLAGS="$CFLAGS $GLIB_CFLAGS"
LIBS="$LIBS $GLIB_LIBS"

# Checks for library functions.
AC_CHECK_FUNCS([memset socket strstr])

AC_MSG_NOTICE([FOUND CFLAGS DEFINES : "$CFLAGS"])
AC_MSG_NOTICE([FOUND CPPFLAGS DEFINES : "$CPPFLAGS"])
AC_MSG_NOTICE([FOUND LIBS DEFINES : "$LIBS"])

AC_CONFIG_FILES([Makefile
		src/Makefile
		test/Makefile])
AC_OUTPUT
