# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/13 22:38:47 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_PATH = src

SRC_NAME =	main.c init.c\
			play/cycle.c play/check_process.c play/get_curr_op.c play/intro.c\
			play/play.c play/get_curr_param.c play/do_op.c play/kill_process.c\
			op_functions/live.c op_functions/add.c op_functions/sub.c\
			op_functions/zjmp.c op_functions/aff.c op_functions/lfork.c\
			op_functions/lld.c op_functions/lldi.c op_functions/ld.c\
			op_functions/st.c op_functions/sti.c\
			op_functions/get_param_value.c\
			setup/create_player.c setup/create_map.c\
			setup/open_read_functions.c setup/create_process.c\
			setup/check_magic.c setup/parsing.c setup/write_player.c\
			display/debug.c display/update_map.c\
			clear.c error.c tool.c op.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -O2

CC = clang

NCURSE = -lncurses

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(NCURSE) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj/play obj/setup obj/display obj/op_functions
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

norme:
	norminette $(SRC)
	norminette include/*.h
	norminette libft/src
	norminette libft/include

clean:
	make -C libft clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all, clean, fclean, re
