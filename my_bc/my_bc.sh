#!/bin/sh

count=0
final=0

if [ "$#" -ne 1 ]; then
    while read line; do
        count=$(($line))
        echo $count
    done < /dev/stdin
fi

if [ "$#" -eq 1 ]; then
    count=$(($1))
    echo $count
fi
