/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init and destroy funcs for the game_over scene
*/

#include "game_over.h"

//intis the music element for the start menu and plays it
static sfMusic *init_music(config_t *conf)
{
    sfMusic *music = sfMusic_createFromFile(conf->paths[gm_over_music]);
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

game_over_elements_t *init_gm_over_elements(sfRenderWindow *window,
config_t *conf)
{
    game_over_elements_t *elements = malloc(sizeof(game_over_elements_t));
    void *bn_color[] = {&sfYellow, &sfBlue, &sfRed};

    elements->main_font = sfFont_createFromFile(conf->paths[gm_over_font]);
    elements->vect = con_vu_to_vf(get_center_xy_pcn(window, -0.09f , -0.25f));
    elements->msg = init_text(gm_over_msg, elements->main_font, 50,
    &elements->vect);
    elements->menu = set_up_menu_bntext(elements->main_font,
    init_button_text_info(create_fvector(elements->vect.x - 200,
    elements->vect.y + 450), bn_color, create_fvector(450, 0), 45),
    gm_over_menu, action);
    elements->cursor = set_up_cursor(conf->paths[cursor_path]);
    elements->music = init_music(conf);
    elements->background = do_background(conf->paths[gm_over_bg],
    window);
    sfText_setFillColor(elements->msg->text, GM_OVER_COLOR);
    return elements;
}


