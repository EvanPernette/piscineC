#!/bin/sh

for file1 in $(ls $1); do
    file $1/$file1 | grep 'ASCII'
done
