#!/bin/sh

test -f configure.ac || {
  echo "Please, run this script in the top level project directory."
  exit
}

libtoolize --force --copy
aclocal -I m4
autoconf
autoheader
automake --add-missing --copy

