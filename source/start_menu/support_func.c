/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init and delete elements for start menu
*/

#include "start_menu.h"
#include "buttons.h"
#include "main.h"

//intis the music element for the start menu and plays it
static sfMusic *init_music(config_t *conf)
{
    sfMusic *music = sfMusic_createFromFile(conf->paths[start_music]);
    if (!music)
        return (NULL);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, (float) conf->confs[music_vol_cf]);
    sfMusic_play(music);
    return (music);
}

start_menu_elements_t *init_start_elements(sfRenderWindow *window,
config_t *conf)
{
    start_menu_elements_t *elements = malloc(sizeof(start_menu_elements_t));
    sfVector2f bg_size;
    void *bn_color[] = {&sfYellow, &sfBlue, &sfRed};

    elements->main_font = sfFont_createFromFile(conf->paths[start_font]);
    elements->vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05f, -0.3f));
    elements->title = init_text("my_rpg", elements->main_font, 50,
    &(elements->vect));
    elements->menu = set_up_menu_bntext(elements->main_font,
    init_button_text_info(create_fvector(elements->vect.x,
    elements->vect.y + 100), bn_color, create_fvector(0, 100), 50),
    options_msg, action_start_menu);
    elements->cursor = set_up_cursor(conf->paths[cursor_path]);
    elements->music = init_music(conf);
    elements->background = set_sprite(NULL, conf->paths[start_background],
    NULL, NULL);
    bg_size.x = (float) sfRenderWindow_getSize(window).x /
    (float) sfSprite_getTextureRect(elements->background->sprite).width;
    bg_size.y = (float) sfRenderWindow_getSize(window).y /
    (float) sfSprite_getTextureRect(elements->background->sprite).height;
    sfSprite_setScale(elements->background->sprite, bg_size);
    return elements;
}
