/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** items header file
*/

#ifndef ITEMS_H
    #define ITEMS_H

    #include "main.h"
    #include "buttons.h"
    #include "sprites.h"

typedef struct item item_t;

//types of the structs that are gonna be used in the list
typedef enum {armor, weapon, potion} item_type;
typedef enum {attack, defense, health} item_stat;

struct items {
    item_type type;
    int amount;
    item_stat stat;
    char *name;
    sfBool is_active;
};

#endif