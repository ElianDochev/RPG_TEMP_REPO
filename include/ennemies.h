/*
** EPITECH PROJECT, 2022
** ennemies.h
** File description:
** header for ennemies
*/

#include "sprites.h"
#ifndef ENNEMIES
    #define ENNEMIES

typedef struct ennemies_s {
    char **map;
    sfTexture **textures;
    sprite_t **sprites;
    int direction;
    int attack;
    int move;
} ennemies_t;

typedef struct coo_s {
    int i;
    int j;
}coo_t;

#endif /* !ENNEMIES */
