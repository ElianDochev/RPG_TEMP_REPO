/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** has the quit, start function for callback via buttons
*/

#include "main.h"

void quit(void *state)
{
    *((states *)state) = gm_quit;
}

void start(void *state)
{
    *((states *)state) = running;
}

void start_over(void *state)
{
    *((states *)state) = not_started;
}
