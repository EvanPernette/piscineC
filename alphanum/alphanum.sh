#!/bin/sh

while read line; do
        if [ "$line" = "" ]; then
                echo "it is empty"
        elif test -n "$(echo "$line" | grep -E "^[0-9]{2,}+$" )"; then
                echo "it is a number"
        elif test -n "$(echo $line | grep -E "^[0-9]{1}$")"; then
                echo "it is a digit"
        elif test -n "$(echo $line | grep -E "^[a-zA-Z]{1,}$")"; then
                echo "it is a word"
        elif test -n "$(echo "$line" | grep -E "^[a-zA-Z0-9]{1,}$")"; then
                echo "it is an alphanum"
        else
                echo "it is too complicated"
                break
        fi
done < /dev/stdin
exit 0
