##
## EPITECH PROJECT, 2022
## my_rpg Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##


NAME		=	my_rpg

SRC	=	lib/my/convert_vectors.c						\
		source/main.c									\
		source/game_loop/main_game_loop.c				\
		source/game_loop/config.c						\
		source/game_loop/game_over.c					\
		source/game_loop/game_paused.c					\
		source/game_loop/game_running.c 				\
		source/game_loop/start_menu.c 					\
		source/window/events.c							\
		source/window/window.c							\
		source/window/get_center_window.c				\
		source/sprites/text.c							\
		source/sprites/sprite.c							\
		source/shared_functions/cursor.c				\
		source/shared_functions/button_text.c			\
		source/shared_functions/menu_bntext.c			\
		source/shared_functions/action_state.c			\
		source/shared_functions/not_impemented.c		\
		source/shared_functions/slider.c				\
		source/shared_functions/slider_move.c			\
		source/start_menu/support_func.c				\
		source/start_menu/event_loop.c					\
		source/start_menu/display_help.c				\
		source/start_menu/options_function.c			\
		source/start_menu/option_function_callbacks.c 	\
		source/game_over/support_function.c				\
		source/game_over/event_loop.c					\
		source/game_paused/option_menu.c				\
		source/game_paused/support_function.c			\
		source/game_paused/inventory_option.c			\
		source/game_paused/option_callbacks.c			\
		source/get.c									\
		source/create_map.c								\
		source/map_mana.c								\
		source/game_running/create_player.c 			\
		source/game_running/player_manage.c 			\
		source/is.c										\
		source/game_running/create_ennemi.c 			\
		source/game_running/change_map.c 				\
		source/game_running/player_action.c				\
		source/game_running/animation.c 				\
		source/ennemies/ennemies_movement.c 			\
		source/game_loop/init_entities.c 				\

CPPFLAGS = -I./include -I./m_lib/my -g3

OBJ			=	$(SRC:.c=.o)

DIR = -L./lib/ -L./m_lib/

LIB 		=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window \
				-lmy -lm

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
