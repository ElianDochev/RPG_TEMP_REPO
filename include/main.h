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
    #include "ennemi.h"

/*###########################################################################
#######################BEGINING OF STATE FUNC SEGMENT########################
#############################################################################*/
//this are the main game states
typedef enum {not_started, paused, running, gm_over, gm_quit} states;
//sets the state to gm_quit (takes the state obj as void *)
void quit(void *state);
//sets the state to gm_running (takes the state obj as void *)
void start(void *state);
//sets the state to not_starded which resets the game
//(takes the state obj as void *)
void start_over(void *state);
//sets the state to paused which pauses
//(takes the state obj as void *)
void pause_game(void *state);
//callback for a button to end the running of the current option
void exit_option(void *running);
/*###########################################################################
#######################END OF STATE FUNC  SEGEMENT###########################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINING OF CONFIG OBJECT SEGMENT######################
#############################################################################*/
    #define CONF_PATH "main.conf"
//error msg when there are invalide chars in file
static const char *conf_err_msg_one = "FATAL: Invalide config file, "
"check for spaces and case\nCorrect format is "
"Attirubute=possitive integer number/n\n!!! CASE SENSITIVE\n";
//error msh when atrubutes are missing
static const char *conf_err_msg_two =
"missing attribute check content of config file, "
"all these attributes should be present\nRefresh_rate\nHeight\n"
"Width\nBpp\nFrame_rate\nMusic_volume\nSound_volume\nFullscrene\n"
"Cursor_path\nFont_start\nLives\nStart_bg\nStart_music\n!!! CASE SENSITIVE\n";
//the required attrubutes
static const char *needed_unsigned[] = {"Refresh_rate_over_start=",
"Height=", "Width=", "Bpp=", "Frame_rate=", "Music_volume=", "Sound_volume=",
"Fullscrene=", "Lives=", NULL};
static const char *needed_paths[] = {"Cursor_path=" , "Font_start=", "Start_bg=",
"Start_music=", "Font_gm_over=", "Gm_over_bg=", "Gm_over_music=",
"Paused_font=", "Paused_music=", NULL};
//used for a loop in config init
typedef enum {refresh_rate_ov_st, height_cf, width_cf, bpp_cf,
frame_rate_cf, music_vol_cf, sound_vol_cf, fullscreen_cf,
conf_lives, confs_count} confs;
typedef enum {cursor_path, start_font, start_background, start_music,
gm_over_font, gm_over_bg, gm_over_music,
game_paused_font, game_paused_music, path_count} path_enum;
//read from file contains all the window and clock params;
typedef struct {
    unsigned int confs[confs_count];
    char *paths[path_count];
} config_t;
//sets up the config object
config_t *set_up_config(void);
/*###########################################################################
#######################END OF CONFIG OBJECT SEGMENT##########################
-----------------------------------------------------------------------------*/



/*###########################################################################
#######################BEGINING OF GLOBAL OBJECT SEGMENT#####################
#############################################################################*/
typedef struct time_management
{
    sfClock *clock;
    sfTime time;
    float millisec;
} time_mana_t;
//global object struct
typedef struct {
    int lives;
    map_t *map;
    player_t *player;
    ennemi_t *ennemi;
    time_mana_t clock;
} global_t;
// inits the global variable
global_t *set_up_global(int lives);
//resets the global variable uses lives form the config object
void reset_global(global_t *global, int lives);
//function to create and initialize a new clock
time_mana_t *get_clock(void);
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
/*###########################################################################
#######################END OF NOT IMP SEGEMENT###############################
-----------------------------------------------------------------------------*/
#endif
