/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animation
*/

#include "main.h"
#include <stdio.h>

static void init_ruby(player_t *player, sfIntRect *rect, time_mana_t *ru)
{
    ru->time = sfClock_getElapsedTime(ru->clock);
    ru->millisec = sfTime_asMilliseconds(ru->time);
    player->textures[RRUBY] = sfTexture_createFromFile(PLAYER_PATHS_NAME[RRUBY],
    NULL);
    player->sprites[RRUBY] = set_sprite(player->textures[RRUBY],
    NULL, rect, get_sfvector2f(1.5, 1.5));
}

void anim_ruby(player_t *player, time_mana_t *ru, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos;
    sfIntRect *rect = get_int_rect(PLAYER_RECT[RRUBY][0],
    PLAYER_RECT[RRUBY][1], PLAYER_RECT[RRUBY][2], PLAYER_RECT[RRUBY][2] * i);

    if (i == 0)
        pos = sfSprite_getPosition(player->sprites[player->direction]->sprite);
    else
        pos = sfSprite_getPosition(player->sprites[RRUBY]->sprite);
    init_ruby(player, rect, ru);
    sfSprite_setPosition(player->sprites[RRUBY]->sprite, pos);
    sfRenderWindow_drawSprite(window, player->sprites[RRUBY]->sprite, NULL);
    if (ru->millisec >= 50) {
        ++i;
        sfClock_restart(ru->clock);
    }
    if (i >= 15) {
        i = 0;
        player->ruby = 0;
    }
}
