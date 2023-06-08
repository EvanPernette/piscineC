#!/bin/sh

for i; do
    if test ! -e "$i" ; then
        echo "$i: unknown"
    elif test -d "$i" ; then
        echo "$i: directory"
    elif test -f "$i" ; then
        echo "$i: file"
    fi
done
