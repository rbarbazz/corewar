# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/14 16:38:16 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_PATH = src

SRC_NAME =	init.c\
			play/cycle.c play/check_process.c play/get_curr_op.c play/intro.c\
			play/play.c play/get_curr_param.c play/do_op.c play/kill_process.c\
			op_functions/live.c op_functions/add.c op_functions/sub.c\
			op_functions/zjmp.c op_functions/aff.c op_functions/lfork.c\
			op_functions/lld.c op_functions/lldi.c\
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

CFLAGS = -Wall -Wextra -g

NCURSE = -lncurses

# GTK build specific variables
GTK_SRC_NAME = gui/main_gui.c\
		gui/bg_loop.c\
		gui/call_filepicker.c\
		gui/call_logic.c
GTK_LIBS = gtk+-3.0 gmodule-2.0
GTK_CPPFLAGS = $(shell pkg-config --cflags-only-I $(GTK_LIBS))
GTK_LDFLAGS = $(shell pkg-config --libs --cflags $(GTK_LIBS)) -rdynamic
ifeq ($(GTK), 1)
	NAME = corewar_gui
	SRC_NAME += $(GTK_SRC_NAME)
	CPPFLAGS += $(GTK_CPPFLAGS)
	LDFLAGS += $(GTK_LDFLAGS)
else
	SRC_NAME += main.c
endif

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(NCURSE) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj/play obj/setup obj/display obj/op_functions obj/gui
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
