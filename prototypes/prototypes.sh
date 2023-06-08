#!/bin/sh

for i;do
    if test -f "$i"; then
        sed -n -E "s@^[a-z]{1,}( [a-z]{1,}|) {1,}[^ ]{1,}\(.{1,}(\)| .{1,}\))@&;@p" "$i"
    fi
    exit 0
done
