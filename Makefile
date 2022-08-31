##
## EPITECH PROJECT, 2022
## my_rpg Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##


NAME		=	my_rpg

SRC	=	source/tests/button.c						\
		lib/my/convert_vectors.c					\
		source/main.c								\
		source/game_loop/main_game_loop.c			\
		source/game_loop/config.c					\
		source/game_loop/game_over.c				\
		source/game_loop/game_paused.c				\
		source/game_loop/game_running.c 			\
		source/game_loop/start_menu.c 				\
		source/window/events.c						\
		source/window/window.c						\
		source/window/get_center_window.c			\
		source/sprites/text.c						\
		source/sprites/sprite.c						\
		source/shared_functions/cursor.c			\
		source/shared_functions/button_text.c		\
		source/shared_functions/menu_bntext.c		\
		source/shared_functions/action_state.c		\
		source/shared_functions/loop_menu.c			\
		source/shared_functions/not_impemented.c	\
		source/start_menu/support_func.c			\
		source/game_over/support_function.c			\
		source/get.c								\
		source/create_map.c							\
		source/map_mana.c							\

CPPFLAGS = -I./include -I./m_lib/my

OBJ			=	$(SRC:.c=.o)

DIR = -L./lib/ -L./m_lib/

LIB 		=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window -lmy

all: compil

compil : $(OBJ)
	$(MAKE) -C ./lib/my
	$(MAKE) -C ./m_lib/my
	gcc -o $(NAME) $(OBJ) $(DIR) $(LIB) m_lib/libmy.a

debug:	CFLAGS += -g3 -Wall -Wextra
debug:	re

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my
	$(MAKE) clean -C ./m_lib/my

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my
	$(MAKE) fclean -C ./m_lib/my

re: fclean all

.PHONY: all makelib clean fclean re
