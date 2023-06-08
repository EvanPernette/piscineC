#!/bin/sh

var=$2

if ! [ -f "$1" ] || ! [ $# -eq 2 ] || ! [ -n $var ] ||  ! [ "$var" -eq "$var" ] 2>/dev/null ; then
    exit 1
fi


count=$(wc -l < $1)
if [ "$count" -lt "$2" ] || [ $2 -le 0 ]; then
    exit 1
fi
x=1
while read -r l; do
    if  [ $x -eq $2 ]; then
        echo "$l" > str
        test=$(cut -d ';' -f 2 str)
        test2=$(cut -d ';' -f 3 str)
        echo "$test is $test2"
    fi
    x=$((x + 1))
done < $1
exit 0
