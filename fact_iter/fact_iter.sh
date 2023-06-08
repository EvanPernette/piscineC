#!/bin/sh

n=$1
var=1

if [ $1 -eq 0 ]; then
    echo "1"
elif [ $# -ne 1 ]; then
    exit 1
else
    while [ $n -ne 1 ]; do
        var=$(($var * $n))
        n=$(($n - 1))
        done
        echo "$var"
fi
