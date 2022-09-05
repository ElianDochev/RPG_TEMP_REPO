/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file to create_maps
*/

#include "player.h"
#include "map.h"
#include "main.h"
#include "m_my.h"

int select_move(player_t *player, int y)
{
    for (int x = 0; x < MAX_X; x++) {
        if (player->move == 1 && player->direction == 0 &&
        player->map[y][x] == 'B' && player->map[y][x - 1] == ' ') {
            player->map[y][x] = ' ';
            player->map[y][x - 1] = 'B';
            return 1;
        }
        if (player->move == 1 && player->direction == 1 &&
        player->map[y][x] == 'B' && player->map[y][x + 1] == ' ') {
            player->map[y][x] = ' ';
            player->map[y][x + 1] = 'B';
            return 1;
        }
        if (player->move == 1 && player->direction == 2 &&
        player->map[y][x] == 'B' && player->map[y - 1][x] == ' ') {
            player->map[y][x] = ' ';
            player->map[y - 1][x] = 'B';
            return 1;
        }
        if (player->move == 1 && player->direction == 3 &&
        player->map[y][x] == 'B' && player->map[y + 1][x] == ' ') {
            player->map[y][x] = ' ';
            player->map[y + 1][x] = 'B';
            return 1;
        }
    }
    return 0;
}

int move_player(player_t *player, time_mana_t *mo)
{
    mo->time = sfClock_getElapsedTime(mo->clock);
    mo->millisec = sfTime_asMilliseconds(mo->time);
    if (mo->millisec > 100) {
        for (int y = 0; y < MAX_Y; y++) {
            if (select_move(player, y) == 1)
                return 1;
        }
    }
    return 0;
}

void anim_player(player_t *player, int *j)
{
    player->textures[player->direction] = sfTexture_createFromFile(PLAYER_PATHS_NAME[player->direction],
    get_int_rect(PLAYER_RECT[player->direction][0], PLAYER_RECT[player->direction][1], PLAYER_RECT[player->direction][2],
    PLAYER_RECT[player->direction][3] + (PLAYER_RECT[player->direction][2] * *j)));
    player->sprites[player->direction] = set_sprite(player->textures[player->direction], NULL, NULL,
    get_sfvector2f(1.5, 1.5));
    ++*j;
    if (*j >= 8)
        *j = 0;
}

void draw_sprite_player(player_t *player, char c, sfVector2f *pos, sfRenderWindow *window)
{
    if (c == PLAYER_TEXT_CHARS[0]) {
        sfSprite_setPosition(player->sprites[player->direction]->sprite, *pos);
        sfRenderWindow_drawSprite(window, player->sprites[player->direction]->sprite, NULL);
    }
}

void draw_player(sfRenderWindow *window, player_t *player)
{
    sfVector2f pos = create_fvector(0, 0);

    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            draw_sprite_player(player, player->map[y][x], &pos, window);
            pos.x += 64;
        }
        pos.x = 0;
        pos.y += 64;
    }
}
