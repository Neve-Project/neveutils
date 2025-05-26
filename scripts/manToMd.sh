#!/bin/sh

SRC_DIR="./src"

find "$SRC_DIR" -type f \( -name "*.1" -o -name "*.8" \) | while read -r manfile; do
	dir="$(dirname "$manfile")"
	out="$dir/README.md"

	echo "Converting $manfile → $out"
	mandoc -T markdown "$manfile" >"$out" || {
		echo "Error: unable to convert $manfile" >&2
		continue
	}
done
