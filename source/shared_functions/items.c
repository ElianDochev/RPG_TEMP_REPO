/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** items init
*/

#include "items.h"
#include "utilities.h"
#include <stdio.h>

static item_type get_type(char *str)
{
    if (str_cmp(str, "armor") == 0)
        return armor;
    if (str_cmp(str, "weapon") == 0)
        return weapon;
    if (str_cmp(str, "potion") == 0)
        return potion;
    return -1;
}

static item_t *get_item_from_str(char *str)
{
    item_t *item = malloc(sizeof(item_t));
    char **splitted = split_str_single(str, split_endl);

    if (splitted == NULL)
        return NULL;
    item->name = my_strdup(parce(splitted[0], "name: "));
    item->type = get_type(parce(splitted[1], "type: "));
    item->stat = my_getnbr(parce(splitted[2], "stat: "));
    item->amount = 0;
    item->is_active = sfFalse;
    item->id = my_getnbr(parce(splitted[3], "id: "));
    for (int i = 0; splitted[i] != NULL; ++i)
        free(splitted[i]);
    free(splitted);
    return item;
}

static item_t **do_it(char **arr)
{
    item_t **items = malloc(sizeof(item_t *) * (get_len_two_d(arr) + 1));

    for (int i = 0; arr[i] != NULL; ++i) {
        items[i] = get_item_from_str(arr[i]);
    }
    items[get_len_two_d(arr)] = NULL;
    return items;
}

item_t **load_items(void)
{
    char *buff = fopen_file(ITEM_PATH, "Items file not found");
    char **items = NULL;
    item_t **item_list = NULL;

    //printf("%s\n" , buff);
    if (buff == NULL)
        return NULL;
    items = split_str_single(buff, split_backslash);
    for (int i = 0; items[i] != NULL; ++i)
        printf("%s\n" , items[i]);
    fflush(stdout);
    if (items == NULL)
        return NULL;
    item_list = do_it(items);
    xfree((void **) &buff);
    for (int i = 0; items[i] != NULL; ++i)
        xfree((void **) &items[i]);
    xfree((void **) &items);
    return item_list;
}