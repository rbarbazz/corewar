# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/25 23:25:58 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

VM = vm

LIB = libft

all:
	$(MAKE) -C $(ASM)
	$(MAKE) -C $(VM)

clean:
	$(MAKE) -C $(LIB) clean
	$(MAKE) -C $(ASM) clean
	$(MAKE) -C $(VM) clean

fclean:
	$(MAKE) -C $(LIB) fclean
	$(MAKE) -C $(ASM) fclean
	$(MAKE) -C $(VM) fclean

re:
	$(MAKE) fclean
	$(MAKE)

norme:
	$(MAKE) -C $(LIB) norme
	$(MAKE) -C $(ASM) norme
	$(MAKE) -C $(VM) norme

GTK:
	$(MAKE) -C $(VM) GTK

.PHONY: all clean fclean re norme GTK
