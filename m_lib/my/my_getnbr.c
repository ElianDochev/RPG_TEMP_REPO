/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** function that return a number from a string
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int neg = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            neg = neg * -1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
        } else {
            return (nbr * neg);
        }
    }
    return (nbr * neg);
}
