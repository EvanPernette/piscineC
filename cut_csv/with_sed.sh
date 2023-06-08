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
sed -n $2p "$1" > str
test=$(sed 's/.*;\(.*\);.*;.*;/\1/g' str)
test1=$(sed 's/.*;.*;\(.*\);.*;/\1/g' str)
echo "$test is $test1"
exit 0
