/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** all the things needed for start menu
*/

#ifndef START_H
    #define START_H

    #include "sprites.h"
    #include "buttons.h"

static char *options_msg[] = {"START", "HOW TO PLAY", "OPTION", "QUIT", NULL};
    #define FONT_STMENU "./resources/fonts/orange juice 2.0.ttf"
//sets up the start menu array of objects (later will be buttons)
text_t **set_up_start_menu(sfFont *font, sfVector2f vect);
//draws the menu on the screen
void draw_menu(text_t **menu , sfRenderWindow *window);
//event loop for start menu
void ev_loop_start(sfRenderWindow *window, states *state,
button_text_t **menu);
#endif