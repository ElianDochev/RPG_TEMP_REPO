/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** function that return 1 or 0 if contain only lowercase alphabetical character
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            i = i + 1;
        } else {
            return 0;
        }
    }
    return 1;
}
