/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** button test .h
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "sprites.h"
    #define MAX_Y 16
    #define MAX_X 30
    #define GROUND ' '
    #define GROUND_TEXT 0
    #define WALL_UP '-'
    #define WALL_LEFT '('
    #define WALL_DOWN '_'
    #define WALL_RIGHT ')'
    #define WALL_NO '/'
    #define WALL_SO 'o'
    #define WALL_SE 'e'
    #define WALL_NE '\\'
    #define WALL_UP_TEXT 1
    #define WALL_LEFT_TEXT 2
    #define WALL_DOWN_TEXT 3
    #define WALL_RIGHT_TEXT 4
    #define WALL_NO_TEXT 5
    #define WALL_SO_TEXT 6
    #define WALL_SE_TEXT 7
    #define WALL_NE_TEXT 8
    #define BUSH 'x'
    #define BUSH_TEXT 9
    #define GRASS 'g'
    #define GRASS_TEXT 10
    #define TEXTURES_NB 11

typedef struct map
{
    char **map;
    sfTexture **textures;
    sprite_t ***sprites;
} map_t;

map_t *create_map(char *path);
void walls_textures_mana(sfTexture **textures);
sprite_t *choose_wall_texture(int y, int x, map_t *map);

#endif
