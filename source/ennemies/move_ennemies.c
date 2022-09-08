/*
** EPITECH PROJECT, 2022
** move_ennemies.c
** File description:
** functions that moves ennemies for my_rpg
*/

#include "ennemies.h"
#include "player.h"
#include "m_my.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

coo_t find_coo(player_t *entity, char symbol)
{
    coo_t coo;
    coo.i = -1;
    coo.j = -1;

    for (int i = 0; entity->map[i] != NULL; ++i) {
        for (int j = 0; entity->map[i][j] != '\0'; ++j) {
            if (entity->map[i][j] = symbol) {
                coo.i = i;
                coo.j = j;
            }
        }
    }
    return coo;
}

void move_ennemies(player_t *player, player_t *enemy)
{
    coo_t coo_player = find_coo(player, "B");
    coo_t coo_enemy = find_coo(enemy, "E");

    if (abs(coo_player.i - coo_enemy.i) > 3 || abs(coo_player.j - coo_enemy.j) > 5)
        return;
    if (abs(coo_player.i - coo_enemy.i) > abs(coo_player.j - coo_enemy.j)) {
        if (abs(coo_player.i - (coo_enemy.i + 1)) < abs(coo_player.i - (coo_enemy.i)))
            //move enemy down
            return;
        else
            //move enemy up
            return;
    } else {
        if (abs(coo_player.j - (coo_enemy.j + 1)) < abs(coo_player.j - (coo_enemy.j)))
            // move enemy right
            return;
        else
            //move enemy left
            return;
    }
}
