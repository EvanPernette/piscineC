#!/bin/sh

n=$1
var=1

if [ "$#" -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
    exit 1
elif [ "$2" -eq 0 ]; then
    exit 1
else
    if [ $1 -eq $3 ]; then
        echo $1
        exit 0
    fi
    if [ $1 -ge $3 ]; then
        if [ 0 -ge $2 ]; then
            var=$1
            while [ $var -ge  $(($3 - $2)) ]; do
                echo "$var"
                var=$(($var + $2))
            done
            echo "$var"
        else
            exit 1
            var=$3
            while [ $(($1 - $2)) -ge $var ]; do
                    echo "$var"
                    var=$(($var + $2))
            done
            echo "$3"
        fi
    else
        if [ 0 -ge $2 ]; then
            exit 1
            var=$1
            while [ $var -le $(($3 - $2)) ]; do
                echo "$var"
                var=$(($var + $2))
            done
            echo "$var"
        else
            var=$1
            while [ $var -le $(($3 - $2)) ]; do
                echo "$var"
                var=$(($var + $2))
            done
            echo "$var"
        fi
    fi
fi
