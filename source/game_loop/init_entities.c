/*
** EPITECH PROJECT, 2022
** init_entities.c
** File description:
** functions that init_entities for game running loop
*/

#include "main.h"

static void init_text_attack(player_t *p, sfIntRect *rect)
{
    p->textures[p->direction + 4] = sfTexture_createFromFile(
    PLAYER_PATHS_NAME[p->direction + 4], NULL);
    p->sprites[p->direction + 4] = set_sprite(p->textures[p->direction + 4],
    NULL, rect, get_sfvector2f(2, 2));
}

void attack_anim(player_t *p, time_mana_t *hit, sfRenderWindow *w)
{
    static int i = 0;
    sfVector2f pos = sfSprite_getPosition(p->sprites[p->direction]->sprite);
    sfIntRect *rect = get_int_rect(PLAYER_RECT[p->direction + 4][0],
    PLAYER_RECT[p->direction + 4][1], PLAYER_RECT[p->direction + 4][2],
    PLAYER_RECT[p->direction + 4][2] * i);

    hit->time = sfClock_getElapsedTime(hit->clock);
    hit->millisec = sfTime_asMilliseconds(hit->time);
    init_text_attack(p, rect);
    sfSprite_setPosition(p->sprites[p->direction + 4]->sprite, pos);
    sfRenderWindow_drawSprite(w, p->sprites[p->direction + 4]->sprite, NULL);
    if (hit->millisec >= 40) {
        ++i;
        sfClock_restart(hit->clock);
    }
    if (i >= 5) {
        i = 0;
        p->attack = 0;
    }
}

static void init_bomb(player_t *p, sfIntRect *rect, time_mana_t *bom)
{
    bom->time = sfClock_getElapsedTime(bom->clock);
    bom->millisec = sfTime_asMilliseconds(bom->time);
    p->textures[BOMB] = sfTexture_createFromFile(PLAYER_PATHS_NAME[BOMB], NULL);
    p->sprites[BOMB] = set_sprite(p->textures[BOMB], NULL, rect,
    get_sfvector2f(2.5, 2.5));
}

void bomb(player_t *p, time_mana_t *bom, sfRenderWindow *window)
{
    static int i = 0;
    sfVector2f pos;
    sfIntRect *rect = get_int_rect(PLAYER_RECT[BOMB][0], PLAYER_RECT[BOMB][1],
    PLAYER_RECT[BOMB][2], PLAYER_RECT[BOMB][2] * i);

    if (i == 0)
        pos = sfSprite_getPosition(p->sprites[p->direction]->sprite);
    else
        pos = sfSprite_getPosition(p->sprites[BOMB]->sprite);
    init_bomb(p, rect, bom);
    sfSprite_setPosition(p->sprites[BOMB]->sprite, pos);
    sfRenderWindow_drawSprite(window, p->sprites[BOMB]->sprite, NULL);
    if (bom->millisec >= 90) {
        ++i;
        sfClock_restart(bom->clock);
    }
    if (i >= 18) {
        i = 0;
        p->bomb = 0;
    }
}

void destroy_player(player_t *player)
{
    sfMusic_destroy(player->music);
    for (int i = 0; i < MAX_Y; ++i)
        free(player->map[i]);
    for (int i = 0; i < PLAYER_TEXTURE_NB; ++i) {
        free(player->textures[i]);
        free(player->sprites[i]);
    }
}
