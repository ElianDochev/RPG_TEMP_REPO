/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** HEared file for paiused game
*/

#ifndef GAME_PAUSED_H
    #define GAME_PAUSED_H

    #include "main.h"
    #include "sprites.h"
    #include "buttons.h"

typedef sprite_t cursor_t;
typedef struct game_paused_elements game_paused_elements_t;

static const char *option_menu[] = {"Resume", "Invenroty", "Options", "Quit",
NULL};
// the colors for the silder option menu
static void *option_colors[] = {&sfWhite, &sfGreen, &sfBlack, &sfWhite};
// the thickness of the slider option menu
static const sfVector2f option_thinkness = {2, 2};
//changes the volume of the music
void change_volume_p(void *arg, float percent);
//changes the volume of the sound
void change_sound_p(void *arg, float percent);
// opens the option panel in game paused
void open_options(void *arg, int index);
// opens the inventory in game paused
void open_inventory(void *arg, int index);
// the callback for the menu
static const void (*action_game_paused[])(void *, int) =
{&start, &open_inventory, &open_options, &quit};
struct game_paused_elements {
    config_t *conf;
    sfFont *main_font;
    sfVector2f vect;
    button_text_t **menu;
    cursor_t *cursor;
    sfMusic *music;
    sfRenderWindow *window;
    sfRectangleShape *square_container;
    global_t *global;
};
game_paused_elements_t *init_paused_elements(sfRenderWindow *window,
config_t *conf, global_t *global);
void ev_loop_paused(sfRenderWindow *window, states *state);
void draw_ennemi(sfRenderWindow *window, global_t *global);
#endif
