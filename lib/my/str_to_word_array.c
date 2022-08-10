/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** converts a string to word array
*/

#include "main.h"
#include <stdlib.h>

static int it_begins_when(char const *str, int i, int (*sep)(char))
{
    for (; str[i] != '\0'; i++) {
        if (!sep(str[i])) {
            return i;
        }
    }
    return i;
}

static int count_words(char const *scr, int (*sep)(char))
{
    int count = 1;
    int i = it_begins_when(scr, 0, sep);

    for (; scr[i] != '\0'; ++i) {
        if (sep(scr[i])) {
            count++;
            i = it_begins_when(scr, i, sep);
        }
    }
    return count;
}

static int count_char(char const *str, int (*sep)(char))
{
    int count = 0;
    static int index = 0;

    for (int i = index; str[i] != '\0'; ++i) {
        ++index;
        if (sep(str[i])) {
            index = it_begins_when(str, i, sep);
            break;
        }
        ++count;
    }
    return count;
}

//allocates memory for char **str using the funs count_sup AND count_char
static char **make_array(char const *str, int (*sep)(char))
{
    int num_words = count_words(str, sep);
    char **words = (char **) malloc((num_words + 1) * sizeof(char *));

    for (int i = 0; i < num_words; ++i) {
        words[i] = (char *) malloc(count_char(str, sep) + 1);
    }
    words[num_words] = NULL;
    return words;

}

char **split_str(char *scr, int (*sep)(char))
{
    char **words = make_array(scr, sep);
    int i = it_begins_when(scr, 0, sep);
    int t = 0;
    int k = 0;
    int j;

    while (scr[i] != '\0') {
        for (j = i; !sep(scr[j]) && scr[j] != '\0'; ++j) {
            words[t][k] = scr[j];
            ++k;
        }
        words[t][k] = '\0';
        k = 0;
        i = it_begins_when(scr, j, sep);
        ++t;
    }
    words[t] = NULL;
    return words;
}
