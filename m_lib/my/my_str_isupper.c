/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** function that return 1 or 0 if contain only uppercase alphabetical character
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            i = i + 1;
        } else {
            return 0;
        }
    }
    return 1;
}
