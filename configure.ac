AC_INIT([pisica-app], [1.0], [student@glaic3n203])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CXX
AX_PTHREAD([
    AX_PTHREAD_TARGET_LOCAL=yes
], [
    AC_MSG_ERROR([Este nevoie de suport pentru pthreads pentru a rula aplicatia.])
])
PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.0])
AC_SUBST([GTK_CFLAGS])
AC_SUBST([GTK_LIBS])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
