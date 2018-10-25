# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/25 15:30:32 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

INC_PATH = include/

INC_FILES = asm.h

INC_FULL = $(addprefix $(INC_PATH)/, $(INC_FILES))

SRC_PATH = src

SRC_NAME =	main.c clear.c check_argument.c store_sfile.c op.c cursor_motion.c\
 			error/error_file.c error/error.c error/error1.c\
			encode/cor_file.c encode/header.c encode/split_int.c\
			parsing/parser.c parsing/parse_header.c parsing/parse_label.c\
			parsing/parse_op.c parsing/parse_op_name.c parsing/parse_op_param.c\
			parsing/parse_reg.c parsing/parse_dir.c parsing/parse_ind.c\
			parsing/parse_label_pos.c parsing/replace_label_pos.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude -I../libft/include

LDFLAGS = -L../libft

LDLIBS = -lft

LIB = ../libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(LIB):
	make -C ../libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_FULL)
	@mkdir -p obj/parsing obj/encode obj/error
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

norme:
	norminette $(SRC)
	norminette include/*.h

clean:
	make -C ../libft clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all norme clean fclean re
