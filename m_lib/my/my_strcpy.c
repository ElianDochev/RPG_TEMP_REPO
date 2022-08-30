/*
** EPITECH PROJECT, 2022
** my_strcpy.C
** File description:
** copy a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int nb = 0;

    while (src[nb] != '\0') {
        dest[nb] = src[nb];
        nb = nb + 1;
    }
    dest[nb] = '\0';
    return (dest);
}
