/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_int_to_str.c
*/

#include "printf.h"

char *my_int_to_str(int nb)
{
    char *str = malloc(count_nums(nb) + 1);
    int j = 0;

    for (; j != count_nums(nb); j++)
        str[j] = nb / my_compute_power_rec(10,
        (count_nums(nb) - j - 1)) % 10 + 48;
    str[j] = '\0';
    return str;
}
