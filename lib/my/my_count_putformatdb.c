/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_count_putnum.c
*/

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void put_spaceb(int entier, int value, int nbr_conv, int nb_z)
{
    value = value;
    if (entier > 0) {
        for (int i = 0; i < entier - nbr_conv - nb_z; i++) {
            my_putchar(' ');
        }
    }
}

static void condi938(int nbr, int value, int nbr_conv, int *nb_z)
{
    if (nbr < 0) {
        my_printf("%b", value);
        for (int i = 0; i < (nbr * -1) - nbr_conv; i++) {
            my_putchar('0');
            *nb_z += 1;
        }
    } else {
        for (int i = 0; i < nbr - nbr_conv; i++) {
            my_putchar('0');
            nb_z += 1;
        }
        my_printf("%b", value);
    }
}

int flagb(va_list ap, int nbr, const char *format, int entier)
{
    int value = va_arg(ap, int);
    int nbr_conv = my_countnbr_base(value, 0, "01");
    int nb_z = 0;

    format = format;
    if (nbr == 0) {
        my_printf("%b", value);
        return 0;
    }
    condi938(nbr, value, nbr_conv, &nb_z);
    put_spaceb(entier, value, nbr_conv, nb_z);
    return 0;
}

void put_space(int entier, int value, int nbr_conv)
{
    if (entier < 0) {
        my_printf("%x", value);
        for (int i = 0; i < (entier * -1) - nbr_conv; i++) {
            my_putchar(' ');
        }
    } else {
        for (int i = 0; i < entier - nbr_conv; i++) {
            my_putchar(' ');
        }
        my_printf("%x", value);
    }
}

int flagpointx(va_list ap, int nbr, const char *format, int entier)
{
    int value = va_arg(ap, int);
    int nbr_conv = my_countnbr_base(value, 0, "0123456789abcdef");

    format = format;
    if (nbr > nbr_conv) {
        for (int i = nbr; i >= nbr_conv; i--) {
            my_putchar('0');
            nbr_conv += 1;
        }
    }
    if (entier == 0) {
        my_printf("%x", value);
        return 0;
    }
    put_space(entier, value, nbr_conv);
    return 0;
}

void point0(int *countnum, int nbr, char const *format)
{
    format = format;
    if (nbr > *countnum) {
        for (int i = nbr; i >= *countnum; i--) {
            my_putchar('0');
            *countnum += 1;
        }
    }
}

static int put_spacepos(int entier, int countnum, int value)
{
    for (int i = 0; i < entier - countnum; i++) {
            my_putchar(' ');
        }
        my_printf("%d", value);
    return 0;
}

static void tiens(int entier, int value, int *countnum, bool neg)
{
    if (neg)
        *countnum += 1;
    if (entier < 0) {
        my_printf("%d", value);
        for (int i = 0; i < (entier * -1) - (*countnum); i++)
            my_putchar(' ');
    } else {
        put_spacepos(entier, *countnum, value);
    }
}

int flagpointd(va_list ap, int nbr, const char *format, int entier)
{
    int value = (va_arg(ap, int));
    bool plus = false;
    bool pos = false;
    bool neg = false;
    int countnum = count_nums(value);

    if (value < 0) {
        value = value * -1;
        my_putchar('-');
        neg = true;
    }
    point0(&countnum, nbr, format);
    if (pos && value > 0)
        my_printf("+");
    if (plus || entier == 0) {
        my_printf("%d", value);
        return 0;
    }
    tiens(entier, value, &countnum, neg);
    return 0;
}
