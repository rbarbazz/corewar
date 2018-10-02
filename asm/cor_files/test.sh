make -C .. && cp ../asm .
for file in ./*.s; do printf $file; printf "\n"; ./asm $file; done