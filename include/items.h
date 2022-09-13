/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** items header file
*/

#ifndef ITEMS_H
    #define ITEMS_H

    #include "conf.h"
    #include "buttons.h"
    #include "sprites.h"

typedef struct items item_t;
    #define ITEM_PATH "items.item"
//types of the structs that are gonna be used in the list
typedef enum {armor, weapon, potion} item_type;
typedef enum {attack_value, defense, health} item_stat;
//loads the items from the file
item_t **load_items(void);
struct items {
    item_type type;
    int amount;
    item_stat stat;
    char *name;
    size_t id;
    sfBool is_active;
};

#endif