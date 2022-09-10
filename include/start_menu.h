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

/*###########################################################################
#######################BEGINING OF START_MENU SEGMENT########################
#############################################################################*/
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
static const void (*action_start_menu[])(void *, int) =
{&start, &display_help, &option, &quit};
//all the elements needed for start menu
struct start_menu_elements {
    config_t *conf;
    sfFont *main_font;
    sfVector2f vect;
    text_t *title;
    button_text_t **menu;
    cursor_t *cursor;
    sprite_t *background;
    sfMusic *music;
    sfRenderWindow *window;
};
//initializes the elements of the start menu
start_menu_elements_t *init_start_elements(sfRenderWindow *window,
config_t *conf);

/*###########################################################################
#######################END OF START_MENU SEGEMENT############################
-----------------------------------------------------------------------------*/
    #define FONT_SIZE_HELP 50
    #define FONT_COLOR_HELP sfColor_fromRGB(0xff, 0x8c, 0x00)

/*###########################################################################
#######################BEGINING OF HELP SEGMENT##############################
#############################################################################*/
//colors used for sliders in option menu in start menu
static const void *option_colors[] = {&sfWhite, &sfBlue, NULL, &sfBlack};
//the thinness of outline of the sliders in option menu in start menu
// bar =0 , circle = 2
static const sfVector2f option_thinkness = {0, 2};
//callback for the volume slider in option menu in start menu
void change_volume(void *arg, float percent);
//callback for the sound slider in option menu in start menu
void change_sound(void *arg, float percent);

/*###########################################################################
#######################END OF HELP SEGEMENT##################################
-----------------------------------------------------------------------------*/
#endif