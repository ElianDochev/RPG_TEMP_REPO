/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game over header file header file
*/

#ifndef GM_OVER_H
    #define GM_OVER_H

    #include "main.h"
    #include "sprites.h"
    #include "buttons.h"

typedef sprite_t cursor_t;
static char *gm_over_msg = "GAME OVER\n";
static char *gm_over_menu[] = {"START OVER", "QUIT", NULL};
//event loop for game over state
void ev_loop_gm_over(sfRenderWindow *window, states *state,
button_text_t **menu);
//button functions for game over state
static const void (*action[])(void *) = {&start_over, &quit};
//all the elements needed for game over
typedef struct {
    sfFont *main_font;
    sfVector2f vect;
    text_t *msg;
    button_text_t **menu;
    cursor_t *cursor;
    sprite_t *background;
    sfMusic *music;
} game_over_elements_t;
//initializes the elements of the game over state
game_over_elements_t *init_gm_over_elements(sfRenderWindow *window,
config_t *conf);
#endif