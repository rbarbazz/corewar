# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/19 12:51:43 by msamak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

VM = vm

LIB = libft

all:
	make -C $(ASM)
	make -C $(VM)

clean:
	make -C $(LIB) clean
	make -C $(ASM) clean
	make -C $(VM) clean


fclean:
	make -C $(LIB) fclean
	make -C $(ASM) fclean
	make -C $(VM) fclean

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all, clean, fclean, re
