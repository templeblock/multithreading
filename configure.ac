dnl Statistics for MySQL

dnl Initialization
AC_INIT([libsqlstat], [1.1], [xypron.glpk@gmx.de])
AM_INIT_AUTOMAKE
LT_INIT

dnl Compiler check
AC_PROG_CC
AC_CHECK_PROG([have_cc],[$CC],[yes],[no])
if test [$have_cc] != [yes]; then
  AC_MSG_ERROR([$CC is missing])
fi

dnl Provide $(LN_S)
AC_PROG_LN_S

dnl Configure macros
AC_CONFIG_MACRO_DIR([m4])

dnl Create config.h
AC_CONFIG_HEADERS([config.h])

CPPFLAGS+=" -I`cd $srcdir && pwd`/src"

dnl Thread support
AX_PTHREAD([have_pthread=yes],[have_pthread=no])
AC_MSG_NOTICE([PTHREAD_CC=$PTHREAD_CC])
AC_MSG_NOTICE([PTHREAD_CPPFLAGS=$PTHREAD_CFLAGS])
AC_MSG_NOTICE([PTHREAD_LIBS=$PTHREAD_LIBS])
CPPFLAGS+=" -pthread"
LDFLAGS+=" -pthread"

AC_MSG_NOTICE([CPPFLAGS = $CPPFLAGS])
AC_MSG_NOTICE([LDFLAGS  = $LDFLAGS])

dnl Check includes
AC_CHECK_HEADER([pthread.h],
  [],
  [AC_MSG_ERROR([pthread.h not found])]
  )

dnl Makefiles
AC_CONFIG_FILES([
  Makefile
  src/Makefile
  test/Makefile
  ])

dnl Generate files
AC_OUTPUT
