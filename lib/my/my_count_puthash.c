/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_count_puthash.c
*/

#include <stdio.h>
#include "printf.h"

void verif_case_hash(const char *format, int i, va_list ap)
{
    int nbr = 0;
    int value = 0;

    if (nbr == 0 && format[i] == 'd') {
        value = va_arg(ap, int);
        my_printf("%d", value);
    } else if (nbr == 0 && format[i] == 'x') {
        value = va_arg(ap, int);
        my_putstr("0x");
        my_printf("%x", value);
    }
    if (nbr == 0 && format[i] == 'o') {
        value = va_arg(ap, int);
        my_putchar('0');
        my_printf("%o", value);
    }
}

int my_count_puthash(va_list ap, const char *format)
{
    int a = 0;
    int i = 0;

    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == '#') {
            i += 2;
            break;
        }
    }
    verif_case_hash(format, i, ap);
    return a;
}
