/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** opens a file and puts its contents in a buffer
*/

#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

char *fopen_file(char *path, char *err_msg)
{
    FILE *file = fopen(path, "r");
    char *buff = malloc(BUFF_SIZE);

    for (int i = 0; i < BUFF_SIZE; ++i)
        buff[i] = '\0';
    if (file == NULL) {
        error(err_msg);
        xfree((void **) &buff);
        return NULL;
    }
    fread(buff, BUFF_SIZE, sizeof(char), file);
    fclose(file);
    return buff;
}

int delim_space_tab(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}

char *parce(char *scr, char *sub_arr)
{
    int len = my_strlen(sub_arr);

    if (scr == NULL || sub_arr == NULL)
        return NULL;
    remove_sep(&scr, delim_space_tab, 0);
    if (str_ncmp(scr, sub_arr, len) != 0)
        return NULL;
    scr += len;
    remove_sep(&scr, delim_space_tab, 0);
    return scr;
}

int split_backslash(char c)
{
    if (c == '/')
        return 1;
    return 0;
}

int split_endl(char ch)
{
    if (ch == '\n')
        return 1;
    else
        return 0;
}
