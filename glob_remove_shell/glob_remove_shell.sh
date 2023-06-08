#!/bin/sh
var=$1
var2=0
if [ $# -eq 0 ]; then
    var=txt
    fi

for i in *."$var" ; do
    if test -f "$i"; then
        rm -rf $i;
        var2=1
        fi
done
if [ "$var2" -eq 0 ]; then
    exit 1
fi

