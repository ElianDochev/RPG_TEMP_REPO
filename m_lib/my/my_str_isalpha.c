/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** function that return 1 or 0 if contain only alphabetical character
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            i = i + 1;
        else
            return 0;
    }
    return 1;
}
