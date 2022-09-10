/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** Header file for config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

    #include "utilities.h"

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
"Fullscrene=", "Lives=", "Attack=", "Defense=", NULL};
static const char *needed_paths[] = {"Cursor_path=" , "Font_start=",
"Start_bg=", "Start_music=", "Font_gm_over=", "Gm_over_bg=", "Gm_over_music=",
"Paused_font=", "Paused_music=", NULL};
//used for a loop in config init
typedef enum {refresh_rate_ov_st, height_cf, width_cf, bpp_cf,
frame_rate_cf, music_vol_cf, sound_vol_cf, fullscreen_cf,
conf_lives, conf_attack, conf_defense, confs_count} confs;
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
#######################BEGINING OF TIME SEGMENT##############################
#############################################################################*/
typedef struct time_management
{
    sfClock *clock;
    sfTime time;
    float millisec;
} time_mana_t;

//function to create and initialize a new clock
time_mana_t *get_clock(void);

/*###########################################################################
#######################END OF TIME SEGEMENT##################################
-----------------------------------------------------------------------------*/
#endif