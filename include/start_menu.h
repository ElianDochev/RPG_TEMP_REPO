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
typedef struct start_menu_elements start_menu_elements_t;
static char *options_msg[] = {"START", "HOW TO PLAY", "OPTION", "QUIT", NULL};
    #define FONT_STMENU "./resources/fonts/orange juice 2.0.ttf"
    #define TITLE_COLOR sfGreen
//draws the menu on the screen
void draw_menu(text_t **menu , sfRenderWindow *window);
//event loop for start menu
void ev_loop_start(states *state,
start_menu_elements_t *elements);
//the display help button function
void display_help(void *element);
//the options button function
void option(void *element);
//functions for start menu
static const void (*action_start_menu[])(void *) =
{&start, &display_help, &option, &quit};
//all the elements needed for start menu
struct start_menu_elements {
    sfFont *main_font;
    sfVector2f vect;
    text_t *title;
    button_text_t **menu;
    cursor_t *cursor;
    sprite_t *background;
    sfMusic *music;
    sfRenderWindow *window;
    config_t *conf;
};
//initializes the elements of the start menu
start_menu_elements_t *init_start_elements(sfRenderWindow *window,
config_t *conf);
#endif