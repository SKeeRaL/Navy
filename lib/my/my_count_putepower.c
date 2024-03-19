/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_epower.c
*/

#include "printf.h"
#include <stdarg.h>
#include <stdbool.h>

void numbercond(double *number, bool *inf, int *nb, int *count)
{
    if (*number < 0) {
        *number *= -1;
        my_printf("-");
        *nb += 1;
    }
    while (*number < 1) {
        *inf = true;
        *number *= 10;
        *count += 1;
    }
    while (*number >= 10) {
        *number /= 10;
        *count += 1;
    }
}

int my_count_putepower(va_list ap)
{
    double value = va_arg(ap, double);
    int count = 0;
    double number = value;
    bool inf = false;
    int nb = 0;

    numbercond(&number, &inf, &nb, &count);
    my_printf("%f", number);
    if (inf)
        my_printf("e-");
    else {
        my_printf("e+");
    }
    if (count < 10) {
        my_putchar('0');
        my_put_nbr(count);
    } else {
        my_put_nbr(count);
    }
    return 12 + nb;
}

int my_count_putepowermaj(va_list ap)
{
    double value = va_arg(ap, double);
    int count = 0;
    double number = value;
    bool inf = false;
    int nb = 0;

    numbercond(&number, &inf, &nb, &count);
    my_printf("%f", number);
    if (inf)
        my_printf("E-");
    else {
        my_printf("E+");
    }
    if (count < 10) {
        my_putchar('0');
        my_put_nbr(count);
    } else {
        my_put_nbr(count);
    }
    return 12 + nb;
}
