/*
** EPITECH PROJECT, 2022
** my_board_len.c
** File description:
** len of a board
*/

#include <stdlib.h>

void free_board(char **board)
{
    for (int y = 0; board[y] != NULL; y++)
        free(board[y]);
    free(board);
}
