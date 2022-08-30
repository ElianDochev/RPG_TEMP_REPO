##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for day10
##

SRCS	=	./my_compute_power_rec.c \
		./my_compute_square_root.c \
		./my_getnbr.c \
		./my_isneg.c \
		./my_putchar.c \
		./my_put_nbr.c \
		./my_putstr.c \
		./my_revstr.c \
		./my_strcpy.c \
		./my_str_isalpha.c \
		./my_str_islower.c \
		./my_str_isnum.c \
		./my_str_isupper.c \
		./my_strlen.c \
		./my_strlowcase.c \
		./my_strncpy.c \
		./my_strupcase.c \
		./my_swap.c \
		./my_strdup.c \
		./concat_str.c \
		./my_boardlen.c \
		./my_copy_board.c \
		./my_str_to_word_array.c \
		./is_not_delim.c \
		./my_strcmp.c \
		./my_strcnp.c \
		./free_board.c

CFLAGS	=	-Wall -Wextra

OBJ	=	$(SRCS:.c=.o)

NAME	=	libmy.a

MY	=	m_my.h

all: 	build move

build:	$(OBJ)
	ar -rc $(NAME) $(OBJ)

move: 	$(MY)
	mv -f $(NAME) ./../

clean:
	rm -rf $(OBJ)
	rm -rf *~

fclean:	clean
	rm -rf ../$(NAME)

re: 	fclean all

.PHONY:	all build copy clean fclean re
