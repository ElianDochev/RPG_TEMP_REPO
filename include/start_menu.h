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
    #include "main.h"

typedef sprite_t cursor_t;
static char *options_msg[] = {"START", "HOW TO PLAY", "OPTION", "QUIT", NULL};
    #define FONT_STMENU "./resources/fonts/orange juice 2.0.ttf"
    #define TITLE_COLOR sfGreen
//draws the menu on the screen
void draw_menu(text_t **menu , sfRenderWindow *window);
//event loop for start menu
void ev_loop_start(sfRenderWindow *window, states *state,
button_text_t **menu);
//functions for start menu
static const void (*action_start_menu[])(void *) =
{&start, &not_imp, &not_imp, &quit};
//all the elements needed for start menu
typedef struct {
    sfFont *main_font;
    sfVector2f vect;
    text_t *title;
    button_text_t **menu;
    cursor_t *cursor;
    sprite_t *background;
    sfMusic *music;
} start_menu_elements_t;
//initializes the elements of the start menu
start_menu_elements_t *init_start_elements(sfRenderWindow *window,
config_t *conf);
#endif