# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2018/10/30 15:07:41 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

INC_PATH = include/

INC_FILES = op.h vm.h

INC_FULL = $(addprefix $(INC_PATH)/, $(INC_FILES))

SRC_PATH = src

SRC_NAME =	init.c\
			play/cycle.c play/check_process.c play/get_curr_op.c play/intro.c\
			play/play.c play/get_curr_param.c play/do_op.c play/kill_process.c\
			op_functions/live.c op_functions/add.c op_functions/sub.c\
			op_functions/zjmp.c op_functions/aff.c op_functions/lfork.c\
			op_functions/lld.c op_functions/lldi.c op_functions/ld.c\
			op_functions/st.c op_functions/sti.c op_functions/ldi.c\
			op_functions/and.c op_functions/or.c op_functions/xor.c\
			op_functions/fork_vm.c op_functions/get_param_value.c\
			setup/create_player.c setup/create_map.c\
			setup/open_read_functions.c setup/create_process.c\
			setup/check_magic.c setup/parsing.c setup/write_player.c\
			setup/duplicate_process.c\
			display/update_map.c\
			display/get_inputs.c display/check_screen_size.c\
			display/exit_curses.c display/init_curses.c display/visu_curses.c\
			display/print_instructions.c display/get_playerid.c\
			display/curses_permanent_parts.c display/curses_map.c\
			display/fun_code.c\
			clear.c error.c tool.c op.c


OBJ_PATH = obj

CPPFLAGS = -Iinclude -I../libft/include

LDFLAGS = -L../libft

LDLIBS = -lft

LIB = ../libft/libft.a

CFLAGS = -Wall -Wextra -Werror -O2 -g

CC = clang

NCURSE = -lncurses

# GTK build specific variables
GTK_SRC_NAME = gui/main_gui.c\
		gui/bg_loop.c\
		gui/reset.c\
		gui/rice.c\
		gui/popup.c\
		gui/gui_win.c\
		gui/gui_helpers.c\
		gui/update_info.c\
		gui/call_control.c\
		gui/call_debug.c\
		gui/call_filepicker.c\
		gui/call_colors.c\
		gui/call_misc.c
GTK_INC_FILES = gui.h
GTK_LIBS = gtk+-3.0 gmodule-2.0
GTK_CPPFLAGS = $(shell pkg-config --cflags-only-I $(GTK_LIBS)) -pthread
GTK_LDFLAGS = $(shell pkg-config --libs --cflags $(GTK_LIBS)) -rdynamic
ifeq ($(GTK), 1)
	NAME = corewar_gui
	SRC_NAME += $(GTK_SRC_NAME)
	INC_FILES += $(GTK_INC_FILES)
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
	make -C ../libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(NCURSE) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_FULL)
	@mkdir -p obj/play obj/setup obj/display obj/op_functions obj/gui
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

GTK:
	GTK=1 $(MAKE)

GTK_fclean:
	GTK=1 $(MAKE) fclean

GTK_re:
	GTK=1 $(MAKE) re

.PHONY: all norme clean fclean re GTK GTK_fclean GTK_re
