/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_put_float.c
*/

#include "printf.h"
#include <stdarg.h>

void intsup0(long *entier, int *nb, double *value, long *decimal)
{
    if (*entier < 0) {
        my_printf("-");
        *entier *= -1;
        *value *= -1;
        *nb += 1;
    }
    *value -= *entier;
    *decimal = *value * 10000000;
}

void decimalinf(long *decimal, double *value, long *entier)
{
    if (*decimal % 10 >= 5) {
        if (*decimal == 9999999) {
            *entier += 1;
            *decimal = 0;
        } else {
            *decimal = *value * 10000000 + 1;
        }
    } else {
        *decimal = *value * 10000000;
    }
    if (*decimal < 0)
        *decimal *= -1;
    *decimal += 1;
}

int my_count_putfloat(va_list ap)
{
    double value = va_arg(ap, double);
    int nb = 7;
    long entier = value;
    long decimal = 0;

    intsup0(&entier, &nb, &value, &decimal);
    decimalinf(&decimal, &value, &entier);
    decimal /= 10;
    my_printf("%d.", entier);
    for (int i = 0; i < 6 - count_nums(decimal); i++)
        my_printf("0");
    my_printf("%d", decimal);
    return count_nums(entier) + nb;
}
