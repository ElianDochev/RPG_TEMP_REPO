/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** count and return the len of the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (str == 0)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}
