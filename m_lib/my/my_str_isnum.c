/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** function that return 1 or 0 if contain only digits character
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-' || str[i] == '+')
            i = i + 1;
        else
            return 0;
    }
    return 1;
}
