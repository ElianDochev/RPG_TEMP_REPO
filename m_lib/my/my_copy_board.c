/*
** EPITECH PROJECT, 2022
** antman
** File description:
** main for antman
*/

#include "m_my.h"
#include <stdlib.h>

char **copy_board(char **board)
{
    char **new_board = malloc(sizeof(char *) * (my_boardlen(board) + 2));

    for (int i = 0; board[i] != NULL; i++){
        new_board[i] = board[i];
        new_board[i + 1] = NULL;
        new_board[i + 2] = NULL;
    }
    return new_board;
}
