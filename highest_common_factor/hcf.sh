#!/bin/sh
var=1
max=1
if [ $1 -eq 0 ]; then
    max=$2
    fi

if [ $# -ne 2 ]; then
    echo "Usage: ./hcf.sh num1 num2"
    exit 1
else
    while [ $1 -ge $var ]; do
        var1=$(($2 % $var))
        var2=$(($1 % $var))
        if [ $var1 -eq 0 ]; then
            if [ $var2 -eq 0 ]; then
                   max=$var
            fi
        fi
        var=$(($var + 1))
    done
    echo "$max"
fi

