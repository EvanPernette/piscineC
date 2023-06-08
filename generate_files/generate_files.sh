#!/bin/sh

file="default"
number=1
type="txt"


for i; do
    if [ "$i" = "-f" ]; then
        file="got"
    elif [ "$i"  = "--filename" ]; then
        file="got"
    elif [ "$i" = "-n" ]; then
        number="got"
    elif [ "$i" = "--number" ]; then
        number="got"
    elif [ "$i" = "-e" ]; then
        type="got"
    elif [ "$i" = "--extension" ]; then
        type="got"
    elif [ "$file" = "got" ]; then
        file="./$i"
    elif [ "$number" = "got" ]; then
        number="$i"
    elif [ "$type" = "got" ]; then
        type="$i"
    else
        exit 1
    fi
done

while [ $number -ne 0 ]; do
    touch "$file-$number.$type"
    number=$(($number-1))
    done
