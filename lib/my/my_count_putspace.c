/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putspace.c
*/

#include "printf.h"
#include <stddef.h>

crazyprinter_t array9[] = {
    {'c', my_count_putchar},
    {'d', my_count_putnbr},
    {'i', my_count_putnbr},
    {'s', my_count_putstr},
    {'x', my_count_puthexamin},
    {'X', my_count_puthexa},
    {'f', my_count_putfloat},
    {'F', my_count_putfloat},
    {'o', my_count_putoct},
    {'e', my_count_putepower},
    {'E', my_count_putepowermaj},
    {'u', my_count_putu},
    {'p', my_count_putaddress},
    {'g', my_count_shorter},
    {'G', my_count_shortermaj},
    // {'n', stock_count, count_flagn},
    {0, NULL},
};

void spaceneed(int *nbr, int count2, int value)
{
    while (((*nbr) - 1) - count2 != 0) {
        (*nbr) -= 1;
        my_printf(" ");
    }
    my_printf("%d", value);
}

void ifneed(const char *format, va_list ap, int *i, int value)
{
    int nbr = 0;
    int count2 = 0;

    ap = ap;
    if (format[*i + 2] >= '0' && format[*i + 2] <= '9') {
            nbr = format[*i + 2] - '0';
            count2 = count_nums(value);
            if (count2 >= nbr)
                my_printf("%d", value);
            else {
                spaceneed(&nbr, count2, value);
            }
        }
}

void putflagspace(va_list ap, const char *format, int *i, int value)
{
    for (int j = 0; array9[j].c != 0; j++) {
        if (format[*i + 2] == array9[j].c) {
            array9[j].pf(ap);
            *i += 1;
        }
    }
    ifneed(format, ap, i, value);
}

static int scnd_opt(const char *format, int i, va_list ap, int value)
{
    if (format[i] == '%' && format[i + 1] == ' ') {
        my_printf(" ");
        putflagspace(ap, format, &i, value);
        i += 2;
    }
    return i;
}

int my_count_putspace(va_list ap, const char *format)
{
    int i = 0;
    int count = 0;
    int value = va_arg(ap, int);

    if (value < 0) {
        my_printf("%d", value);
        return 0;
    }
    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == ' ' &&
        format[i + 2] == 'd') {
            my_printf(" ");
            my_printf("%d", value);
            break;
        }
        i += scnd_opt(format, i, ap, value);
    }
    return count;
}
