#!/bin/bash
for file in ./*.cor; do printf $file; printf "\n"; diff -u <(hexdump -vC $file) <(hexdump -vC "../cor_files_zaz/${file}"); done
