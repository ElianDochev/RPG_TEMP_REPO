/*
** EPITECH PROJECT, 2022
** My_defender
** File description:
** main header file
*/

#ifndef MAIN_H
    #define MAIN_H

    #include "utilities.h"
    #include "sprites.h"
    #include "map.h"
    #include "player.h"
    #include "conf.h"
    #include "ennemi.h"

/*###########################################################################
#######################BEGINING OF STATE FUNC SEGMENT########################
#############################################################################*/
//this are the main game states
typedef enum {not_started, paused, running, gm_over, gm_quit} states;
//sets the state to gm_quit (takes the state obj as void *)
void quit(void *state, int a);
//sets the state to gm_running (takes the state obj as void *)
void start(void *state, int a);
//sets the state to not_starded which resets the game
//(takes the state obj as void *)
void start_over(void *state, int a);
//sets the state to paused which pauses
//(takes the state obj as void *)
void pause_game(void *state);
//callback for a button to end the running of the current option
void exit_option(void *running, int a);
/*###########################################################################
#######################END OF STATE FUNC  SEGEMENT###########################
-----------------------------------------------------------------------------*/



/*###########################################################################
#######################BEGINING OF GLOBAL OBJECT SEGMENT#####################
#############################################################################*/
//global object struct
typedef struct {
    int lives;
    map_t *map;
    player_t *player;
    ennemi_t *ennemi;
    time_mana_t clock;
} global_t;
// inits the global variable
global_t *set_up_global(config_t *conf);
//resets the global variable uses lives form the config object
void reset_global(global_t *global, int lives);
/*###########################################################################
#######################END OF GLOBAL OBJECT SEGEMENT#########################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINING OF  GAME LOOPS SEGMENT########################
#############################################################################*/
//creates the window object from config
sfRenderWindow *create_window(config_t *config);
//the event loop is here
void event_loop(sfRenderWindow *window, states *state);
//runs the start menu
void start_menu(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf);
//runs the actual game segment
void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf);
//runs the game_paused segment
void game_paused(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf);
//runs the game over segment (win or lose)
void game_over(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf);
/*###########################################################################
######################END OF  GAME LOOPS SEGMENT#############################
#############################################################################*/



/*###########################################################################
######################BEGINING OF UNITL FUNCS SEGMENT########################
#############################################################################*/
//gets the window center on y axis
unsigned int get_center_y(sfRenderWindow *window);
//gets the window center on x axis
unsigned int get_center_x(sfRenderWindow *window);
//gets the window center on both axis -
//the offset (precent of the x or y axis)
sfVector2u get_center_xy_pcn
(sfRenderWindow *window, float ofset_x, float ofset_y);
//gets the window center on both axis - the offset in pixels
sfVector2u get_center_xy(sfRenderWindow *window, int offset_x, int offset_y);
/*###########################################################################
######################END OF UNITL FUNCS SEGMENT#############################
#############################################################################*/


/*###########################################################################
######################BEGINING OF CURSOR SEGMENT#############################
#############################################################################*/
typedef sprite_t cursor_t;
//sets up the cursor object
cursor_t *set_up_cursor(char *cursor_path);
//moves the cursor object to the position of the mouse and prints it
void set_cursor_to_mouse(cursor_t *cursor, sfRenderWindow *window);
//destroys the cursor object
void destroy_cursor(cursor_t *cursor);
/*###########################################################################
######################END OF CURSOR SEGMENT##################################
#############################################################################*/

/*###########################################################################
#######################BEGINING OF NOT IMP SEGMENT###########################
#############################################################################*/
    #define N_IMP_MSG "Feathur not implmented"
    #define N_IMP_PATH_CURSOR "./resources/cursor/hand_only.png"
    #define MSG_FONT_HELP "./resources/fonts/orange_juice_2.0.ttf"
static char const *n_imp_button[] = {"Go back", NULL};
//call when you have an inimplemented feature take the window obj as a void ptr
void not_imp(void *ptr);
// draws map on screen with sfrenderwindow
void draw_map(sfRenderWindow *window,map_t *map);
//destroys the map, textures and sprites
void destroy_map(map_t *map);
//changes the map
void change_map(map_t *map, const char *path);
void anim_flowers(map_t *map, time_mana_t *fl);
int move_player(player_t *player, time_mana_t *mo);
void which_map(player_t *player, map_t *map);
void player_action(player_t *player, map_t *map, ennemi_t *ennemi);
void anim_ruby(player_t *player, time_mana_t *ru, sfRenderWindow *window);
void move_ennemies(player_t *player, ennemi_t *enemy);
int is_around_player(player_t *player, int y, int x, char item);
int is_around_ennemi(player_t *player, ennemi_t *ennemi, int y, int x, char item);
void main_game_loop(int *error);
ennemi_t *set_up_ennemi(void);
void destroy_player(player_t *player);
int str_to_int(char *str);
void ev_loop_running(sfRenderWindow *window, states *state, global_t *global);
void anim_player(player_t *player, time_mana_t *pl);
void draw_ennemi(sfRenderWindow *window, global_t *global);
char **my_str_to_word_array(char *buffer);
void free_board(char **board);
/*###########################################################################
#######################END OF NOT IMP SEGEMENT###############################
-----------------------------------------------------------------------------*/
#endif
