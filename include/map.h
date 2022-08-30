/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "sprites.h"
    #define MAX_Y 10
    #define MAX_X 80
    #define GRASS ' '
    #define GRASS_TEXT 0
    #define TEXTURES_NB 1

typedef struct map
{
    char **map;
    sfTexture **textures;
    sprite_t ***sprites;
} map_t;

map_t *create_map(char *path);

#endif
