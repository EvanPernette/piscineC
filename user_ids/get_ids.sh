#!/bin/sh
cut -d ':' -f 3 /etc/passwd | sort -r -un
exit 0
