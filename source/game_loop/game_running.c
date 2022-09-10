/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

void attack(player_t *p, time_mana_t *hit, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos = sfSprite_getPosition(p->sprites[p->direction]->sprite);
    sfIntRect *rect = get_int_rect(PLAYER_RECT[p->direction + 4][0],
    PLAYER_RECT[p->direction + 4][1], PLAYER_RECT[p->direction + 4][2],
    PLAYER_RECT[p->direction + 4][2] * i);

    hit->time = sfClock_getElapsedTime(hit->clock);
    hit->millisec = sfTime_asMilliseconds(hit->time);
    p->textures[p->direction + 4] = sfTexture_createFromFile(
    PLAYER_PATHS_NAME[p->direction + 4], NULL);
    p->sprites[p->direction + 4] = set_sprite(p->textures[p->direction + 4],
    NULL, rect, get_sfvector2f(2, 2));
    sfSprite_setPosition(p->sprites[p->direction + 4]->sprite, pos);
    sfRenderWindow_drawSprite(window, p->sprites[p->direction + 4]->sprite,
    NULL);
    if (hit->millisec >= 40) {
        ++i;
        sfClock_restart(hit->clock);
    }
    if (i >= 5) {
        i = 0;
        p->attack = 0;
    }
}

void bomb(player_t *player, time_mana_t *bom, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos;
    sfIntRect *rect = get_int_rect(PLAYER_RECT[BOMB][0], PLAYER_RECT[BOMB][1],
    PLAYER_RECT[BOMB][2], PLAYER_RECT[BOMB][2] * i);

    if (i == 0)
        pos = sfSprite_getPosition(player->sprites[player->direction]->sprite);
    else
        pos = sfSprite_getPosition(player->sprites[BOMB]->sprite);
    bom->time = sfClock_getElapsedTime(bom->clock);
    bom->millisec = sfTime_asMilliseconds(bom->time);
    player->textures[BOMB] = sfTexture_createFromFile(PLAYER_PATHS_NAME[BOMB],
    NULL);
    player->sprites[BOMB] = set_sprite(player->textures[BOMB],
    NULL, rect, get_sfvector2f(2.5, 2.5));
    sfSprite_setPosition(player->sprites[BOMB]->sprite, pos);
    sfRenderWindow_drawSprite(window, player->sprites[BOMB]->sprite, NULL);
    if (bom->millisec >= 90) {
        ++i;
        sfClock_restart(bom->clock);
    }
    if (i >= 18) {
        i = 0;
        player->bomb = 0;
    }
}

void game_running(sfRenderWindow *window, states *game_state,
global_t *global, config_t *conf)
{
    time_mana_t *fl = get_clock();
    time_mana_t *pl = get_clock();
    time_mana_t *mo = get_clock();
    time_mana_t *hit = get_clock();
    time_mana_t *bom = get_clock();
    time_mana_t *ru = get_clock();
    time_mana_t *en = get_clock();

    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        sfRenderWindow_clear(window, sfBlack);
        en->time = sfClock_getElapsedTime(en->clock);
        en->millisec = sfTime_asMilliseconds(en->time);
        ev_loop_running(window, game_state, global);
        which_map(global->player, global->map);
        draw_map(window, global->map);
        anim_flowers(global->map, fl);
        if (global->player->move == 1 && global->player->attack != 1)
            anim_player(global->player, pl);
        if (global->player->bomb == 1)
            bomb(global->player, bom, window);
        if (move_player(global->player, mo) == 1)
            sfClock_restart(mo->clock);
        if (global->player->attack == 1 && global->player->move != 1)
            attack(global->player, hit, window);
        else
            draw_player(window, global->player);
        if (en->millisec > 400) {
            move_ennemies(global->player, global->ennemi);
            sfClock_restart(en->clock);
        }
        draw_ennemi(window, global);
        player_action(global->player, global->map);
        if (global->player->ruby == 1)
            anim_ruby(global->player, ru, window);
        sfRenderWindow_display(window);
    }
}
