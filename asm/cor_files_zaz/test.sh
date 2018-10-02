for file in ./*.s; do printf $file; printf "\n"; ./zasm $file; done
