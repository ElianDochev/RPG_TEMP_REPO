/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inits the elements of the game paused
*/

#include "game_paused.h"

static sfMusic *init_music(config_t *conf)
{
    sfMusic *music = sfMusic_createFromFile(conf->paths[game_paused_music]);
    if (!music)
        return (NULL);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, (float) conf->confs[music_vol_cf]);
    sfMusic_play(music);
    return (music);
}

static sfRectangleShape *set_up_sqre_container(sfRenderWindow *window,
sfVector2f vect)
{
    sfRectangleShape *container = sfRectangleShape_create();
    sfVector2f size = {sfRenderWindow_getSize(window).x / 2,
    sfRenderWindow_getSize(window).y / 2};

    sfRectangleShape_setPosition(container, vect);
    sfRectangleShape_setSize(container, size);
    sfRectangleShape_setFillColor(container, sfBlack);
    sfRectangleShape_setOutlineColor(container, sfWhite);
    sfRectangleShape_setOutlineThickness(container, 5);
    return (container);
}

game_paused_elements_t *init_paused_elements(sfRenderWindow *window,
config_t *conf, global_t *global)
{
    game_paused_elements_t *elements = malloc(sizeof(game_paused_elements_t));
    void *bn_color[] = {&sfYellow, &sfBlue, &sfRed};

    elements->main_font = sfFont_createFromFile(conf->paths[game_paused_font]);
    elements->vect = con_vu_to_vf(get_center_xy_pcn(window, -0.05f, -0.3f));
    elements->square_container = set_up_sqre_container(window, elements->vect);
    elements->menu = set_up_menu_bntext(elements->main_font,
    init_button_text_info(create_fvector(elements->vect.x + 50,
    elements->vect.y + 150), bn_color, create_fvector(0, 100), 50),
    option_menu, action_game_paused);
    elements->cursor = set_up_cursor(conf->paths[cursor_path]);
    elements->music = init_music(conf);
    elements->window = window;
    elements->global = global;
    elements->conf = conf;
    return elements;
}
