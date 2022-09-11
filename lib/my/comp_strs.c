/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** func for comp strings and
*/

#include "utilities.h"

int str_cmp(char const *str_one, char const *str_two)
{
    if (*str_one == '\0' && *str_two == '\0')
        return 0;
    return ((*str_one - *str_two) == 0) ? str_cmp(str_one + 1, str_two + 1) :
    (*str_one - *str_two);
}

int str_ncmp(char const *str_one, char const *str_two, int length)
{
    int res = 0;
    int count = 0;
    int len_s_one = my_strlen(str_one);
    int len_s_two = my_strlen(str_two);

    if ((len_s_one + len_s_two) == 0)
        return 0;
    if (len_s_one == 0)
        return -1;
    if (len_s_two == 0)
        return 1;
    if (length > MIN(len_s_one + 1, len_s_two + 1))
        length = MIN(len_s_one + 1, len_s_two + 1);
    while (res == 0 && count < length) {
        res = *str_one - *str_two;
        ++str_one;
        ++str_two;
        ++count;
    }
    return res;
}

int get_len_two_d(const char **w_arr)
{
    int count = 0;

    while (*w_arr) {
        ++count;
        ++w_arr;
    }
    return count;
}

static void stage_two(char *scr, int length, char *dest)
{
    int lenght_scr = my_strlen(scr);

    for (int i = 0; i + length <= lenght_scr; ++i)
        dest[i] = scr[i + length];
}

int str_in_word_arr(char *dest, char **word_arr, const char *sub_arr)
{
    int length_sub = my_strlen(sub_arr);

    for (int i = 0; word_arr[i]; ++i) {
        if (str_ncmp(word_arr[i], sub_arr, length_sub) == 0) {
            stage_two(word_arr[i], length_sub, dest);
            return 0;
        }
    }
    return 1;
}

