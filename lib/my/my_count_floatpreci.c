/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_put_float.c
*/

#include "printf.h"
#include <stdarg.h>

int my_count_floatprecision(double value, int lendec, int precision)
{
    int nb = 7;
    long entier = value;
    long decimal = 0;

    intsup0(&entier, &nb, &value, &decimal);
    decimalinf(&decimal, &value, &entier);
    decimal /= 10;
    my_printf("%d.", entier);
    for (int i = 0; i < 6 - count_nums(decimal); i++)
        my_printf("0");
    lendec = count_nums(decimal) - precision;
    if (precision > 6) {
        my_printf("%d", decimal);
        for (int i = 0; i != (precision - 6); i++)
            my_printf("0");
    } else {
        decimal /= my_compute_power_rec(10, lendec);
        my_printf("%d", decimal);
    }
    return count_nums(entier) + nb;
}
