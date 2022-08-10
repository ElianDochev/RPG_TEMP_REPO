##
## EPITECH PROJECT, 2022
## Makefile for lib
## File description:
## Compiles and builds mylib (called from root Makefile)
##

SCR	=	create_sf_int_rect.c		\
		create_sf_float_vector.c	\
		convert_vectors.c			\
		compare_vector.c			\
		error.c						\
		strlen.c					\
		int_to_str.c				\
		calc_pow.c					\
		str_cat.c					\
		comp_strs.c					\
		linked_list.c				\
		custom_sys_calls.c			\
		file_fopen.c				\
		str_to_int.c				\
		str_to_word_array.c

OBJ	=	$(SCR:.c=.o)

CPPFLAGS =  -Wall -Wextra -I../../include

NAME	=	libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	   rm -f ../$(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
