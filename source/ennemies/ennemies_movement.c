/*
** EPITECH PROJECT, 2022
** move_ennemies.c
** File description:
** functions that moves ennemies for my_rpg
*/

#include "main.h"
#include "m_my.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

static int is_coo_right(coo_t *coo, char *map, char symbol, int i)
{
    for (int j = 0; map[j] != '\0'; ++j) {
        if (map[j] == symbol) {
            coo->i = i;
            coo->j = j;
            return 1;
        }
    }
    return 0;
}

static coo_t find_coo(char **map, char symbol)
{
    coo_t coo;
    coo.i = -1;
    coo.j = -1;

    for (int i = 0; map[i] != NULL; ++i) {
        if (is_coo_right(&coo, map[i], symbol, i))
            return coo;
    }
    return coo;
}

void change_pos_ennemies(player_t *player, ennemi_t *ennemi,
coo_t coo_e, int direction)
{
    if (direction == EWDOWN) {
        if (player->map[coo_e.i + 1][coo_e.j] == 'B') {
            player->life--;
        } else {
            ennemi->direction = 3;
            player->map[coo_e.i][coo_e.j] = ' ';
            player->map[coo_e.i + 1][coo_e.j] = 'E';
        }
    }
    if (direction == EWUP) {
        if (player->map[coo_e.i - 1][coo_e.j] == 'B') {
            player->life--;
        } else {
            ennemi->direction = 2;
            player->map[coo_e.i][coo_e.j] = ' ';
            player->map[coo_e.i - 1][coo_e.j] = 'E';
        }
    }
}

void change_pos_ennemies_bis(player_t *player, ennemi_t *ennemi,
coo_t coo_e, int direction)
{
    if (direction == EWRIGHT) {
        if (player->map[coo_e.i][coo_e.j + 1] == 'B') {
            player->life--;
        } else {
            ennemi->direction = 1;
            player->map[coo_e.i][coo_e.j] = ' ';
            player->map[coo_e.i][coo_e.j + 1] = 'E';
        }
    }
    if (direction == EWLEFT) {
        if (player->map[coo_e.i][coo_e.j - 1] == 'B') {
            player->life--;
        } else {
            ennemi->direction = 0;
            player->map[coo_e.i][coo_e.j] = ' ';
            player->map[coo_e.i][coo_e.j - 1] = 'E';
        }
    }
}

void move_ennemies(player_t *player, ennemi_t *ennemi)
{
    coo_t coo_p = find_coo(player->map, 'B');
    coo_t coo_e = find_coo(player->map, 'E');

    if (coo_e.i == -1 || coo_e.j == -1)
        return;
    if (abs(coo_p.i - coo_e.i) > 5 || abs(coo_p.j - coo_e.j) > 7)
        return;
    if (abs(coo_p.i - coo_e.i) > abs(coo_p.j - coo_e.j)) {
        if (abs(coo_p.i - (coo_e.i + 1)) < abs(coo_p.i - (coo_e.i)))
            change_pos_ennemies(player, ennemi, coo_e, EWDOWN);
        else
            change_pos_ennemies(player, ennemi, coo_e, EWUP);
    } else {
        if (abs(coo_p.j - (coo_e.j + 1)) < abs(coo_p.j - (coo_e.j)))
            change_pos_ennemies_bis(player, ennemi, coo_e, EWRIGHT);
        else
            change_pos_ennemies_bis(player, ennemi, coo_e, EWLEFT);
    }
}
