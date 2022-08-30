/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init and delete elements for start menu
*/

#include "start_menu.h"
#include "buttons.h"
#include "main.h"

void destroy_element(start_menu_elements_t *elements)
{
    destroy_text(elements->title);
    destroy_menu_bntext(elements->menu);
    destroy_cursor(elements->cursor);
    sfFont_destroy(elements->main_font);
    sfMusic_destroy(elements->music);
    destroy_sprite(elements->background, DESTOY_TEXTURE);
    free(elements);
}

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
    float x;
    float y;

    elements->main_font = sfFont_createFromFile(conf->paths[start_font]);
    elements->vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05f, -0.3f));
    elements->title = init_text("my_rpg", elements->main_font, 50, &(elements->vect));
    elements->menu = set_up_menu_bntext(elements->main_font,
    create_fvector(elements->vect.x, elements->vect.y + 100),
    options_msg, action_start_menu);
    elements->cursor = set_up_cursor(conf->paths[cursor_path]);
    elements->music = init_music(conf);
    elements->background = set_sprite(NULL, conf->paths[start_background], NULL, NULL);
    x = (float) sfSprite_getTextureRect(elements->background->sprite).width /
    (float) sfRenderWindow_getSize(window).x;
    y = (float) sfSprite_getTextureRect(elements->background->sprite).height /
    (float) sfRenderWindow_getSize(window).y;
    x = (sfSprite_getTextureRect(elements->background->sprite).width / x) /
    (float) sfSprite_getTextureRect(elements->background->sprite).width;
    y = (sfSprite_getTextureRect(elements->background->sprite).height / y) /
    (float) sfSprite_getTextureRect(elements->background->sprite).height;
    sfSprite_setScale(elements->background->sprite, create_fvector(x, y));
    return elements;
}
