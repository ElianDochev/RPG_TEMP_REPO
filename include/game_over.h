/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game over header file header file
*/

#ifndef GM_OVER_H
    #define GM_OVER_H

    #include "utilities.h"
    #include "sprites.h"
    #include "buttons.h"

static char *gm_over_msg[] = {"YOU LOSE:\n SCORE ", "YOU WIN:\n SCORE ", NULL};
static char *gm_over_menu[] = {"START OVER", "QUIT", NULL};
//event loop for game over state
void ev_loop_gm_over(sfRenderWindow *window, states *state,
button_text_t **menu);
#endif