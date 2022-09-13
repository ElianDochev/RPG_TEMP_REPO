/*
** EPITECH PROJECT, 2022
** utility functions
** File description:
** splits a string into an array of strings with one delimiter
*/

#include "main.h"

static int count_sep(char *scr, int len, int (*sep)(char))
{
    int count = 0;

    if (scr == NULL || sep == NULL)
        return -1;
    scr += len;
    for (int i = 0; scr[i]; ++i) {
        if (!sep(scr[i])) {
            break;
        }
        ++count;
    }
    return count;
}

static int count_words(char *scr, int (*sep)(char))
{
    int count = 1;

    if (scr == NULL || sep == NULL)
        return -1;
    for (int i = 0; scr[i] != '\0'; ++i) {
        if (sep(scr[i]) && scr[i + 1] != '\0' && !sep(scr[i + 1])) {
            count++;
        }
    }
    return count;
}

static int count_char(char *str, int (*sep)(char))
{
    int count = 0;

    if (str == NULL || sep == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (sep(str[i])) {
            break;
        }
        ++count;
    }
    return count;
}

static char **alloc_space(char *scr, int (*sep)(char))
{
    int words = count_words(scr, sep);
    printf ("words: %d\n" , words);
    char **arr = scr != NULL ? (char **) malloc((words + 1) * sizeof(char *))
    : NULL;
    int tmp = 0;

    if (arr == NULL)
        return NULL;
    for (int i = 0; i < words; ++i) {
        tmp = count_char(scr, sep);
        arr[i] = (char *) malloc(tmp + 1);
        printf("\nhere \n");
        write(1, scr , tmp);
        printf("\nhere \n");
        scr += count_sep(scr, tmp, sep) + tmp;
        arr[i][tmp] = '\0';
    }
    arr[words] = NULL;
    return arr;
}

char **split_str_single(char *scr, int (*sep)(char))
{
    char **w_arr = alloc_space(scr, sep);
    int row = 0;

    if (w_arr == NULL)
        return NULL;
    remove_sep(&scr, delim_space_tab, 0);
    for (int i = 0; scr[i] != '\0'; ++i) {
        if (sep(scr[i]) && scr[i + 1] != '\0' && !sep(scr[i + 1])) {
            scr += count_char(scr, sep) + 1;
           // printf("in w_arr scr %s\n", w_arr[row]);
            row++;
            i = 0;
        }
        if ((i != 0 && scr[i - 1] == '\0') || scr[i] == '\0')
            break;
        w_arr[row][i] = scr[i];
    }
    return w_arr;
}
