/*
** EPITECH PROJECT, 2022
** my_board_len.c
** File description:
** len of a board
*/

#include <stddef.h>

int my_boardlen(char **board)
{
    int i = 0;

    while (board[i] != NULL)
        i++;
    return i;
}
