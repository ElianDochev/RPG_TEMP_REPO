/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** funtction that allocates memory and copies the string given as argument
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dup = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dup == NULL)
        return NULL;
    my_strcpy(dup, src);
    return dup;
}
