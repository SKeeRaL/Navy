/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_count_putfalg.c
*/

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int my_countnbr_base(int nbr, int nbr_conv, const char *base)
{
    int div = nbr / my_strlen(base);

    if (nbr < 0) {
        nbr_conv += 1;
        nbr = nbr * - 1;
    }
    if (nbr < my_strlen(base)) {
        nbr_conv += 1;
        return nbr_conv;
    }
    nbr_conv += 1;
    return my_countnbr_base(div, nbr_conv, base);
}

int flagx(va_list ap, int nbr, const char *format)
{
    int value = va_arg(ap, int);
    int nbr_conv = my_countnbr_base(value, 0, "0123456789abcdef");

    format = format;
    if (nbr == 0) {
        my_printf("%x", value);
        return 0;
    }
    if (nbr < 0) {
        my_printf("%x", value);
        for (int i = 0; i < (nbr * -1) - nbr_conv; i++) {
            my_putchar(' ');
        }
    } else {
        for (int i = 0; i < nbr - nbr_conv; i++) {
            my_putchar(' ');
        }
        my_printf("%x", value);
    }
    return 0;
}

int flags(va_list ap, int nbr, const char *format)
{
    char const *value = va_arg(ap, char *);
    int str_len = my_strlen(value);

    format = format;
    if (nbr == 0) {
        my_printf("%s", value);
        return 0;
    }
    if (nbr < 0) {
        my_printf("%s", value);
        for (int i = 0; i < (nbr * -1) - str_len; i++) {
            my_putchar(' ');
        }
    } else {
        for (int i = 0; i < nbr - str_len; i++) {
            my_putchar(' ');
        }
        my_printf("%s", value);
    }
    return 0;
}

int flagc(va_list ap, int nbr, const char *format)
{
    char value = va_arg(ap, int);

    format = format;
    if (nbr == 0) {
        my_printf("%c", value);
        return 0;
    }
    if (nbr < 0) {
        my_printf("%c", value);
        for (int i = 0; i < (nbr * -1) - 1; i++) {
            my_putchar(' ');
        }
    } else {
        for (int i = 0; i < nbr - 1; i++) {
            my_putchar(' ');
        }
        my_printf("%c", value);
    }
    return 0;
}

int flago(va_list ap, int nbr, const char *format)
{
    int value = va_arg(ap, int);
    int nbr_conv = my_countnbr_base(value, 0, "01234567");

    format = format;
    if (nbr == 0) {
        my_printf("%o", value);
        return 0;
    }
    if (nbr < 0) {
        my_printf("%o", value);
        for (int i = 0; i < (nbr * -1) - nbr_conv; i++) {
            my_putchar(' ');
        }
    } else {
        for (int i = 0; i < nbr - nbr_conv; i++) {
            my_putchar(' ');
        }
        my_printf("%o", value);
    }
    return 0;
}
