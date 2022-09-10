/*
** EPITECH PROJECT, 2022
** move_ennemies.c
** File description:
** functions that moves ennemies for my_rpg
*/

#include "ennemi.h"
#include "player.h"
#include "m_my.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

static coo_t find_coo(char **map, char symbol)
{
    coo_t coo;
    coo.i = -1;
    coo.j = -1;

    for (int i = 0; map[i] != NULL; ++i) {
        for (int j = 0; map[i][j] != '\0'; ++j) {
            if (map[i][j] = symbol) {
                coo.i = i;
                coo.j = j;
            }
        }
    }
    return coo;
}

void move_ennemies(player_t *player, ennemi_t *enemy)
{
    coo_t coo_p = find_coo(player->map, 'B');
    coo_t coo_e = find_coo(player->map, 'E');

    if (abs(coo_p.i - coo_e.i) > 3 || abs(coo_p.j - coo_e.j) > 5)
        return;
    if (abs(coo_p.i - coo_e.i) > abs(coo_p.j - coo_e.j)) {
        if (abs(coo_p.i - (coo_e.i + 1)) < abs(coo_p.i - (coo_e.i)))
            ;//move enemy down
        else
            ;//move enemy up
    } else {
        if (abs(coo_p.j - (coo_e.j + 1)) < abs(coo_p.j - (coo_e.j)))
            ;// move enemy right
        else
            ;//move enemy left
    }
}
