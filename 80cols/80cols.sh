#!/bin/sh

if [ $# -ge 2 ];then
    exit 1
fi

if ! test -f "$1" ;then
    exit 1
fi


while IFS= read -r l; do
    echo "$l" > t.txt
    n=$(wc -c < t.txt)
    if [ "$n" -gt 80 ]; then
        printf "%s\n" "$l"
    fi
done < "$1"

