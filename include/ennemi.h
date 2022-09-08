/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** ennemi.h
*/

#ifndef ENNEMI_H_
    #define ENNEMI_H_

    #include "sprites.h"
    #define MAX_Y 16
    #define MAX_X 30
    #define ENNEMI_TEXTURE_NB 4

enum {EWLEFT, EWRIGHT, EWUP, EWDOWN};
static const char ENNEMI_TEXT_CHARS[] = "E";
static const char *ENNEMI_PATHS_NAME[] = {"resources/ennemi/ennemi_walk_left.png",
"resources/ennemi/ennemi_walk_right.png", "resources/ennemi/ennemi_walk_up.png",
"resources/ennemi/ennemi_walk_down.png"};
static const int ENNEMI_RECT[][5] = {{0, 64, 40, 0}, {0, 64, 40, 0},
{0, 64, 40, 0}, {0, 64, 40, 0}};

typedef struct ennemi {
    sfTexture **textures;
    sprite_t **sprites;
    int direction;
    int move;
} ennemi_t;

#endif
