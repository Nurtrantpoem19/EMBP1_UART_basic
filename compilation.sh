#!/usr/bin/env bash

if [[ $# -ne 1 ]]; then
	echo "USAGE: $0 <source.c>"
	exit 1
fi



source_file="$1"

if [[ ! -f "$source_file" ]]; then
	echo "File does not exist: $source_file" >&2
	exit 1
fi


if [[ "$source_file" != *.c ]]; then
	echo "ERROR: Needs a .c file" >&2
	exit 1
fi

output_base="${source_file%.c}"
output_elf="${output_base}.elf"
output_hex="${output_base}.hex"

echo "$output_elf + $output_hex"
echo "The script is working for $source_file"


echo "Compiling $source_file..."

avr-gcc \
	-mmcu=atmega2560 \
	"$source_file" \
	-o "$output_elf"


echo "Copying into $output_hex..."

avr-objcopy \
	 -j .data \
	 -j .text \
	 -O ihex \
	 "$output_elf" \
	 "$output_hex"

 avrdude \
	 -p m2560 \
	 -D \
	 -c wiring \
	 -P /dev/ttyACM0 \
	 -b 115200 \
	 -U flash:w:"$output_hex":i
