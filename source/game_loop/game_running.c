/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game_running loop
*/

#include "main.h"
#include <stdio.h>

void ennemies(player_t *player, ennemi_t *ennemi, time_mana_t *en)
{
    en->time = sfClock_getElapsedTime(en->clock);
    en->millisec = sfTime_asMilliseconds(en->time);
    if (en->millisec > 400) {
        move_ennemies(player, ennemi);
        sfClock_restart(en->clock);
    }
}

static void start_loop(sfRenderWindow *window, states *game_state,
global_t *global)
{
    sfRenderWindow_clear(window, sfBlack);
    ev_loop_running(window, game_state, global);
    draw_map(window, global->map);
    which_map(global->player, global->map);
}

static void end_loop(global_t *global, sfRenderWindow *window, time_mana_t *en,
time_mana_t *ru)
{
    ennemies(global->player, global->ennemi, en);
    draw_ennemi(window, global);
    player_action(global->player, global->map, global->ennemi);
    if (global->player->ruby == 1)
        anim_ruby(global->player, ru, window);
    sfRenderWindow_display(window);
}

static void manage_clock(global_t *global, time_mana_t *fl, time_mana_t *pl,
time_mana_t *mo)
{
    anim_flowers(global->map, fl);
    if (global->player->move == 1 && global->player->attack != 1)
        anim_player(global->player, pl);
    if (move_player(global->player, mo) == 1)
        sfClock_restart(mo->clock);
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
    sfMusic_play(global->player->music);
    while (sfRenderWindow_isOpen(window) && *game_state == running) {
        start_loop(window, game_state, global);
        manage_clock(global, fl, pl, mo);
        if (global->player->bomb == 1)
            bomb(global->player, bom, window);
        if (global->player->attack == 1 && global->player->move != 1)
            attack_anim(global->player, hit, window);
        else
            draw_player(window, global->player);
        end_loop(global, window, en, ru);
    }
    sfMusic_stop(global->player->music);
}
