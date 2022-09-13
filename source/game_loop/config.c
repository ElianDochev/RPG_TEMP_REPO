/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sets_up_config and deletes it
*/

#include "conf.h"
#include <stdlib.h>
#include <stdio.h>

static int check_line(char *scr)
{
    for (int i = 0; scr[i]; ++i) {
        if (scr[i] >= 'a' && scr[i] <= 'z')
            continue;
        if (scr[i] >= 'A' && scr[i] <= 'Z')
            continue;
        if (scr[i] >= '0' && scr[i] <= '9')
            continue;
        if (scr[i] == '=' || scr[i] == '_')
            continue;
        if (scr[i] == '.' || scr[i] == '/')
            continue;
        return 1;
    }
    return 0;
}

static int check_config(char **word_array)
{
    char tmp[64];

    empty_buffer(tmp, 64);
    for (int i = 0; word_array[i]; ++i)
        if (check_line(word_array[i]))
            return 1;
    for (int i = 0; needed_unsigned[i]; ++i)
        if (str_in_word_arr(tmp, word_array, needed_unsigned[i]))
            return 2;
    empty_buffer(tmp, 64);
    for (int i = 0; needed_paths[i]; ++i)
        if (str_in_word_arr(tmp, word_array, needed_paths[i]))
            return 2;
    return 0;
}

static void init_config(config_t **config, char **word_array)
{
    char buff[64];

    empty_buffer(buff, 64);
    for (int i = 0; i < confs_count; ++i) {
        str_in_word_arr(buff, word_array, needed_unsigned[i]);
        (*config)->confs[i] = str_to_int(buff);
        empty_buffer(buff, 64);
    }
    for (int i = 0; i < path_count; ++i) {
        str_in_word_arr(buff, word_array, needed_paths[i]);
        (*config)->paths[i] = str_dup(buff);
        empty_buffer(buff, 64);
    }
}

static void clean_up(void **buff, void **word_arr)
{
    xfree(buff);
    for (int i = 0; word_arr[i]; ++i)
        xfree((word_arr[i]));
    xfree(word_arr);
}

config_t *set_up_config(void)
{
    config_t *config = malloc(sizeof(config_t));
    char *buff = fopen_file(CONF_PATH, "FATAL: config file missing\n");
    int err = 0;
    char **word_array = NULL;

    if (buff == NULL)
        return NULL;
    word_array = split_str(buff, split_endl);
    if ((err = check_config(word_array))) {
        if (err == 1)
            error(conf_err_msg_one);
        else
            error(conf_err_msg_two);
        return NULL;
    }
    init_config(&config, word_array);
    clean_up((void **) &buff, (void **) &word_array);
    return config;
}
