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

static sprite_t *do_background(char *path, sfRenderWindow *window)
{
    sfVector2f bg_size;
    sprite_t *bg = set_sprite(NULL, path, NULL, NULL);

    bg_size.x = (float) sfRenderWindow_getSize(window).x /
    (float) sfSprite_getTextureRect(bg->sprite).width;
    bg_size.y = (float) sfRenderWindow_getSize(window).y /
    (float) sfSprite_getTextureRect(bg->sprite).height;
    sfSprite_setScale(bg->sprite, bg_size);
    return (bg);
}

start_menu_elements_t *init_start_elements(sfRenderWindow *window,
config_t *conf)
{
    start_menu_elements_t *elements = malloc(sizeof(start_menu_elements_t));
    void *bn_color[] = {&sfYellow, &sfBlue, &sfRed};

    elements->main_font = sfFont_createFromFile(conf->paths[start_font]);
    elements->vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05f, -0.3f));
    elements->title = init_text("My_rpg", elements->main_font, 50,
    &(elements->vect));
    elements->menu = set_up_menu_bntext(elements->main_font,
    init_button_text_info(create_fvector(elements->vect.x,
    elements->vect.y + 150), bn_color, create_fvector(0, 100), 50),
    options_msg, action_start_menu);
    elements->cursor = set_up_cursor(conf->paths[cursor_path]);
    elements->music = init_music(conf);
    elements->background = do_background(conf->paths[start_background],
    window);
    sfText_setColor(elements->title->text, TITLE_COLOR);
    return elements;
}
