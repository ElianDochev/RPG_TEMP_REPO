/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copy n characters from a string to another
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    if (n > my_strlen(src)) {
        dest[n + 1] = '\0';
        while (n >= 0) {
            dest[n] = src[n];
            n = n - 1;
        }
    } else {
        while (a < n) {
            dest[a] = src[a];
            a = a + 1;
        }
    }
    return dest;
}
